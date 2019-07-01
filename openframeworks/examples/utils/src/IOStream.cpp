

// Own
#include <IOStream.hpp>

std::ostream& operator<<(std::ostream& os, const QString& sStr)
{
    os << sStr.toStdString();
    return os;
}
