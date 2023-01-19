#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include "Reciever.hpp"

class TDataManager : protected TReciever
{
    public:
        TDataManager();

    protected:
        void SendUpdate();
};

#endif

