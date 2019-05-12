

// Own
#include <Application.hpp>

// OpenFrameworks
#include <ofAppRunner.h>
#include <ofGraphics.h>

Application::Application(const std::string& sImagePath)
{
    _sImagePath = sImagePath;
}

void Application::setup()
{
    ofSetVerticalSync(true);

    if (_oImage.load(_sImagePath))
    {
        std::cout << "Image (" << _sImagePath << ") loaded" << std::endl;
        ofSetupOpenGL(_oImage.getWidth(), _oImage.getHeight(), OF_WINDOW);
    }
    else
    {
        ofSetupOpenGL(100, 100, OF_WINDOW);
        std::cerr << "Image (" << _sImagePath << ") not loaded" << std::endl;
    }
    ofSetLineWidth(2);
}

void Application::update()
{
}

void Application::draw()
{
    if (_oImage.isAllocated())
    {
        ofBackground(ofColor::black);

        // draw the original image
        ofSetColor(ofColor::white);
        _oImage.draw(0, 0);
    }
}

void Application::keyPressed(int key)
{
}

void Application::keyReleased(int key)
{
}

void Application::mouseMoved(int x, int y )
{
}

void Application::mouseDragged(int x, int y, int button)
{
}

void Application::mousePressed(int x, int y, int button)
{
}

void Application::mouseReleased(int x, int y, int button)
{
}

void Application::mouseEntered(int x, int y)
{
}

void Application::mouseExited(int x, int y)
{
}

void Application::windowResized(int w, int h)
{
}

void Application::gotMessage(ofMessage msg)
{
}

void Application::dragEvent(ofDragInfo dragInfo)
{
}
