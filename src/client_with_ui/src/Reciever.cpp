#include "Reciever.hpp"

#include <iostream>
#include <unistd.h>

TReciever::TReciever()
{
    this->context = zmq::context_t();
    this->socket = zmq::socket_t(this->context, ZMQ_PAIR);
    this->socket.connect("tcp://localhost:4040");
}

void TReciever::Update()
{
    int pid = fork();

    if (!pid){
        execl("./Updater", "Updater", NULL);
    }

    zmq::message_t message;
    zmq::recv_result_t messageStatus = this->socket.recv(message, zmq::recv_flags::none);
    
    int num = std::atoi(message.to_string().data());
    this->originalData = std::vector<std::string>(num, std::string());

    for (int i = 0; i < num; ++i)
    {
        zmq::message_t msg;
        zmq::recv_result_t msgStatus = this->socket.recv(msg, zmq::recv_flags::none);
        
        this->originalData[i] = (msg.to_string());
    }
}

TReciever::~TReciever()
{
    this->socket.close();
    this->context.close();
}

