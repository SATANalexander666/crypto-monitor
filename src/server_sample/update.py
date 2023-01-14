import requests

def update(link: str):
    
    data = requests.get(link)
    data = data.json()

    print(len(data))

    for pair in data:
        pair_str = pair["symbol"]

        if pair_str.count("USDT") == 0:
            data.remove(pair)
            
    print(len(data))

link = "https://api.binance.com/api/v3/ticker/price?"

if __name__ == "__main__":
    update(link)
    
