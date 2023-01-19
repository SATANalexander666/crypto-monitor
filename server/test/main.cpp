#include <zmq.hpp>
#include <fstream>
#include <iostream>

int main()
{
    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::pair);
    socket.connect("tcp://localhost:5050");

    zmq::message_t message;
    auto a = socket.recv(message, zmq::recv_flags::none);

    std::fstream fout("test.png", std::ios::out | std::ios::binary);
    fout << message.to_string() << '\n';

    return 0;
}

