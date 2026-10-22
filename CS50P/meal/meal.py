def main():
    inp = input("What time is it? ")
    t = convert(inp)
    if(t <= 8 and t >= 7):
        print("breakfast time")
    elif(t <= 13 and t >= 12):
        print("lunch time")
    elif(t <= 19 and t >= 18):
        print("dinner time")

def convert(time):
    time = time.split(":")
    return(float(time[0]) + (float(time[1]) / 60))





if __name__ == "__main__":
    main()
