#ifndef RECIEVER_HPP
#define RECIEVER_HPP

#include <QString>
#include <QVector>
#include <zmq.hpp>

class TReciever
{
    public:
        TReciever();
        void Update();
        ~TReciever();
    private:
        zmq::context_t context;
        zmq::socket_t socket;

    protected:
        QVector< QVector<QString> > table;
    
};

#endif

