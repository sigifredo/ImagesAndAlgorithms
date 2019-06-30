

// Own
#include <Color.hpp>

Color::Color()
{
    _fBlue = 0.0f;
    _fGreen = 0.0f;
    _fRed = 0.0f;
}

Color::Color(const float& fRed, const float& fGreen, const float& fBlue)
{
    _fBlue = fBlue;
    _fGreen = fGreen;
    _fRed = fRed;
}

Color::Color(const Color& oColor)
{
    operator=(oColor);
}


Color& Color::operator=(const Color& oColor)
{
    _fBlue = oColor._fBlue;
    _fGreen = oColor._fGreen;
    _fRed = oColor._fRed;

    return *this;
}
