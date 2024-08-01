import os

from datetime import datetime
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    userID = session["user_id"]
    stonks = db.execute("select symbol, shares, before, price from stonks where id = ? order by time desc limit 2", session["user_id"])
    cash = db.execute("select cash from users where id = ?", session["user_id"])
    total = cash[0]["cash"]
    try:
        for i in range(len(stonks)):
            total = total + float(stonks[i]["price"])
    except:
        total = cash[0]["cash"]
    return render_template("portfolio.html", stonks=stonks, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        try:
            num = int(request.form.get("shares"))
        except:
            return apology("Enter a number", 400)
        stock = lookup(symbol)
        if not stock:
            return apology("Enter a valid symbol", 400)
        if not num or num <= 0:
            return apology("Enter a valid number of shares", 400)
        symbol = stock["symbol"]
        price = stock["price"]
        cost = price * int(num)
        cash = db.execute("select cash from users where id = ?", session["user_id"])
        now = datetime.now()
        if cost > float(cash[0]["cash"]):
            return apology("You do not have enough cash!")
        else:
            cash[0]["cash"] = cash[0]["cash"] - cost
            db.execute("update users set cash = ? where id = ?", cash[0]["cash"], session["user_id"])

        cost = "{:6.2f}".format(cost)
        price = "{:6.2f}".format(price)
        db.execute("insert into stonks (id, symbol, price, shares, before, time) values(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, cost, num, price, datetime.fromtimestamp(datetime.timestamp(now)))
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    userID = session["user_id"]
    stonks = db.execute("select symbol, shares, before, price from stonks where id = ? order by time desc", session["user_id"])
    cash = db.execute("select cash from users where id = ?", session["user_id"])
    #total = cash["cash"] +
    return render_template("history.html", stonks=stonks, cash=cash, )


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        LUS = lookup(symbol)
        if not LUS:
            return apology("Invalid Symbol", 400)
        name = LUS["name"]
        price = LUS["price"]
        symbol = LUS["symbol"]
        return render_template("quoted.html", name=name, price=price, symbol=symbol)
    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        others = db.execute("select username from users")
        for i in range(len(others)):
            if username == others[i]["username"]:
                return apology("That username is taken.", 400)
        if not username:
            return apology("Please enter a valid username.", 400)
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not password:
            return apology("Please enter a password.", 400)
        if password != confirmation:
            return apology("Please confirm your password.", 400)

        db.execute("insert into users (username, hash) values(?, ?)", username, generate_password_hash(password))
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        try:
            num = int(request.form.get("shares"))
        except:
            return apology("Enter a valid number", 400)
        stock = lookup(symbol)
        if not stock:
            return apology("Enter a valid symbol", 400)
        if not num or num <= 0:
            return apology("Enter a valid number of shares", 400)
        symbol = stock["symbol"]
        price = stock["price"]
        cost = price * int(num)
        cash = db.execute("select cash from users where id = ?", session["user_id"])
        stocks = db.execute("select shares from stonks where id = ? and symbol = ?", session["user_id"], symbol)
        ownedShares = 0
        if not stocks:
            return apology("You don't have any of this stock?")
        try:
            for i in range(len(stocks)):
                ownedShares = ownedShares + stocks[i]["shares"]
        except:
            return apology("Enter a valid request", 400)
        now = datetime.now()
        if num > ownedShares:
            return apology("You do not have enough stocks!", 400)
        else:
            cash[0]["cash"] = float(cash[0]["cash"]) + cost
            db.execute("update users set cash = ? where id = ?", cash[0]["cash"], session["user_id"])

        cost = "{:20,.2f}".format(cost)
        price = "{:20,.2f}".format(price)
        db.execute("insert into stonks (id, symbol, price, shares, before, time) values(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, cost, num, price, datetime.fromtimestamp(datetime.timestamp(now)))
        return redirect("/")
    else:
        symbols = db.execute("select distinct symbol from stonks where id = ?", session["user_id"])
        return render_template("sell.html", symbols=symbols)



def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
