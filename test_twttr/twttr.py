
vowels = ["a", "e", "o", "i", "u"]
capVs = []

for i in range(len(vowels)):
    capVs.append(vowels[i].upper())

def main():
    inp = shorten(input("Input: "))
    print(f"Output: {inp}")


def shorten(inp):
    for i in range(len(vowels)):
        inp = inp.replace(vowels[i], "")
        inp = inp.replace(capVs[i], "")
    return inp


if __name__ == "__main__":
    main()
