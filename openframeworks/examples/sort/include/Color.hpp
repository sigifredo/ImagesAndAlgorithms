

#ifndef COLOR_HPP
#define COLOR_HPP

// OpenFrameworks
#include <ofColor.h>

class Color: public ofColor
{
public:
    Color();

    operator ofColor();
    bool operator=(const ofColor& oColor);
    bool operator<(const ofColor& oColor);
    bool operator>(const ofColor& oColor);
};

#endif
