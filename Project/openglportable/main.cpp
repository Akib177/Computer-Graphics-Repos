#include <GL/glut.h>
#include <math.h>

//World
float worldH = 640;
float worldW = 480;

// Bird
float birdX, birdY;
float birdVY = 0;
float birdR = 14;

// Pipe
float pipeX;
float pipeGapY = 300;
float pipeW = 60;
float pipeGap = 160;
float pipeSpeed = 150;

//Draw Rectengular
void drawRect(float x,float y,float w,float h)
{
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+w,y);
    glVertex2f(x+w,y+h);
    glVertex2f(x,y+h);
    glEnd();
}

//Draw Circle
void drawCircle(float cx,float cy,float r)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0;i<=100;i++)
    {
        float a = i * 2 * 3.1416f / 100;
        glVertex2f(cx + cos(a)*r, cy + sin(a)*r);
    }
    glEnd();
}

//Cloud
void drawCloud(float x,float y)
{
    glColor3f(1,1,1);
    drawCircle(x,y,20);
    drawCircle(x+20,y+10,25);
    drawCircle(x-20,y+10,25);
    drawCircle(x+40,y,18);
}

//  Background
void drawHill()
{
    glColor3f(0.2,0.6,0.2);
    drawCircle(120,80,150);
    drawCircle(360,80,180);
}
void drawBackground()
{
    glColor3f(0.53,0.81,0.98);
    drawRect(0,0,worldW,worldH);

    // Clouds
    drawCloud(100,520);
    drawCloud(280,560);
    drawCloud(380,500);

    drawHill();

    glColor3f(0.36,0.25,0.2);
    drawRect(0,0,worldW,80);
}
