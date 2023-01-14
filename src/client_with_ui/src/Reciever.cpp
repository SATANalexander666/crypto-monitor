#include "Reciever.hpp"

#include <iostream>

TReciever::TReciever()
{
    this->context = zmq::context_t();
    this->socket = zmq::socket_t(this->context, ZMQ_REQ);
    this->socket.connect("tcp://localhost:4040");
}

void TReciever::Update()
{
    zmq::message_t request, response;

    zmq::send_result_t requestStatus = this->socket.send(request, zmq::send_flags::none);
    zmq::recv_result_t responseStatus = this->socket.recv(response, zmq::recv_flags::none);
    
    int num = std::atoi(response.to_string().data());
    this->originalData = std::vector<std::string>(num, std::string());

    for (int i = 0; i < num; ++i)
    {
        responseStatus = this->socket.recv(response, zmq::recv_flags::none);
        requestStatus = this->socket.send(request, zmq::send_flags::none);

        this->originalData[i] = (response.to_string());
    }
}

TReciever::~TReciever()
{
    this->socket.close();
    this->context.close();
}

