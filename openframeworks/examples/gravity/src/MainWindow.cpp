

// Own
#include <MainWindow.hpp>
#include <GLWidget.hpp>

// Qt
#include <QBoxLayout>

MainWindow::MainWindow(QWidget * pParent):
    QMainWindow(pParent)
{
    QWidget * pCentralWidget = new QWidget(this);
    {
        QBoxLayout * pLayout = new QBoxLayout(QBoxLayout::TopToBottom, pCentralWidget);

        GLWidget * pParentGLWidget = new GLWidget(pCentralWidget);

        pLayout->addWidget(pParentGLWidget);
    }

    setCentralWidget(pCentralWidget);
}
