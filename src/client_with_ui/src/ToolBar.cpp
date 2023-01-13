#include <ToolBar.hpp>
#include <qmainwindow.h>
#include <qtoolbar.h>

#include <iostream>

TToolBar::TToolBar()
{
    toolBar = new QToolBar;

    QPixmap searchPix("/home/axr/.cryptomonitor/resources/search.png");
    QPixmap trashPix("/home/axr/.cryptomonitor/resources/trash.png");

    toolBar->setOrientation(Qt::Vertical);
    toolBar->setStyleSheet(
        "border: 0px"
    );

    toolBar->addAction(QIcon(searchPix), "Find");
    toolBar->addAction(QIcon(trashPix), "Trash");
}

TToolBar::~TToolBar(){
    delete toolBar;
}

