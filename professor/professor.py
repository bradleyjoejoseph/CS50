import random


def main():
    level = get_level()
    score = 0
    for i in range(10):
        num1 = generate_integer(level)
        num2 = generate_integer(level)
        result = num1 + num2
        for i in range(3):
            inp = input(f"{num1} + {num2} = ")

            try:
                if (int(inp) == result):
                    score += 1
                    break
            except:
                pass
            print("EEE")
            if (i == 2):
                print(f"{num1} + {num2} = {result}")
    print(f"Score: {score}")


def get_level():
    while True:
        try:
            inp = int(input("Level: "))
            if (inp in [1, 2, 3]):
                return inp
            else:
                raise ValueError
        except ValueError:
            pass


def generate_integer(level):
    if (level == 1):
        return random.randint(0, 9)
    end = int("9" * level)
    start = end - int("8" + ("9" * (level-1)))
    return random.randint(start, end)

if __name__ == "__main__":
    main()
