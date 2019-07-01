

#ifndef GLWIDGET_HPP
#define GLWIDGET_HPP

// Own
#include <PaintHelper.hpp>

// Qt
#include <QOpenGLWidget>

class GLWidget: public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget * pParent = nullptr);

protected:
    void paintEvent(QPaintEvent* pEvent) override;
    void timerEvent(QTimerEvent* pEvent) override;

private:
    int _iElapsed;
    PaintHelper _oPaintHelper;
};

#endif
