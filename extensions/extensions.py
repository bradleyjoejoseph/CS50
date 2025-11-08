imgSuffix = ["gif",
          "jpg",
          "jpeg",
          "png"

]
appSuffix = ["pdf",
          "PDF",
          "txt",
          "zip"
]
inp = input("File name: ")
inpsuf = inp.rstrip().split(".")
if (inpsuf[-1] in imgSuffix):
    if (inpsuf[-1] == "jpg"):
        print("image/jpeg")
    else:
        print(f"image/{inpsuf[-1]}")
elif (inpsuf[-1] in appSuffix):
    if (inpsuf[-1] == "txt"):
        print(f"text/{inpsuf[0]}")
    elif (inpsuf[-1] == "PDF"):
        print("application/pdf")
    else:
        print(f"application/{inpsuf[-1]}")
else:
    print("application/octet-stream")
