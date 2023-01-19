import zmq

if __name__ == "__main__":
    
    context = zmq.Context()
    socket = context.socket(zmq.PAIR)
    socket.bind("tcp://*:5050")

    with open("../resources/data/BTC.png", "rb") as file:
        img = file.read()

    socket.send(img)

