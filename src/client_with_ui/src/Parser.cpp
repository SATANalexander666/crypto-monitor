#include "Parser.hpp"

#include <iostream>

TParser::TParser(){}

void TParser::Parse()
{
    this->Update();

    std::string name;
    std::string price;
    this->table.resize(this->originalData.size());

    for (int i = 0; i < (int)this->originalData.size(); ++i)
    {
        std::istringstream strm(originalData[i]);

        std::getline(strm, name, ' ');
        std::getline(strm, price, ' ');

        QString QName = name.data();
        QString QPrice = price.data();

        if (name.length() && price.length())
        {
            this->table[i].append(QName);
            this->table[i].append(QPrice);
        }
    }
}

