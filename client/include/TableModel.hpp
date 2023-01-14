#ifndef TABLE_MODEL_HPP
#define TABLE_MODEL_HPP

#include <DataManager.hpp>

#include <QAbstractTableModel>

class TTableModel : public QAbstractTableModel
{
    public:
        TTableModel();
        ~TTableModel();

    protected:
        virtual int rowCount(const QModelIndex &parent);
        virtual int columnCount(const QModelIndex &parent);
        virtual QVariant data(const QModelIndex &index, int role);
        virtual QVariant headerData(int section, Qt::Orientation orientation, int role);

};

#endif

