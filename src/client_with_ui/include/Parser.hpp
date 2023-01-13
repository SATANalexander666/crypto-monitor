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

    protected:
        std::queue< std::pair<std::string, std::string> > data;

    private:
};

#endif

