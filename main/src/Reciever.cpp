#include "Reciever.hpp"

#include <iostream>
#include <fstream>
#include <unistd.h>

TReciever::TReciever()
{
    this->context = zmq::context_t();
    this->socket = zmq::socket_t(this->context, ZMQ_REQ);
    this->socket.connect("tcp://localhost:4040");
}

void TReciever::RequestUpdate()
{
    int pid = fork();

    if (!pid){
        execl("./server.py", "server.py");
    }

    zmq::message_t request, response;

    zmq::send_result_t requestStatus = this->socket.send(request, zmq::send_flags::none);
    zmq::recv_result_t responseStatus = this->socket.recv(response, zmq::recv_flags::none);
 
    if (!responseStatus.has_value())
    {
        std::cerr << "Invalid response from server.\n";
        exit(EXIT_FAILURE);
    }   

    int numOfLines = std::atoi(response.to_string().data());
    requestStatus = this->socket.send(request, zmq::send_flags::none);
    
    responseStatus = this->socket.recv(response, zmq::recv_flags::none);
    
    if (!responseStatus.has_value())
    {
        std::cerr << "Invalid response from server.\n";
        exit(EXIT_FAILURE);
    }

    int numOfColumns = std::atoi(response.to_string().data());
    requestStatus = this->socket.send(request, zmq::send_flags::none);

    this->table.resize(numOfLines);

    for (int i = 0; i < numOfLines; ++i)
    {
        this->table[i].resize(numOfColumns + 1);

        std::string name;

        for (int j = 0; j < numOfColumns; ++j)
        {
            responseStatus = this->socket.recv(response, zmq::recv_flags::none);

            if (j == 0){
                name = response.to_string();
            }

            QString elem = response.to_string().data();
            this->table[i][j + 1] = elem;

            requestStatus = this->socket.send(request, zmq::send_flags::none);
        }        
   }

    if (!responseStatus.has_value())
    {
        std::cerr << "Invalid response from server.\n";
        exit(EXIT_FAILURE);
    }

    responseStatus = this->socket.recv(request, zmq::recv_flags::none);
}

TReciever::~TReciever()
{
    this->socket.close();
    this->context.close();
}

