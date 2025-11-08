import inflect
p = inflect.engine()

names = []

while True:
    try:
        inp = (input("Name: "))
        names.append(inp)
    except EOFError:
        print()
        break
print(f"Adieu, adieu, to {p.join(names)}")
