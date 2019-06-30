

// Own
#include <Application.hpp>

// OpenFrameworks
#include <ofAppRunner.h>
#include <ofGraphics.h>

Application::Application(const std::string& sImagePath)
{
    if (sImagePath.front() == '/')
    {
        _sImagePath = sImagePath;
    }
    else
    {
        _sImagePath = currentPath() + sImagePath;
    }

    if (_oImage.load(_sImagePath))
    {
        std::cout << "Image (" << _sImagePath << ") loaded" << std::endl;
        // ofSetupOpenGL(_oImage.getWidth(), _oImage.getHeight(), OF_WINDOW);
        ofSetupOpenGL(_oImage.getHeight(), _oImage.getWidth(), OF_WINDOW);
    }
    else
    {
        ofSetupOpenGL(100, 100, OF_WINDOW);
        std::cerr << "Image (" << _sImagePath << ") not loaded" << std::endl;
    }
}

void Application::setup()
{
    ofSetVerticalSync(true);

    bubbleSort();

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

void Application::keyPressed(int)
{
}

void Application::keyReleased(int)
{
}

void Application::mouseMoved(int, int)
{
}

void Application::mouseDragged(int, int, int)
{
}

void Application::mousePressed(int, int, int)
{
}

void Application::mouseReleased(int, int, int)
{
}

void Application::mouseEntered(int, int)
{
}

void Application::mouseExited(int, int)
{
}

void Application::windowResized(int, int)
{
}

void Application::gotMessage(ofMessage)
{
}

void Application::dragEvent(ofDragInfo)
{
}

void Application::bubbleSort()
{
    auto start = std::chrono::system_clock::now();

    ofImage oSecondImage;
    oSecondImage.allocate(_oImage.getWidth(), _oImage.getHeight(), _oImage.getImageType());

    for (int iRow = 0; iRow < _oImage.getHeight(); iRow++)
    {
        for (int j = 0; j < _oImage.getWidth(); j++)
        {
            oSecondImage.setColor(iRow, j, _oImage.getColor(iRow, j));
        }

        for (int i = 0; i < oSecondImage.getWidth()-1; i++)
        {
            for (int j = 0; j < oSecondImage.getWidth()-i-1; j++)
            {
                if (oSecondImage.getColor(iRow, j).getHex() > oSecondImage.getColor(iRow, j+1).getHex())
                {
                    ofColor tmp = oSecondImage.getColor(iRow, j);
                    oSecondImage.setColor(iRow, j, oSecondImage.getColor(iRow, j+1));
                    oSecondImage.setColor(iRow, j+1, tmp);
                }
            }
        }
    }

    _oImage = oSecondImage;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << __func__ << ": elapsed time: " << elapsed_seconds.count() << "s\n";
}

void Application::transpose()
{
    ofImage oSecondImage;
    oSecondImage.allocate(_oImage.getHeight(), _oImage.getWidth(), _oImage.getImageType());

    for (int i = 0; i < _oImage.getWidth(); i++)
    {
        for (int j = 0; j < _oImage.getHeight(); j++)
        {
            oSecondImage.setColor(j, i, _oImage.getColor(i, j));
        }
    }

    _oImage = oSecondImage;
}
