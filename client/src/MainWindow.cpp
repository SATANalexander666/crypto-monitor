#include "MainWindow.hpp"

#include "TableBuilder.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QPixmap mainPix("/home/axr/.cryptomonitor/resources/main.jpg");
    
    QPalette palette;
    palette.setBrush(QPalette::Window, mainPix);

    


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




    TTableBuilder *table = new TTableBuilder(this);
    
    table->setStyleSheet(
        "background-image: url(/home/axr/.cryptomonitor/resources/main.jpg)"
    ); 

    setCentralWidget(table);
}

MainWindow::~MainWindow(){
     
}

