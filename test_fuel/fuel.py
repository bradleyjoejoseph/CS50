
def main():
    while True:
        inp = input("enter Fraction: ")
        try:
            print(gauge(convert(inp)))
        except ValueError:
            pass
        except ZeroDivisionError:
            pass
        else:
            break
def convert(fraction):
    fraction = fraction.split("/")
    if (int(fraction[0]) != float(fraction[0]) or int(fraction[1]) != float(fraction[1])):
        raise ValueError
    if (int(fraction[0]) < 0 or int(fraction[1]) < 0):
        raise ValueError
    if (int(fraction[1]) == 0):
        raise ZeroDivisionError
    result = int(round((float(fraction[0]) / float(fraction[1]))*100))
    if (result > 100):
        raise ValueError
    return result

def gauge(percentage):
    if (percentage >= 99):
        return "F"
    elif (percentage <= 1):
        return "E"
    else:
        return str(percentage) + "%"


if __name__ == "__main__":
    main()
