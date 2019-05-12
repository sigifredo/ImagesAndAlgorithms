

#include <ofMain.h>
#include <OFApp.hpp>

//========================================================================
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ofSetupOpenGL(527, 640, OF_WINDOW);			// <-------- setup the GL context

        // this kicks off the running of my app
        // can be OF_WINDOW or OF_FULLSCREEN
        // pass in width and height too:
        ofRunApp(new OFApp(argv[1]));
    }
    else
    {
        std::printf("use:\n\t%s <image path>\n", argv[0]);
    }
}
