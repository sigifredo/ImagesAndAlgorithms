

// Own
#include <PaintHelper.hpp>

// Qt
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

PaintHelper::PaintHelper()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    _oBackground = QBrush(QColor(64, 32, 64));

    //initial centered Huge mass particle
    Particle sun;
    sun.setMass(10000.0f);
    sun.setRadius(10.0f);
    sun.setColor(QColor(255, 255, 0));
    sun.setX(500.0f);
    sun.setY(500.0f);

    Particle p1;
    p1.setMass(10.0f);
    p1.setRadius(5.0f);
    p1.setColor(QColor(100, 255, 0));

    _lParticles.push_back(sun);
    _lParticles.push_back(p1);
}

void PaintHelper::paint(QPainter* pPainter, QPaintEvent* pEvent, const int& iElapsed)
{
    pPainter->fillRect(pEvent->rect(), _oBackground);

    int i = 0;
    for (Particle& oParticleA: _lParticles)
    {
        bool bNotFall = true;

        int j = 0;
        for (Particle oParticleB: _lParticles)
        {
            // we consider the 10000 as infinit (big mass) so this particles won't move
            if (i == j || oParticleA.mass() >= 10000.0f)
            {
                continue;
            }

            float fDistance = oParticleA.distance(oParticleB);

            // std::printf("distance > radius => %.2f > %.2f\n", fDistance, oParticleB.radius());
            if (fDistance > oParticleB.radius())
            {
                Velocity oVelocity;

                oVelocity.setX(oParticleA.velocity().x() + (0.03 * oParticleB.mass() / (fDistance*fDistance) * (oParticleB.x() - oParticleA.x())/fDistance));
                oVelocity.setY(oParticleA.velocity().y() + (0.03 * oParticleB.mass() / (fDistance*fDistance) * (oParticleB.y() - oParticleA.y())/fDistance));

                oParticleA.setVelocity(oVelocity);
                // p.vx += 0.03 * p1.m / (d*d) * (p1.x - p.x)/d; //f = ma => a = f/m
                // p.vy += 0.03 * p1.m / (d*d) * (p1.y - p.y)/d;
            }
            else
            {
                bNotFall = false;
            }

            j++;
        }

        if (bNotFall)
        {
            oParticleA.setX(oParticleA.x() + oParticleA.velocity().x());
            oParticleA.setY(oParticleA.y() + oParticleA.velocity().y());
        }
        else
        {
            _lParticles.erase(_lParticles.begin() + i);
        }

        i++;
    }

    pPainter->save();

    //draw particles
    for (Particle& oParticle: _lParticles)
    {
        pPainter->setBrush(QBrush(oParticle.color()));
        pPainter->drawEllipse(QRectF(oParticle.x(), oParticle.x(), oParticle.radius()*2, oParticle.radius()*2));
    }

    pPainter->restore();
}
