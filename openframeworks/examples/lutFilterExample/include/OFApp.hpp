

#ifndef OFAPP_HPP
#define OFAPP_HPP

#include <ofMain.h>

class OFApp: public ofBaseApp
{
public:
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
    void gotMessage(ofMessage msg);
    void dragEvent(ofDragInfo dragInfo);

    void loadLUT(std::string path);
    void applyLUT(ofPixelsRef pix);

    bool doLUT;
    // ofVideoGrabber vidGrabber;
    ofVideoPlayer vidGrabber;
    int dirLoadIndex;
    ofDirectory dir;
    ofPoint lutPos;
    ofPoint thumbPos;

    bool LUTloaded;
    ofVec3f lut[32][32][32];

    ofImage lutImg;
};

#endif
