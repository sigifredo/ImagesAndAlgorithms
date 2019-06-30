/*##############################################
##                                            ##
##  Program: Gravity simulation               ##
##  Author: Curcudel Eugen (GuessGen)         ##
##  E-mail: CurcudelEugen@gmail.com           ##
##  WebSite: http://GuessGen.wordpress.com    ##
##                                            ##
##############################################*/

// Own
#include <Particle.hpp>

#include <GL/glut.h>

// std
#include <cmath>
#include <iostream>
#include <vector>

struct Line
{
    float x1;
    float y1;
    float x2;
    float y2;
} line;

void timer(int = 0);
void display();
void mouse(int, int, int, int);
void mouseMotion(int, int);
void addParticle(float, float, bool = true, float = 0, float = 0);
void removeParticles();
void keyboard(unsigned char, int, int);

int Mx, My, WIN;
bool PRESSED_LEFT = false, PRESSED_RIGHT = false,
     PRESSED_MIDDLE = false, SPEED_PARTICLES = false;

std::vector<Particle> particles;

int main(int argc, char **argv)
{
    //initial centered Huge mass particle
    Particle p;
    p.setMass(10000.0f);
    p.setRadius(10.0f);
    p.setColor(Color(1.0f, 1.0f, 0.0f));
    particles.push_back(p);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    WIN = glutCreateWindow("Gravity");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250.0, 250.0, 250.0, -250.0, 0, 1);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    timer();

    glutMainLoop();
    return 0;
}

void timer(int)
{
    display();
    if (PRESSED_LEFT && !SPEED_PARTICLES)
    {
        addParticle(10, 3); //add tiny particle
        PRESSED_LEFT = false;
    }

    if (PRESSED_RIGHT)
    {
        addParticle(10000, 10, 0); //add huge particle
        PRESSED_RIGHT = false;
    }

    if (PRESSED_MIDDLE)
    {
        removeParticles(); //remove all particles
    }

    int i = 0;
    for (Particle& oParticleA: particles)
    {
        bool bNotFall = true;

        int j = 0;
        for (Particle oParticleB: particles)
        {
            // we consider the 10000 as infinit (big mass) so this particles won't move
            if (i == j || oParticleA.mass() >= 10000.0f)
            {
                continue;
            }

            float fDistance = oParticleA.distance(oParticleB);

            // std::printf("distance > radius => %.2f > %.2f\n", fDistance, oParticleB.radius());
            if (fDistance > oParticleB.radius())
            {
                Velocity oVelocity;

                oVelocity.setX(oParticleA.velocity().x() + (0.03 * oParticleB.mass() / (fDistance*fDistance) * (oParticleB.x() - oParticleA.x())/fDistance));
                oVelocity.setY(oParticleA.velocity().y() + (0.03 * oParticleB.mass() / (fDistance*fDistance) * (oParticleB.y() - oParticleA.y())/fDistance));

                oParticleA.setVelocity(oVelocity);
                // p.vx += 0.03 * p1.m / (d*d) * (p1.x - p.x)/d; //f = ma => a = f/m
                // p.vy += 0.03 * p1.m / (d*d) * (p1.y - p.y)/d;
            }
            else
            {
                bNotFall = false;
            }

            j++;
        }

        if (bNotFall)
        {
            oParticleA.setX(oParticleA.x() + oParticleA.velocity().x());
            oParticleA.setY(oParticleA.y() + oParticleA.velocity().y());
        }
        else
        {
            particles.erase(particles.begin() + i);
        }

        i++;
    }

    glutTimerFunc(1, timer, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //draw the drag line
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(line.x1, line.y1);
    glVertex2f(line.x2, line.y2);
    glEnd();

    //draw particles
    for (Particle& oParticle: particles)
    // for(int i = 0; i < particles.size(); i++)
    {
        glColor3f(oParticle.color().red(), oParticle.color().green(), oParticle.color().blue());
        glBegin(GL_POLYGON);

        for (float a = 0; a < 2*M_PI; a+=0.2)
        {
            glVertex2f(oParticle.radius()*cos(a) + oParticle.x(), oParticle.radius()*sin(a) + oParticle.y());
        }

        glEnd();
    }

    glFlush();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    //set the coordinates
    Mx = x - 250;
    My = y - 250;

    //add speed particles by line draging
    if (SPEED_PARTICLES)
    {
        if(line.x2 != 0 && line.y2 != 0 && state == GLUT_UP && PRESSED_LEFT)
        {
            addParticle(100, 5, 1, line.x1 - line.x2, line.y1 - line.y2); //add a speed particle
        }
        else
        {
            line.x1 = line.x2 = Mx;
            line.y1 = line.y2 = My;
        }
    }

    //check which button is pressed
    if(button == GLUT_LEFT_BUTTON)
        PRESSED_LEFT = state == GLUT_DOWN;
    else if(button == GLUT_RIGHT_BUTTON)
        PRESSED_RIGHT = state == GLUT_DOWN;
    else if(button == GLUT_MIDDLE_BUTTON)
        PRESSED_MIDDLE = state == GLUT_DOWN;
}

void mouseMotion(int x, int y)
{
    Mx = x - 250;
    My = y - 250;

    //end of line with draging
    if (SPEED_PARTICLES && PRESSED_LEFT)
    {
        line.x2 = Mx;
        line.y2 = My;
    }
}

void addParticle(float m, float r, bool randColor, float vx, float vy)
{
    Color oColor;

    if (randColor)
    {
        oColor.setRed(std::rand()%200 / 200.0f);
        oColor.setGreen(std::rand()%200 / 200.0f);
        oColor.setBlue(std::rand()%200 / 200.0f);
    }
    else
    {
        oColor.setRed(1.0f);
        oColor.setGreen(1.0f);
        oColor.setBlue(0.0f);
    }

    particles.push_back(Particle(Mx, My, r, m, oColor, Velocity(vx/30.f, vy/30.0f)));

    if (line.x1 != 0)
    {
        line.x1 = line.x2 = line.y1 = line.y2 = 0;
    }
}

void removeParticles()
{
    for (size_t i = 0; i < particles.size(); i++)
    {
        particles.pop_back();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 's':
        SPEED_PARTICLES = !SPEED_PARTICLES;
        break;
    case 27:
        removeParticles();
        glutDestroyWindow(WIN);
        exit(0);
        break;
    }
}
