

// Own
#include <BaseApplication.hpp>

#define CWD_BUFFER_SIZE         2 // 256

std::string BaseApplication::currentPath()
{
    std::string sCurrentPath;
    char * pCWDReturn = nullptr;
    size_t size = CWD_BUFFER_SIZE;
    char * szBuffer = nullptr;

    while (pCWDReturn == nullptr)
    {
        size *= 2;
        if (szBuffer)
        {
            delete [] szBuffer;
        }
        szBuffer = new char[size];

        pCWDReturn = getcwd(szBuffer, size);
    }

    sCurrentPath.append(szBuffer);
    delete [] szBuffer;

    if (sCurrentPath.back() != '/')
    {
        sCurrentPath.append("/");
    }

    return sCurrentPath;
}
