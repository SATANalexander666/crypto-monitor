#include "Reader.hpp"

#include <iostream>

Reader::Reader(std::string &path)
{
    std::ifstream fin(path);
    std::string tmp;

    while (fin)
    {
        std::getline(fin, tmp);
        originalData.push_back(tmp);
    }

    fin.close();    
}
