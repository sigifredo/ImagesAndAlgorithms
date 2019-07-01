

// Own
#include <Particle.hpp>

// std
#include <cmath>

Particle::Particle()
{
    _fX = 0.0f;
    _fY = 0.0f;
    _fRadius = 0.0f;
    _fMass = 0.0f;
}

Particle::Particle(const float& fX, const float& fY, const float& fRadius, const float& fMass, const QColor& oColor, const Velocity& oVelocity)
{
    _fX = fX;
    _fY = fY;
    _fRadius = fRadius;
    _fMass = fMass;
    _oColor = oColor;
    _oVelocity = oVelocity;
}

Particle::Particle(const Particle& oParticle)
{
    operator=(oParticle);
}

Particle& Particle::operator=(const Particle& oParticle)
{
    _fX = oParticle._fX;
    _fY = oParticle._fY;
    _fRadius = oParticle._fRadius;
    _fMass = oParticle._fMass;
    _oColor = oParticle._oColor;
    _oVelocity = oParticle._oVelocity;

    return *this;
}

float Particle::distance(const Particle& oParticle)
{
    return std::sqrt((oParticle._fX - _fX) * (oParticle._fX - _fX) + (oParticle._fY - _fY) * (oParticle._fY - _fY));
}
