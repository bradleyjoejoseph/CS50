menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

total = 0.0
while True:
    try:
        inp = input("Item: ").title()
        if inp == "":
            break;
    except EOFError:
        break;
    else:
        try:
            total += menu[inp]
        except KeyError:
            pass

        else:
            print("Total: $" + format(total, '.2f'))



