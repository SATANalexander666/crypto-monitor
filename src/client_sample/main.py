import socket

def main():
    sock = socket.socket()

    sock.connect(("localhost", 4040))
    sock.sendall("habr".encode("utf-8"))

    data = sock.recv(1024)
    print(f'[client] {data.decode("utf-8")}')

    sock.close()

if __name__ == "__main__":
    main()

