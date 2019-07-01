

// Qt
#include <QApplication>

// Own
#include <MainWindow.hpp>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow mw;
    mw.showMaximized();

    return app.exec();
}
