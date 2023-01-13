#ifndef TOOL_BAR_HPP
#define TOOL_BAR_HPP

#include <QToolBar>
#include <QMainWindow>
#include <qtmetamacros.h>
#include <qtoolbar.h>

class TToolBar : public QToolBar
{
    Q_OBJECT;

    public:
        QToolBar* toolBar;
        TToolBar();
        ~TToolBar();

    private:

};

#endif

