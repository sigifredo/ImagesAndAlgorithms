

// Own
#include <Velocity.hpp>

Velocity::Velocity()
{
    _fX = 0.0f;
    _fY = 0.0f;
}

Velocity::Velocity(const float& fX, const float& fY)
{
    _fX = fX;
    _fY = fY;
}

Velocity::Velocity(const Velocity& oVelocity)
{
    operator=(oVelocity);
}

Velocity& Velocity::operator=(const Velocity& oVelocity)
{
    _fX = oVelocity._fX;
    _fY = oVelocity._fY;

    return *this;
}
