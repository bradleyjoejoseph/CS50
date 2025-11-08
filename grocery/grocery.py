items = {}
while True:
    try:
        inp = input("").upper()
    except EOFError:
        break;
    else:
        if (inp in items):
            items.update({inp: (items[inp]+1)})
        else:
            items.update({inp: 1})
print()
for x, y in sorted(items.items()):
        print(y, x)
