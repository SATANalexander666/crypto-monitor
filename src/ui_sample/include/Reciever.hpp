#ifndef RECIEVER_HPP
#define RECIEVER_HPP

#include <string>
#include <vector>
#include <zmq.hpp>

class TReciever
{
    public:
        TReciever(std::string &path);
        void Listen();
        ~TReciever();
    private:
        std::string path;
        zmq::context_t context;
        zmq::socket_t socket;

    protected:
        std::vector<std::string> originalData;
    
};

#endif

