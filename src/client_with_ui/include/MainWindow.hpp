#ifndef MAIN_WINDOW_HPP
#define MAIN WINDOW_HPP

#include <QtWidgets>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT;

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow(); 

    private slots:
        ;

    private:
        QToolBar *toolBar;
};

#endif

