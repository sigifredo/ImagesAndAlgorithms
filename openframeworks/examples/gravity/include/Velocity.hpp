

#ifndef VELOCITY_HPP
#define VELOCITY_HPP

class Velocity
{
public:
    Velocity();
    Velocity(const float& fX, const float& fY);
    Velocity(const Velocity& oVelocity);

    Velocity& operator=(const Velocity& oVelocity);

    float x() const;
    float y() const;

    void setX(const float& fX);
    void setY(const float& fY);

private:
    float _fX;
    float _fY;
};

inline float Velocity::x() const
{
    return _fX;
}

inline float Velocity::y() const
{
    return _fY;
}

inline void Velocity::setX(const float& fX)
{
    _fX = fX;
}

inline void Velocity::setY(const float& fY)
{
    _fY = fY;
}

#endif
