
# anouncing all of the variables
text = str(input("Text: "))
words = text.split()
wordCount = len(words)
textLen = len(text)
letterCount = 0
sentenceCount = 0

# finding how many of them are actually letters and the number of sentences
i = 0
while i < textLen:
    if text[i].isalpha() == True:
        letterCount += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentenceCount += 1
    i += 1

L = (letterCount / wordCount) * 100
S = (sentenceCount / wordCount) * 100

CLI = round(0.0588 * L - 0.296 * S - 15.8)
if CLI > 16:
    print("Grade 16+")
elif CLI < 1:
    print("Before Grade 1")
else:
    print("Grade: ", CLI)