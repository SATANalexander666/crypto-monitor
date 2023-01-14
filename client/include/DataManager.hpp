#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include "Parser.hpp"

#include <QVector>

class TDataManager : protected TParser
{
    public:
        TDataManager();

    protected:
        void SendUpdate();
};

#endif

