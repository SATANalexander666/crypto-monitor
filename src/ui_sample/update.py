import requests
import json


def update(link: str):

    data = requests.get(link).json()
    result = []

    for pair in data:

        pair_name = pair["symbol"]
        pair_price = pair["price"]

        if pair_name.count("USDT"):

            result.append(
                f'{pair_name.replace("USDT", "")} {pair_price}'
            )

    return result


if __name__ == "__main__":

    link = "https://api.binance.com/api/v3/ticker/price?"
    data = update(link)

    with open("data.txt", "w") as file:
        for line in data:
            file.write(f'{line}\n')





