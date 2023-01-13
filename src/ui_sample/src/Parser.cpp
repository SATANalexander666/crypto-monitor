#include "Parser.hpp"

#include <iostream>

TParser::TParser(){}

void TParser::Parse()
{
    this->Listen();

    std::string name;
    std::string price;

    for (std::string &line : this->originalData)
    {
        std::istringstream strm(line);

        std::getline(strm, name, ' ');
        std::getline(strm, price, ' ');

        if (name.length() && price.length()){
            parsedData.push(std::make_pair(name, price));
        }
    }
}

