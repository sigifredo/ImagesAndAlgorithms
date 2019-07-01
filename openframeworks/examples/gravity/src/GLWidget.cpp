

// Own
#include <GLWidget.hpp>
#include <PaintGravityHelper.hpp>

// Qt
#include <QPainter>
#include <QTimerEvent>

#define UPDATE_TIME                 100

GLWidget::GLWidget(QWidget * pParent):
    QOpenGLWidget(pParent)
{
    PaintGravityHelper * pPaintGravityHelper = new PaintGravityHelper();

    pPaintGravityHelper->readParticlesFromImage("image.jpg", 40);
    _pPaintHelper = pPaintGravityHelper;

    _iTimerId = startTimer(UPDATE_TIME);
}

void GLWidget::paintEvent(QPaintEvent* pEvent)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    _pPaintHelper->paint(&painter, pEvent);
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
