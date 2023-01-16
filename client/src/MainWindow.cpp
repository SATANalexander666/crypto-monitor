#include "MainWindow.hpp"

#include "TableLinker.hpp"
#include "ListModel.hpp"

#include <iostream>
#include <unistd.h>

#include <QStringList>
#include <QAbstractItemModel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QPixmap mainPix("/home/axr/.cryptomonitor/resources/main.jpg");
    
    QPalette palette;
    palette.setBrush(QPalette::Window, mainPix);
    //this->setPalette(palette);

    


    toolBar = new QToolBar;

    QPixmap searchPix("/home/axr/.cryptomonitor/resources/search.png");
    QPixmap trashPix("/home/axr/.cryptomonitor/resources/trash.png");

    toolBar->setOrientation(Qt::Vertical);
    toolBar->setStyleSheet(
        "border: 0px; \
        background-image: url(/home/axr/.cryptomonitor/resources/main.jpg)"
    );

    toolBar->addAction(QIcon(searchPix), "Find");
    toolBar->addSeparator();
    toolBar->addAction(QIcon(trashPix), "Trash");

    addToolBar(Qt::LeftToolBarArea, toolBar);




    QTableView *tableView = new QTableView;
    TTableLinker *tableModel = new TTableLinker;
    
    QPalette tablePalette = tableView->palette();
    tablePalette.setBrush(QPalette::Highlight,QBrush(Qt::white));
    tablePalette.setBrush(QPalette::HighlightedText,QBrush(Qt::black));
    
    tableView->setStyleSheet(
        "background-image: url(/home/axr/.cryptomonitor/resources/main.jpg)"
    );
    
    tableView->setModel(tableModel);
    tableView->resizeColumnsToContents();   
    tableView->resizeRowsToContents();
    
    setCentralWidget(tableView);



    /*QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel *model = new StringListModel(numbers);
    QListView *view = new QListView;

    view->setWindowTitle("View onto a string list model");

    view->setModel(model);

    model->insertRows(5, 7, QModelIndex());

    for (int row = 5; row < 12; ++row) 
    {
        QModelIndex index = model->index(row, 0, QModelIndex());
        model->setData(index, QString::number(row+1));
    }

    setCentralWidget(view);*/
}

MainWindow::~MainWindow(){
     
}

