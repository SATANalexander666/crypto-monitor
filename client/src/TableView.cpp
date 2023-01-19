#include "TableView.hpp"

#include <QHeaderView>
#include <QModelIndex>

#include <iostream>

TTableView::TTableView(QWidget *parent)
{
    this->tableLinker = new TTableLinker(parent);

    this->setModel(this->tableLinker);

    for (int i = 1; i < this->tableLinker->numOfColumns(); ++i){
        this->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    this->setColumnWidth(0, 20);
    this->setFont(QFont("Times", 16));

    this->setStyleSheet(
        "background-image: url(/home/axr/.cryptomonitor/resources/main.jpg)"
    );
}

TTableView::~TTableView(){
    delete this->tableLinker;
}

