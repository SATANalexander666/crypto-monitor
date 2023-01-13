#include "Parser.hpp"

#include <iostream>

TParser::TParser(){}

void TParser::Parse()
{
    this->Update();

    std::string name;
    std::string price;
    this->data = std::queue< std::pair<std::string, std::string> >();

    for (int i = 0; i < (int)this->originalData.size(); ++i)
    {
        std::istringstream strm(originalData[i]);

        std::getline(strm, name, ' ');
        std::getline(strm, price, ' ');

        if (name.length() && price.length()){
            this->data.push(std::make_pair(name, price));
        }
    }
}

