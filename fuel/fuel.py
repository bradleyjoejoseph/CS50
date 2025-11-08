while True:
    inp = input("enter Fraction:").split("/")
    try:
        if (int(inp[0]) != float(inp[0]) or int(inp[1]) != float(inp[1])):
            raise ValueError
        if (int(inp[1]) == 0):
            raise ZeroDivisionError
        result = int(round((float(inp[0]) / float(inp[1]))*100))
        if (result > 100):
            raise ValueError
    except ValueError:
        pass
    except ZeroDivisionError:
        pass
    else:
        if (result >= 99):
            print("F")
        elif (result <= 1):
            print("E")
        else:
            print(f"{result}%")
        break
