

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

// Own
#include <Velocity.hpp>

// Qt
#include <QColor>

class Particle
{
public:
    Particle();
    Particle(const float& fX, const float& fY, const float& fRadius, const float& fMass, const QColor& oColor, const Velocity& oVelocity);
    Particle(const Particle& oParticle);

    Particle& operator=(const Particle& oParticle);

    float distance(const Particle& oParticle);

    /**
     * Métodos accesores.
     */

    float x() const;
    float y() const;
    float radius() const;
    float mass() const;
    QColor& color();
    Velocity& velocity();

    void setX(const float& fX);
    void setY(const float& fY);
    void setRadius(const float& fRadius);
    void setMass(const float& fMass);
    void setColor(const QColor& oColor);
    void setVelocity(const Velocity& oVelocity);

private:
    float _fX;
    float _fY;
    float _fRadius;
    float _fMass;
    QColor _oColor;
    Velocity _oVelocity;
};

inline float Particle::x() const
{
    return _fX;
}

inline float Particle::y() const
{
    return _fY;
}

inline float Particle::radius() const
{
    return _fRadius;
}

inline float Particle::mass() const
{
    return _fMass;
}

inline QColor& Particle::color()
{
    return _oColor;
}

inline Velocity& Particle::velocity()
{
    return _oVelocity;
}

inline void Particle::setX(const float& fX)
{
    _fX = fX;
}

inline void Particle::setY(const float& fY)
{
    _fY = fY;
}

inline void Particle::setRadius(const float& fRadius)
{
    _fRadius = fRadius;
}

inline void Particle::setMass(const float& fMass)
{
    _fMass = fMass;
}

inline void Particle::setColor(const QColor& oColor)
{
    _oColor = oColor;
}

inline void Particle::setVelocity(const Velocity& oVelocity)
{
    _oVelocity = oVelocity;
}

#endif
