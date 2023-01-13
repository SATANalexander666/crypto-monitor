#ifndef PARSER_HPP
#define PARSER_HPP

#include "Reciever.hpp"

#include <string>
#include <queue>
#include <sstream>


class TParser : private TReciever
{
    public:
        TParser();
        void Parse();
        std::pair<std::string, std::string> Get();

    protected:
        std::queue< std::pair<std::string, std::string> > parsedData;

    private:
};

#endif

