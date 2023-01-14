#ifndef READER_HPP
#define READER_HPP

#include <fstream>
#include <string>
#include <vector>

class Reader
{
    public:
        Reader(std::string &path);
    private:
        ;
    protected:
        std::vector<std::string> originalData;

};

#endif

