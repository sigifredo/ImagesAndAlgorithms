

#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
public:
    Color();
    Color(const float& fRed, const float& fGreen, const float& fBlue);
    Color(const Color& oColor);

    Color& operator=(const Color& oColor);

    float blue() const;
    float green() const;
    float red() const;

    void setBlue(const float& fBlue);
    void setGreen(const float& fGreen);
    void setRed(const float& fRed);

private:
    float _fBlue;
    float _fGreen;
    float _fRed;
};

inline float Color::blue() const
{
    return _fBlue;
}

inline float Color::green() const
{
    return _fGreen;
}

inline float Color::red() const
{
    return _fRed;
}

inline void Color::setBlue(const float& fBlue)
{
    _fBlue = fBlue;
}

inline void Color::setGreen(const float& fGreen)
{
    _fGreen = fGreen;
}

inline void Color::setRed(const float& fRed)
{
    _fRed = fRed;
}

#endif
