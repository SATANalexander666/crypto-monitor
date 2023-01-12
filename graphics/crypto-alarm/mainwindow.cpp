#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar toolBar;
    //toolBar.setOrientation(Qt::Vertical);

    auto b = new  QToolBar();
    b->setWindowTitle("OTHER");
    b->setOrientation(Qt::Vertical);
    b->addAction(QIcon(), "TEST");
    addToolBar(Qt::LeftToolBarArea, b);
}

MainWindow::~MainWindow()
{
    delete ui;
}
