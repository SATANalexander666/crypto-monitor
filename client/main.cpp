#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.resize(670, 960);
    window.setWindowTitle("CryptoMonitor");

    window.show();

    return app.exec();
}

