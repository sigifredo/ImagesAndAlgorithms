

#ifndef OFAPP_HPP
#define OFAPP_HPP

// utils
#include <utils/BaseApplication.hpp>

// OF
#include <ofMain.h>

class OFApp: public BaseApplication
{
public:
    OFApp(const std::string& sImagePath);

    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofImage img;

private:
    std::string _sImagePath;
};

#endif
