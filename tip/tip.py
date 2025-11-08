meal = input("How much was the meal? ")
tip = input("What percentage would you like to tip? ")

print(f"Leave ${float(meal.replace(meal[0], ""))*float(tip.replace(tip[-1], ""))/100:.2f}")
