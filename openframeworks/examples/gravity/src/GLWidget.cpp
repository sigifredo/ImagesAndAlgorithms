

// Own
#include <GLWidget.hpp>
#include <PaintGravityHelper.hpp>
#include <PaintImageHelper.hpp>

// Qt
#include <QPainter>
#include <QTimerEvent>

#define UPDATE_TIME                 100

GLWidget::GLWidget(QWidget * pParent):
    QOpenGLWidget(pParent)
{
    /*
    PaintGravityHelper * pPaintGravityHelper = new PaintGravityHelper(this);

    pPaintGravityHelper->readParticlesFromImage("image.jpg", 40);
    _pPaintHelper = pPaintGravityHelper;
    */
    PaintImageHelper * pPaintImageHelper = new PaintImageHelper(this);

    pPaintImageHelper->readImage("image.jpg");
    _pPaintHelper = pPaintImageHelper;

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
