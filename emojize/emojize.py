import emoji
inp = input("Input: ")
print(f"Output: {emoji.emojize(inp, language='alias')}") # got the lang thing from the documentation as it said its changed after some update and you need to explicity enable the lanugage
