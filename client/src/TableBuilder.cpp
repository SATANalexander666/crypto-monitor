#include "TableBuilder.hpp"

TTableBuilder::TTableBuilder(QWidget *parent)
{
    this->Update();

    this->setRowCount(this->table.size());
    this->setColumnCount(this->table[0].size() + 1);

    QStringList headers;
    headers << " " << "Name" << "Price (USDT)" << "Change (USDT)" << "Change %" << "Volume" << "Quantity";
    this->setHorizontalHeaderLabels(headers);

    QHeaderView *headerView = this->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    this->setColumnWidth(0, 1);
    
    for (int i = 0; i < this->table.size(); ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg("Mark"));
        item->setCheckState(Qt::Unchecked);
        this->setItem(i, 0, item);

        if (i % 2){
            item->setBackground(QBrush(QColor(48, 25, 52)));
        }
        else {
            item->setBackground(QBrush(QColor(72, 50, 72)));
        }

        for (int j = 0; j < this->table[0].size(); ++j)
        {
            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(table[i][j]));
            this->setItem(i, j + 1, item);

            if (i % 2){
                item->setBackground(QBrush(QColor(48, 25, 52)));
            }
            else {
                item->setBackground(QBrush(QColor(72, 50, 72)));
            }
        }
    }
}

