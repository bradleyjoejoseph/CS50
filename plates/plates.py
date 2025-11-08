def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if (len(s) > 6 or len(s) < 2):
        return False
    if (s[0].isnumeric() or s[1].isnumeric()):
        return False


    numbersOnlyNow = False
    for i in range(len(s)):
        if (numbersOnlyNow and not (s[i].isnumeric())):
            return False
        if (s[i].isnumeric()):
            if (not numbersOnlyNow and s[i] == "0"):
                return False
            numbersOnlyNow = True

    return True
main()
