from cs50 import get_float

coinCount = 0
money = 0
while money <= 0:
    money = get_float("Change owed: ")

moneyRounded = round(money * 100)

while moneyRounded > 0:
    if moneyRounded - 25 >= 0:
        coinCount += 1
        moneyRounded -= 25
    elif moneyRounded - 10 >= 0:
        coinCount += 1
        moneyRounded -= 10
    elif moneyRounded - 5 >= 0:
        coinCount += 1
        moneyRounded -= 5
    elif moneyRounded - 1 >= 0:
        coinCount += 1
        moneyRounded -= 1
print("Coins:", coinCount)