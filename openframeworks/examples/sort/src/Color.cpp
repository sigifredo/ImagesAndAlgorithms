

// Own
#include <Color.hpp>

Color::Color():
    ofColor()
{
}

Color::operator ofColor()
{
    return *this;
}

bool Color::operator<(const ofColor& oColor)
{
    return getHex() < oColor.getHex();
}

bool Color::operator>(const ofColor& oColor)
{
    return getHex() > oColor.getHex();
}
