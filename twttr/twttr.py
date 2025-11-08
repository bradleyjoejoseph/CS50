vowels = ["a", "e", "o", "i", "u"]
capVs = []

for i in range(len(vowels)):
    capVs.append(vowels[i].upper())

inp = input("Input: ")
for i in range(len(vowels)):
    inp = inp.replace(vowels[i], "")
    inp = inp.replace(capVs[i], "")
print(f"Output: {inp}")
