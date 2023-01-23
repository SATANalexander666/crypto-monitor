#include "ToolBar.hpp"

TToolBar::TToolBar(QWidget* parent)
{
    QPixmap searchPix("/home/axr/.cryptomonitor/resources/search.png");
    QPixmap trashPix("/home/axr/.cryptomonitor/resources/trash.png");

    this->setOrientation(Qt::Vertical);
    this->setStyleSheet(
        "border: 0px; \
        background-image: url(/home/axr/.cryptomonitor/resources/main_old1.jpg)"
    );

    this->addAction(QIcon(searchPix), "Find");
    this->addSeparator();
    this->addAction(QIcon(trashPix), "Trash");
}

