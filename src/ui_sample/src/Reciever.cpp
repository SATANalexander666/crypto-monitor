#include "Reciever.hpp"

#include <iostream>
#include <unistd.h>

TReciever::TReciever(std::string &path)
{
    this->context = zmq::context_t();
    this->socket = zmq::socket_t(this->context, ZMQ_PAIR);
    this->socket.connect("tcp://localhost:4040");

    int pid = fork();

    if (!pid){
        system("python3 /pysrc/");
    }
    
    while (true)
    {
        zmq::message_t msg;
        zmq::recv_result_t msgStatus = socket.recv(msg, zmq::recv_flags::none);
        
        this->originalData.push_back(msg.to_string());
 
        if (!msg.to_string().compare("END_OF_INPUT")){
            break;
        }       
    }

    std::cout << this->originalData.size() << '\n';
}

TReciever::~TReciever()
{

}

