#include "TableLinker.hpp"

#include <iostream>

TTableLinker::TTableLinker(){
    this->SendUpdate();
}

void TTableLinker::Renew(){
    this->SendUpdate();
}

int TTableLinker::rowCount(const QModelIndex &parent) const{
    return this->table.length();
}

int TTableLinker::columnCount(const QModelIndex &parent) const
{
    return this->table[0].length();
}

QVariant TTableLinker::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) 
    {
        QString answer = this->table[index.row()][index.column()];
        
        return QVariant(answer);
    }

    return QVariant();
}

QVariant TTableLinker::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section)
        {   
            case 0:
                return QVariant("Name");
            case 1:
                return QVariant("Price");
            default:
                return QVariant();
        }
    }
    else {
        return QVariant();
    }		
}

