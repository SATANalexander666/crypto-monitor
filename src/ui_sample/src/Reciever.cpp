#include <zmq.hpp>
#include <iostream>
#include <string>

#include <fstream>

void GetMessage()
{
    zmq::context_t context;
    zmq::socket_t socket(context, ZMQ_PAIR);
    socket.connect("tcp://localhost:4040");

    while (true)
    {
        zmq::message_t msg;
        zmq::recv_result_t msgStatus = socket.recv(msg, zmq::recv_flags::none);
        std::string response = msg.to_string();
        
        std::cout << response << '\n';

        if (!response.compare("END_OF_MESSAGES")){
            break;
        }
    }
}

