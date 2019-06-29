

#ifndef UTILS_BASEAPPLICATION_HPP
#define UTILS_BASEAPPLICATION_HPP

// OpenFrameworks
#include <ofBaseApp.h>

class BaseApplication: public ofBaseApp
{
public:
    BaseApplication(): ofBaseApp() { }

    std::string currentPath();
};

#endif
