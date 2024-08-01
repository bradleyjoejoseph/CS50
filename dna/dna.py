import sys
import csv


def main():
    argc = len(sys.argv)
    if argc != 3:
        print("ERROR 001")
        sys.exit(1)

    csvFileOpen = open(sys.argv[1], "r")
    csvFile = csv.reader(csvFileOpen, delimiter=',')
    lineCount = 0
    theListForBiggest = []
    theListForSTR = []
    csvTable = list(csvFile)
    topLine = csvTable[0]

    dnaFileOpen = open(sys.argv[2], "r")
    dnaFile = dnaFileOpen.read()
    dnaFileSaved = dnaFile
    for j in range(1, len(topLine)):
        checkSTR = topLine[j]
        checkSTRLen = len(checkSTR)
        while True:
            firstFound = dnaFile.find(checkSTR)
            if firstFound == -1:
                break
            x = 0
            y = 1
            numOfStr = 0
            while True:
                if dnaFile[firstFound + (checkSTRLen * x):firstFound + (checkSTRLen * y)] == checkSTR:
                    x += 1
                    y += 1
                    numOfStr += 1
                else:
                    theListForBiggest.append(numOfStr)
                    dnaFile = dnaFile[firstFound + (checkSTRLen * x):]
                    break
        dnaFile = dnaFileSaved
        try:
            daBiggestNumInDaBiggestList = max(theListForBiggest)
        except:
            print("No match")
        theListForSTR.append(str(daBiggestNumInDaBiggestList))
        theListForBiggest.clear()

    csvLenned = len(csvTable)

    for q in range(1, csvLenned):
        notfound = True
        while notfound:
            if csvTable[q][1:] == theListForSTR:
                print(csvTable[q][0])
                notfound = False
                sys.exit(0)
            else:
                break
    if notfound == True:
        print("No match")


main()
