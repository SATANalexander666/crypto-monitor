#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.setWindowState(Qt::WindowMaximized);
    window.setWindowTitle("CryptoMonitor");

    window.show();

    return app.exec();
}

