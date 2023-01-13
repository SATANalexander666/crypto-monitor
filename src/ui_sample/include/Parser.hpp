#ifndef PARSER_HPP
#define PARSER_HPP

#include "Reader.hpp"

#include <string>
#include <queue>
#include <sstream>


class Parser : protected Reader
{
    public:
        Parser(std::string &path);
        std::pair<std::string, std::string> Get();

    private:
        std::queue< std::pair<std::string, std::string> > parsedData;
};

#endif

