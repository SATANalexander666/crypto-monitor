#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.resize(1600, 900);
    window.setWindowTitle("CryptoMonitor");

    window.show();

    return app.exec();
}

