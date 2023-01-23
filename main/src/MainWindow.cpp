#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->toolBar = new TToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);

    this->tableView = new TTableView(this); 
    setCentralWidget(tableView);
}

MainWindow::~MainWindow()
{
    delete this->toolBar;
    delete this->tableView;
}

