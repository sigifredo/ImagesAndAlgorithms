

#ifndef PAINTHELPER_HPP
#define PAINTHELPER_HPP

// Own
#include <Particle.hpp>

// Qt
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class PaintHelper
{
public:
    PaintHelper();

public:
    void paint(QPainter* pPainter, QPaintEvent* pEvent, const int& iElapsed);

private:
    std::vector<Particle> _lParticles;
    QBrush _oBackground;
};

#endif
