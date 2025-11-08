inp = input("camelCase: ")
i = 0
while i < len(inp):
    if (inp[i].isupper()):
        inp = inp[:i] + "_" + inp[i:]
        i += 1
    i += 1
print(f"snake_case: {inp.lower()}")

