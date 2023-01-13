#include "MainWindow.hpp"
//#include "LineItem.hpp"
//#include "ToolBar.hpp"
#include "Parser.hpp"


#include <iostream>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QPixmap mainPix("/home/axr/.cryptomonitor/resources/main.jpg");
    
    QPalette palette;
    palette.setBrush(QPalette::Window, mainPix);
    this->setPalette(palette);

    
    
    toolBar = new QToolBar;

    QPixmap searchPix("/home/axr/.cryptomonitor/resources/search.png");
    QPixmap trashPix("/home/axr/.cryptomonitor/resources/trash.png");

    toolBar->setOrientation(Qt::Vertical);
    toolBar->setStyleSheet(
        "border: 0px"
    );

    toolBar->addAction(QIcon(searchPix), "Find");
    toolBar->addSeparator();
    toolBar->addAction(QIcon(trashPix), "Trash");

    addToolBar(Qt::LeftToolBarArea, toolBar);

    std::string path = "data.txt";
    Parser parser(path);

    

    //TLineItem item(this, "1", "SOL", "2500.7");
    //this->layout()->addWidget(item.layout); 
}

MainWindow::~MainWindow(){
     
}

