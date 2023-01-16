import requests
from bs4 import BeautifulSoup

if __name__ == "__main__":

    link = "https://cryptorank.io/ru/all-coins-list"
    response = requests.get(link).text
    soup = BeautifulSoup(response, "lxml")
    
    check_link: str = "https://api.binance.com/api/v3/ticker/24hr"

    table = soup.find("tbody")
    tr = table.find_all("tr")

    for line in tr:
        td = line.find_all("td")

        image_link = td[2].find("img").get("src")
        #image_response = requests.get(image_link).content
        image_name = td[2].find("span", {"class" : "table-coin-link__Symbol-sc-pprt06-1 jJpBXz"}).text

        #with open(f'data/{image_name}.png', "wb") as file:
        #    file.write(image_response)

        if requests.get(f'{check_link}?symbol={image_name.strip()}USDT').json().get("code") == None:
            with open(f'config.txt', "a") as file:
                file.write(f'{image_name}\n')
        
