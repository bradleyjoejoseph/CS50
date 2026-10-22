inp = input("Greeting: ")


if (inp[0].lower() == "h" and "hello" not in inp.lower()):
    print("$20")
elif (inp[0].lower() != "h" and "hello" not in inp.lower()):
    print("$100")
else:
    print("$0")
