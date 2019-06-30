

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

// Own
#include <Color.hpp>
#include <Velocity.hpp>

class Particle
{
    Particle();
    Particle(const float& fX, const float& fY, const float& fRadius, const float& fMass, const Color& oColor, const Velocity& oVelocity);
    Particle(const Particle& oParticle);

    Particle& operator=(const Particle& oParticle);

    float x() const;
    float y() const;
    float radius() const;
    float mass() const;
    Color color() const;
    Velocity velocity() const;

    void setX(const float& fX);
    void setY(const float& fY);
    void setRadius(const float& fRadius);
    void setMass(const float& fMass);
    void setColor(const Color& oColor);
    void setVelocity(const Velocity& oVelocity);

private:
    float _fX;
    float _fY;
    float _fRadius;
    float _fMass;
    Color _oColor;
    Velocity _oVelocity;
};

float Particle::x() const
{
    return _fX;
}

float Particle::y() const
{
    return _fY;
}

float Particle::radius() const
{
    return _fRadius;
}

float Particle::mass() const
{
    return _fMass;
}

Color Particle::color() const
{
    return _oColor;
}

Velocity Particle::velocity() const
{
    return _oVelocity;
}

void Particle::setX(const float& fX)
{
    _fX = fX;
}

void Particle::setY(const float& fY)
{
    _fY = fY;
}

void Particle::setRadius(const float& fRadius)
{
    _fRadius = fRadius;
}

void Particle::setMass(const float& fMass)
{
    _fMass = fMass;
}

void Particle::setColor(const Color& oColor)
{
    _oColor = oColor;
}

void Particle::setVelocity(const Velocity& oVelocity)
{
    _oVelocity = oVelocity;
}

#endif
