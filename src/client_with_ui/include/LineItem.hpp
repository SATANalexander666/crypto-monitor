#ifndef LINE_ITEM_HPP
#define LINE_ITEM_HPP

#include <QtWidgets>
#include <QList>

class TLineItem
{
    public:
        QLabel *idLabel;
        QLabel *nameLabel;
        QLabel *priceLabel;

        QHBoxLayout *layout;

        TLineItem(QWidget *parent, const char* id, const char* name, const char* price)
        {
            this->idLabel = new QLabel(id);
            this->nameLabel = new QLabel(name);
            this->priceLabel = new QLabel(price);

            this->layout = new QHBoxLayout(parent);

            this->layout->addWidget(idLabel);
            this->layout->addWidget(nameLabel);
            this->layout->addWidget(priceLabel);
        }
        
        ~TLineItem()
        {
            delete this->idLabel;
            delete this->nameLabel;
            delete this->priceLabel;
            delete this->layout;
        }

    private:
};

#endif

