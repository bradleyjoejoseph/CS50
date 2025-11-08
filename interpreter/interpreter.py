inp = input("Enter expression: ")
inp = inp.split(" ")
num1 = inp[0]
num2 = inp[2]
operator = inp[1]
match operator:
    case "+":
        print(float(num1) + float(num2))
    case "-":
        print(float(num1) - float(num2))
    case "*":
        print(float(num1) * float(num2))
    case "/":
        print(float(num1) / float(num2))
