import sys
from pyfiglet import Figlet
figlet = Figlet()
import random

args = sys.argv[1:]
if(len(args) == 0):
    figlet.setFont(font=random.choice(figlet.getFonts()))
else:
    try:
        if(args[0] != "-f" and args[0] != "--font"):
            sys.exit("please use -f or --font")
    except:
        sys.exit("enter first parameter")
    try:
        figlet.setFont(font=args[1])
    except:
        sys.exit("invalid font")

inp = input("Input: ")
print("Output: \n" + figlet.renderText(inp))

