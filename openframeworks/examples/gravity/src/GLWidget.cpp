

// Own
#include <GLWidget.hpp>

// Qt
#include <QPainter>

GLWidget::GLWidget(QWidget * pParent):
    QOpenGLWidget(pParent)
{
    _iElapsed = 0;

    startTimer(50);
}

void GLWidget::paintEvent(QPaintEvent* pEvent)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    _oPaintHelper.paint(&painter, pEvent, _iElapsed);
    painter.end();
}

void GLWidget::timerEvent(QTimerEvent* pEvent)
{
    _iElapsed = (_iElapsed + 50) % 1000;
    update();
}
