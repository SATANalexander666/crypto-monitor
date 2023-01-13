import socket

def main():

    sock = socket.socket()
    sock.bind(("localhost", 4040))
    
    sock.listen()
    conn, address = sock.accept()

    while True:

        data = conn.recv(1024)

        if not data:
            break

        conn.sendall(data)
        print(f"[server] {data.decode('utf-8')}")

    conn.close()

if __name__ == "__main__":
    main()

