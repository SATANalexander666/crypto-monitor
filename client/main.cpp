#include "MainWindow.hpp"

#include <QApplication>

#include "DataManager.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.resize(600, 900);
    window.setWindowTitle("CryptoMonitor");

    window.show();

    return app.exec();

    return 0;
}

