from cs50 import get_int

height = 0
tag = "#"
tagsGonnaAdd = "#"
mx = 9
mn = 0

while mx <= height or mn >= height:
    height = get_int("Height: \n")

for iteration in range(height):
    print(" " * (height - 1 - iteration), end="")
    print("#" * (iteration + 1), end="  ")
    print("#" * (iteration + 1), end="\n")