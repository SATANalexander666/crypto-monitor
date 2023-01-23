#ifndef TABLE_VIEW_HPP
#define TABLE_VIEW_HPP

#include "TableLinker.hpp"

#include <QTableView>

class TTableView : public QTableView
{
    public:
        TTableView(QWidget *parent);
        ~TTableView();

    private:
        TTableLinker *tableLinker;
};

#endif

