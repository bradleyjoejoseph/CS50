import sys

count = 0

if (len(sys.argv) > 2):
    print("Too many cl args")
    sys.exit()
elif (len(sys.argv) < 2):
    print("Too few cl args")
    sys.exit()


try:
    f = open(sys.argv[1], "r")
except FileNotFoundError:
    print("File not found")
    sys.exit()


for x in f:
    count += 1
    if (x.strip() == ""):
        count -= 1

print(count)
