

#ifndef OFAPP_HPP
#define OFAPP_HPP

// utils
#include <utils/BaseApplication.hpp>

// OpenFrameworks
#include <ofBaseApp.h>
#include <ofEvents.h>
#include <ofImage.h>

class Application: public BaseApplication
{
public:
    Application(const std::string& sImagePath);

    void dragEvent(ofDragInfo dragInfo);
    void draw();
    void gotMessage(ofMessage msg);
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseDragged(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void setup();
    void update();
    void windowResized(int w, int h);

private:
    ofImage _oImage;
    std::string _sImagePath;
};

#endif
