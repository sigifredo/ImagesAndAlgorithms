

// Own
#include <OFApp.hpp>

OFApp::OFApp(const std::string& sImagePath)
{
    _sImagePath = sImagePath;
}

void OFApp::setup()
{
    ofSetVerticalSync(true);

    if (img.load(_sImagePath))
    {
        std::cout << "Image (" << _sImagePath << ") loaded" << std::endl;
    }
    else
    {
        perror("s");
        std::cerr << "Image (" << _sImagePath << ") not loaded" << std::endl;
    }
    ofSetLineWidth(2);
}

void OFApp::update()
{
}

void OFApp::draw()
{
    if (img.isAllocated())
    {
        ofBackground(ofColor::black);

        // draw the original image
        ofSetColor(ofColor::white);
        img.draw(0, 0);

        // draw the four rectangles
        ofNoFill();
        ofSetColor(ofColor::red);
        ofDrawRectangle(mouseX, mouseY, 100, 100);

        ofSetColor(ofColor::green);
        ofDrawRectangle(mouseX, mouseY, 50, 50);

        ofSetColor(ofColor::blue);
        ofDrawRectangle(mouseX + 25, mouseY + 25, 50, 50);

        ofSetColor(ofColor::magenta);
        ofDrawRectangle(mouseX - 25, mouseY - 25, 50, 50);

        // draw the four corresponding subsections
        ofTranslate(427, 0);
        ofSetColor(ofColor::white);
        img.drawSubsection(0, 0, 100, 100, mouseX, mouseY);
        ofSetColor(ofColor::red);
        ofDrawRectangle(0, 0, 100, 100);

        ofSetColor(ofColor::white);
        img.drawSubsection(0, 100, 100, 100, mouseX, mouseY, 50, 50);
        ofSetColor(ofColor::green);
        ofDrawRectangle(0, 100, 100, 100);

        ofSetColor(ofColor::white);
        img.drawSubsection(0, 200, 100, 100, mouseX + 25, mouseY + 25, 50, 50);
        ofSetColor(ofColor::blue);
        ofDrawRectangle(0, 200, 100, 100);

        ofSetColor(ofColor::white);
        img.drawSubsection(0, 300, 100, 100, mouseX - 25, mouseY - 25, 50, 50);
        ofSetColor(ofColor::magenta);
        ofDrawRectangle(0, 300, 100, 100);
    }
}

void OFApp::keyPressed(int key)
{
}

void OFApp::keyReleased(int key)
{
}

void OFApp::mouseMoved(int x, int y )
{
}

void OFApp::mouseDragged(int x, int y, int button)
{
}

void OFApp::mousePressed(int x, int y, int button)
{
}

void OFApp::mouseReleased(int x, int y, int button)
{
}

void OFApp::mouseEntered(int x, int y)
{
}

void OFApp::mouseExited(int x, int y)
{
}

void OFApp::windowResized(int w, int h)
{
}

void OFApp::gotMessage(ofMessage msg)
{
}

void OFApp::dragEvent(ofDragInfo dragInfo)
{
}
