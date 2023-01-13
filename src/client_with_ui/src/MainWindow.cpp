#include "MainWindow.hpp"

#include "DataManager.hpp"

#include <iostream>
#include <unistd.h>

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
        "border: 0px"
    );

    toolBar->addAction(QIcon(searchPix), "Find");
    toolBar->addSeparator();
    toolBar->addAction(QIcon(trashPix), "Trash");

    addToolBar(Qt::LeftToolBarArea, toolBar);




    TDataManager manager;
    manager.Update();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    int idx = 0;

    while (!manager.empty())
    {
        ++idx;

        std::pair<std::string, std::string> item = manager.Get();

        QHBoxLayout *line = new QHBoxLayout;
        
        QCheckBox *checkBox = new QCheckBox;
        QLabel *index = new QLabel(std::to_string(idx).data());
        QLabel *name = new QLabel(item.first.data());
        QLabel *price = new QLabel(item.second.data());

        line->addWidget(checkBox);
        line->addWidget(index);
        line->addWidget(name);
        line->addWidget(price);

        mainLayout->addLayout(line);
    }

    QWidget *window = new QWidget();
    window->setLayout(mainLayout);

    setCentralWidget(window);
}

MainWindow::~MainWindow(){
     
}

