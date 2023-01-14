import requests
import zmq


class WSender:
    def __init__(self, port: str) -> None:
        print(f'[server] connecting to port - {port}')
        self.address = f"tcp://*:{port}"

    def __enter__(self):
        class Sender:
            def __init__(self, address: str) -> None:

                address = address
                self.context = zmq.Context()
                self.socket = self.context.socket(zmq.REP)

                self.socket.bind(address)

            def send(self, message: str) -> None:
                self.socket.send(message.encode("UTF-8"))

            def recieve(self) -> str:
                return self.socket.recv().decode()

        self.object = Sender(self.address)
        return self.object

    def __exit__(self, exc_type, exc_value, traceback) -> None:
        self.object.socket.close()
        self.object.context.destroy()

        if any([exc_type, exc_value, traceback]):
            print(exc_type, exc_value, traceback)


class WUpdater:
    def __init__(self, link) -> None:
        self.link = link

    def __enter__(self):
        class Updater:
            def __init__(self, link: str) -> None:
                self.link = link

            def update(self) -> list[str]:

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
        if any([exc_type, exc_value, traceback]):
            print(exc_type, exc_value, traceback)


def main():

    port: str = "4040"
    link: str = "https://api.binance.com/api/v3/ticker/price?"

    with WSender(port) as sender:
        while True:

            request = sender.recieve()

            print("[server] Got request.")

            with WUpdater(link) as updater:
                container = updater.update()

            sender.send(str(len(container)))

            for elem in container:

                request = sender.recieve()
                sender.send(elem)

            request = sender.recieve()
            sender.send("0")
                
main()