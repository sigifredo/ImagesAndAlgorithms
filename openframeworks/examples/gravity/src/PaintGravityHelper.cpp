

// Own
#include <PaintGravityHelper.hpp>

// Qt
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

// utils
#include <utils/IOStream.hpp>

#define STOUT_CLASS             "\e[94m[PaintGravityHelper]\e[39m "
#define STERR_CLASS             "\e[91m[PaintGravityHelper]\e[39m "

bool sortFunction(const int& i, const int& j)
{
    return i > j;
}

PaintGravityHelper::PaintGravityHelper(QObject * pParent):
    PaintHelperInterface(pParent)
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    _oBackground = QBrush(QColor(200, 200, 200));

    /*
    Particle sun;
    sun.setMass(10000.0f);
    sun.setRadius(10.0f);
    sun.setColor(QColor(255, 255, 0));
    sun.setX(400.0f);
    sun.setY(400.0f);

    Particle p1;
    p1.setMass(10.0f);
    p1.setRadius(5.0f);
    p1.setColor(QColor(100, 255, 0));
    p1.setX(100.0f);
    p1.setY(50.0f);

    Particle p2;
    p2.setMass(10.0f);
    p2.setRadius(5.0f);
    p2.setColor(QColor(255, 100, 0));

    Particle p3;
    p3.setMass(10.0f);
    p3.setRadius(5.0f);
    p3.setColor(QColor(100, 255, 0));
    p3.setX(50.0f);
    p3.setY(100.0f);

    _lParticles.push_back(p2);
    _lParticles.push_back(p1);
    _lParticles.push_back(sun);
    _lParticles.push_back(p3);
    */
}

void PaintGravityHelper::paint(QPainter* pPainter, QPaintEvent* pEvent)
{
    pPainter->save();
    pPainter->setPen(Qt::NoPen);

    //draw particles
    for (Particle& oParticle: _lParticles)
    {
        pPainter->setBrush(QBrush(oParticle.color()));
        pPainter->drawEllipse(QRectF(oParticle.x(), oParticle.y(), oParticle.radius()*2, oParticle.radius()*2));
    }

    pPainter->restore();
}

void PaintGravityHelper::readParticlesFromImage(const QString& sImagePath, const int& iParticleSize)
{
    QImage oImage;

    if (oImage.load(sImagePath))
    {
        _lParticles.clear();

        for (int i = 0; i < oImage.width(); i += iParticleSize)
        {
            for (int j = 0; j < oImage.height(); j += iParticleSize)
            {
                QColor oColor = oImage.pixelColor(i, j);
                Particle oParticle(i, j, iParticleSize/2.0, oColor.value(), oColor, Velocity());

                _lParticles.push_back(oParticle);
            }
        }
    }
    else
    {
        std::cerr << STERR_CLASS "No se ha podido leer la imagen (" << sImagePath << ")." << std::endl;
    }
}

void PaintGravityHelper::gravity(QPainter* pPainter, QPaintEvent* pEvent)
{
    pPainter->fillRect(pEvent->rect(), _oBackground);

    QSet<int> aItemsToDelete;
    int i = 0;
    for (Particle& oParticleA: _lParticles)
    {
        int j = 0;
        for (Particle& oParticleB: _lParticles)
        {
            if (i != j)
            {
                float fDistance = oParticleA.distance(oParticleB);

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
                    // _lParticles.removeAt(j);
                    aItemsToDelete.insert(j);
                    aItemsToDelete.remove(i);
                    oParticleA.setMass(oParticleA.mass() + oParticleB.mass());
                    oParticleA.setRadius(oParticleA.radius()+1);
                    j--;
                }
            }

            j++;
        }

        oParticleA.setX(oParticleA.x() + oParticleA.velocity().x());
        oParticleA.setY(oParticleA.y() + oParticleA.velocity().y());
        i++;
    }

    QList<int> lst = aItemsToDelete.toList();
    std::sort(lst.begin(), lst.end(), sortFunction);

    for (int& i: lst)
    {
        _lParticles.removeAt(i);
    }
}
