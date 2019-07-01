

// Own
#include <GLWidget.hpp>

// Qt
#include <QPainter>
#include <QTimerEvent>

#define UPDATE_TIME                 100

GLWidget::GLWidget(QWidget * pParent):
    QOpenGLWidget(pParent)
{
    _oPaintHelper.readParticlesFromImage("image.jpg", 40);
    _iTimerId = startTimer(UPDATE_TIME);
}

void GLWidget::paintEvent(QPaintEvent* pEvent)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    _oPaintHelper.paint(&painter, pEvent);
    painter.end();
}

void GLWidget::timerEvent(QTimerEvent* pEvent)
{
    if (_iTimerId == pEvent->timerId())
    {
        killTimer(pEvent->timerId());

        update();
        _iTimerId = startTimer(UPDATE_TIME);
    }
}
