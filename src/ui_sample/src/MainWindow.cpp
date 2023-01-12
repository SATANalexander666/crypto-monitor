#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QToolBar* b = new QToolBar();
    b->setWindowTitle("OTHER");
    b->setOrientation(Qt::Vertical);
    b->addAction(QIcon(), "TEST");
    addToolBar(Qt::LeftToolBarArea, b);
}

MainWindow::~MainWindow()
{
    
}
