inp = input("What is the Answer to the Great Question of Life, the Universe, and Everything?")

try:
    inp = int(inp)
except:
    if ((inp.lower().replace(" ", "").replace("-", "")) == "fortytwo"):
        print("Yes")
    else:
        print("No")
else:
    if (inp == 42):
        print("Yes")
    else:
        print("No")
