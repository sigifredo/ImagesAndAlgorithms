

// Own
#include <OFApp.hpp>

void OFApp::addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c)
{
    ofVec3f normal = ((b - a).cross(c - a)).normalize();
    mesh.addNormal(normal);
    mesh.addVertex(a);
    mesh.addNormal(normal);
    mesh.addVertex(b);
    mesh.addNormal(normal);
    mesh.addVertex(c);
}

void OFApp::addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d)
{
    addFace(mesh, a, b, c);
    addFace(mesh, a, c, d);
}

ofVec3f OFApp::getVertexFromImg(ofFloatImage& img, int x, int y)
{
    return ofVec3f(x, y, 100 * img.getColor(x, y).getBrightness());
}

void OFApp::setup()
{
    //note: you can get nicer anti-aliased rendering ( with slower fps )
    //if you uncomment the appropriate line in main.cpp

    img.load("nyc-small.exr");

    light.enable();
    light.setPosition(+500, 0, 0);

    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    int skip = 1;
    int width = img.getWidth();
    int height = img.getHeight();

    for (int y = 0; y < height - skip; y += skip)
    {
        for (int x = 0; x < width - skip; x += skip)
        {
            ofVec3f nw = getVertexFromImg(img, x, y);
            ofVec3f ne = getVertexFromImg(img, x + skip, y);
            ofVec3f sw = getVertexFromImg(img, x, y + skip);
            ofVec3f se = getVertexFromImg(img, x + skip, y + skip);

            addFace(mesh, nw, ne, se, sw);
        }
    }
}

void OFApp::update()
{
}

void OFApp::draw()
{
    ofBackground(0);

    easyCam.begin();
    ofScale(1, -1, 1);
    ofRotateXDeg(60);
    ofTranslate(-img.getWidth() / 2, -img.getHeight() / 2, 0);
    ofSetColor(255);
    ofEnableDepthTest();
    mesh.draw();
    ofDisableDepthTest();
    easyCam.end();
}

void OFApp::keyPressed(int key)
{
}

void OFApp::keyReleased(int key)
{
}

void OFApp::mouseMoved(int x, int y)
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
