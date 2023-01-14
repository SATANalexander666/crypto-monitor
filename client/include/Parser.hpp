#ifndef PARSER_HPP
#define PARSER_HPP

#include "Reciever.hpp"

#include <QVector>
#include <QString>
#include <sstream>


class TParser : private TReciever
{
    public:
        TParser();
        void Parse();

    protected:
        QVector< QVector<QString> > table;

    private:
};

#endif

