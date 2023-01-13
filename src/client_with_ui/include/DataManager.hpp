#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include "Parser.hpp"

class TDataManager : private TParser
{
    public:
        TDataManager();
        void Update();

        bool empty();
        std::pair<std::string, std::string> Get();
     
};

#endif

