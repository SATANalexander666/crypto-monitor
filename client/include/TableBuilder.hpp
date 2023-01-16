#ifndef TABLE_BUILDER_HPP
#define TABLE_BUILDER_HPP

#include "DataManager.hpp"

#include <QTableWidget>
#include <QHeaderView>

class TTableBuilder : public QTableWidget, private TDataManager
{
    public:
        TTableBuilder(QWidget *parent);
        
};

#endif
