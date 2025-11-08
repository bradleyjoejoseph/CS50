due = 50
coins = [5, 10, 25]

while True:
    print(f"Amount due: {due}")
    inp = int(input("Insert Amount: "))
    if (inp in coins):
        due -= inp
    if (due <= 0):
        print(f"Change Owed: {-due}")
        break
