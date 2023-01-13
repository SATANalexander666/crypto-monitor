#ifndef PARSER_HPP
#define PARSER_HPP

#include "Reciever.hpp"

#include <string>
#include <queue>
#include <sstream>


class TParser : protected TReciever
{
    public:
        TParser(std::string &path);
        std::pair<std::string, std::string> Get();

    private:
        std::queue< std::pair<std::string, std::string> > parsedData;
};

#endif

