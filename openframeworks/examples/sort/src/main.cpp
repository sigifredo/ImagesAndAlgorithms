

// Own
#include <Application.hpp>

// OpenFrameworks
#include <ofAppRunner.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ofRunApp(new Application(argv[1]));
    }
    else
    {
        std::printf("use:\n\t%s <image path>\n", argv[0]);
    }
}
