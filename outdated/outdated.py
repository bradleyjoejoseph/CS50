months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
year = 0
day = 0
month = 0
while True:
    try:
        inp = input("Date: ").strip()
    except EOFError:
        break
    else:
        splitted = inp.split("/")
        if(len(splitted) == 1):
            if("," in splitted[0]):
                try:
                    splitted = inp.split(" ")
                    year = int(splitted[2])
                    month = months.index(splitted[0]) + 1
                    day = int(splitted[1].replace(",",""))

                    if(day <= 31 and month <= 12):
                        break
                except ValueError:
                    pass

        else:
            try:
                year = int(splitted[2])
                month = int(splitted[0])
                day = int(splitted[1])
                if(month <= 12 and day <= 31):
                    break
            except ValueError:
                pass
print(f"{year}-{month:02}-{day:02}")
