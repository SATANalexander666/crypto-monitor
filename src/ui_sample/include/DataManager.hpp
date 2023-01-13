#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include "Parser.hpp"

class TDataManager : protected TParser
{
    public:
        //TDataManager();
        void Update();

    private:
        TParser parser;
};

#endif

