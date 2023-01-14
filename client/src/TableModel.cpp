#include "TableModel.hpp"

TTableModel::TTableModel(){}

TTableModel::~TTableModel(){}

int TTableModel::rowCount(const QModelIndex &parent){
    return 0;
}

int TTableModel::columnCount(const QModelIndex &parent){
    return 0;
}

QVariant TTableModel::data(const QModelIndex &index, int role){
    return QVariant();
}

QVariant TTableModel::headerData(int section, Qt::Orientation orientation, int role){
    return QVariant();
}

