#ifndef TABLE_LINKER_HPP
#define TABLE_LINKER_HPP

#include "TableModel.hpp"
#include "DataManager.hpp"

class TTableLinker : public TTableModel, private TDataManager
{
    public:
        TTableLinker();
        void Renew();

    private:
        using TTableModel::rowCount;
        using TTableModel::columnCount;
        using TTableModel::data;
        using TTableModel::headerData;

        int rowCount(const QModelIndex &parent) const override;
        int columnCount(const QModelIndex &parent) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif
