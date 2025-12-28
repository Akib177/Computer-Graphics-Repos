#include <GL/glut.h>
# include<math.h>
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);

    /*
    glBegin(GL_LINES);

       glColor3f(1,0,0);
       glVertex2f(-0.50,-0.90);
       glVertex2f(0.50,-0.90);

       glColor3f(0,0,1);
       glVertex2f(0.50,-0.90);
       glVertex2f(0.50,-0.2);

       glColor3f(1,0,1);
       glVertex2f(0.50,-0.2);
       glVertex2f(-0.50,-0.2);

       glColor3f(1,1,0);
       glVertex2f(-0.50,-0.90);
       glVertex2f(-0.50,-0.20);

*/

glBegin(GL_POLYGON);

glColor3f(0,1,1);
glVertex2f(0.8,0.5);

glColor3f(0,0,1);
glVertex2f(0.80,-0.50);

glColor3f(0,1,0);
glVertex2f(-0.80,-0.50);

glColor3f(1,0,0);
glVertex2f(-0.80,0.50);



   glEnd();
   glFlush();

   
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 360); //window size
    glutCreateWindow("OpenGL 64bit");
    glutDisplayFunc(display); //call the function
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//window color
    glutMainLoop();
    return 0;
}
