#ifndef RECIEVER_HPP
#define RECIEVER_HPP

#include <string>
#include <vector>
#include <zmq.hpp>

class TReciever
{
    public:
        TReciever();
        void Listen();
        ~TReciever();
    private:
        zmq::context_t context;
        zmq::socket_t socket;

    protected:
        std::vector<std::string> originalData;
    
};

#endif

