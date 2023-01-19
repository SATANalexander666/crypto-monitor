#include "TableLinker.hpp"

#include <iostream>
#include <QColor>
#include <QPixmap>
#include <string>

int TTableLinker::numOfColumns(){
    return this->table[0].size();
}

TTableLinker::TTableLinker(QWidget *parent){
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
    if (role == Qt::BackgroundRole) 
    {
        return QVariant();

        if (index.column() == 0)
        {
            return QVariant();
        }
        else
        {
            if (index.row() % 2 == 0){           
               return QVariant(QColor(48, 25, 52));
            }
            else {
                return QVariant(QColor(72, 50, 72));
            }
        }
    }

    if (role == Qt::DisplayRole) 
    {    
        QString answer = this->table[index.row()][index.column()];

        return QVariant(answer);
    }

    if (index.column() == 0 && role == Qt::DecorationRole)
    {
        std::string path = "/home/axr/prog/projects/crypto-monitor/client/resources/" \
            + this->table[index.row()][1].toStdString() \
            + ".png";

        QPixmap answer = QPixmap::fromImage(QImage(path.data()));

        return QVariant(answer.scaled(20, 20));
    }

    if (role == Qt::TextAlignmentRole){
        return Qt::AlignCenter;
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
                return QVariant("Logo");
            case 1:
                return QVariant("Name");
            case 2:
                return QVariant("Price (USDT)");
            case 3:
                return QVariant("Change (USDT)");
            case 4:
                return QVariant("Change (%)");
            case 5:
                return QVariant("Volume");
            case 6:
                return QVariant("Quantity");
            default:
                return QVariant();
        }
    }
    else if (orientation == Qt::Vertical) {
        return QVariant();
    }
    else {
        return QVariant();
    }		
}

