import sys
import requests
#my keey d80241a8abdfcd80dfc40bda6940dcd866a2e970199f3171a058e0ddb06683e1


def main():
    try:
        r = requests.get('https://rest.coincap.io/v3/assets/bitcoin?apiKey=d80241a8abdfcd80dfc40bda6940dcd866a2e970199f3171a058e0ddb06683e1')
        amount = float(r.json()["data"]["priceUsd"]) * float(sys.argv[1])
        print(f"${amount:,.4f}")
    except requests.RequestException:
       print("request error try again")
    except TypeErrorbitc:
       print("put in a number")
if __name__ == '__main__':
  main()
