

#ifndef OFAPP_HPP
#define OFAPP_HPP

#include <ofMain.h>

class OFApp: public ofBaseApp
{
public:
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

    // member variables to store the current mouse X and Y position
    // as a percentage of the width/height of the screen
    float mouseXPercent, mouseYPercent;
};

#endif
