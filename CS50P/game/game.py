import random
level = 0
guess = 0
while True:
    try:
        level = int(input("Level: "))
        break
    except:
        pass
num = random.randint(1, level)
while (guess != num):
    try:
        guess = int(input("Guess: "))
    except:
        pass
    else:
        if (guess == num):
            print("Just right!")
            break
        elif (guess < 1):
            pass
        elif (guess < num):
            print("Too small!")
        elif (guess > level or guess > num):
            print("Too large!")
