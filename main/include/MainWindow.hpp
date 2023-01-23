#ifndef MAIN_WINDOW_HPP
#define MAIN WINDOW_HPP

#include "ToolBar.hpp"
#include "TableView.hpp"


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
        TToolBar *toolBar;
        TTableView *tableView;
};

#endif

