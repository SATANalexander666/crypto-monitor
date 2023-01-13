import requests
import zmq


class WSender:
    def __init__(self, port: str) -> None:
        self.address = f"tcp://*{port}"

    def __enter__(self) -> None:
        class Sender:
            def __init__(self, address) -> None:

                self.address = address
                self.context = zmq.Context()
                self.socket = self.context.socket(zmq.PAIR)

                self.socket.bind(self.address)

        def send(self, message):
            self.socket.send(message.encode("utf-8"))

    def __exit__(self, exc_type, exc_value, traceback) -> None:
        print(exc_type, exc_value, traceback)


class WUpdater:
    def __init__(self, link) -> None:
        self.link = link

    def __enter__(self):
        class Updater:
            def __init__(self, link: str) -> None:
                self.link = link

            def update(self):

                data = requests.get(self.link).json()
                result = []

                for pair in data:

                    pair_name = pair["symbol"]
                    pair_price = pair["price"]

                    if pair_name.count("USDT"):

                        result.append(f'{pair_name.replace("USDT", "")} {pair_price}')

                return result

        self.object = Updater(self.link)

        return self.object

    def __exit__(self, exc_type, exc_value, traceback):
        print(exc_type, exc_value, traceback)


if __name__ == "__main__":

    port: str = "4040"
    link = "https://api.binance.com/api/v3/ticker/price?"

    with WUpdater(port) as updater:
        updater.update()

