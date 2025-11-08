
def main():
    inp = input("Greeting: ")
    print(f"${greeting(inp)}")

def value(greeting):
    if (greeting[0].lower() == "h" and "hello" not in greeting.lower()):
        return 20
    elif (greeting[0].lower() != "h" and "hello" not in greeting.lower()):
        return 100
    else:
        return 0


if __name__ == "__main__":
    main()




