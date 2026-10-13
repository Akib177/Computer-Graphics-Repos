#include<windows.h>
#include<GL/freeglut.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

float Angle=0.0f;
float Angle_tree=0.0f;
float speed_cloud = 0.005f;
float speed_Tree = 0.015f;
float car = 0.0f;
float enemy_y=0.01f;
float enemy_x=0.0f;
float score=0;
float sunY = 1.5f;
float moonY = -1.5f;
float speed_sun_moon = 0.005f;
float enemy_speed=0.02f;

int isGameOver = 0;
int gameStarted=0;

void circle(float cx , float cy , float r){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++){
        float angle = 2 * 3.1416f * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void update(int value){
    if (isGameOver) return;

    Angle += speed_cloud;
    if(Angle > 1.5f) Angle = -1.5f;

    Angle_tree -= speed_Tree;
    if(Angle_tree < -1.5f) Angle_tree = 0.004f;

    sunY -= speed_sun_moon;
    if(sunY < -1.5f) sunY = 1.5f;

    moonY += speed_sun_moon;
    if(moonY > 1.5f) moonY = -1.5f;

    enemy_y -= enemy_speed;

    if (enemy_y < -0.6f && enemy_y > -0.9f && fabs(car - enemy_x) < 0.2f) {
        isGameOver = 1;
    }

    if(enemy_y < -1.5){
        enemy_y = 0.8;
        score++;
        int rand_val = rand() % 3;
        if(rand_val == 1){
             enemy_x = -0.4f;
        }


        else if(rand_val == 0){
            enemy_x = 0.0f;
        }
        else enemy_x = 0.4f;
    }

    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}

void moon(){
    glColor3f(0.98f,0.96f,0.98f);
    circle(moonY * 0.4f, moonY, 0.1f);
}

void enemy_car(){
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(enemy_x, enemy_y, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.08, -0.1);
        glVertex2f(0.08, -0.1);
        glVertex2f(0.08, 0.1);
        glVertex2f(-0.08, 0.1);
    glEnd();
    glPopMatrix();
}

void Player_car(){
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2d(-0.1, -0.9);
        glVertex2d(0.1, -0.9);
        glVertex2d(0.1, -0.6);
        glVertex2d(-0.1, -0.6);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(-0.08, -0.7);
        glVertex2d(0.08, -0.7);
        glVertex2d(0.08, -0.62);
        glVertex2d(-0.08, -0.62);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(-0.08, -0.88);
        glVertex2d(0.08, -0.88);
        glVertex2d(0.08, -0.82);
        glVertex2d(-0.08, -0.82);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(-0.06, -0.61);
        glVertex2d(0.06, -0.61);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2d(-0.12, -0.7);
        glVertex2d(-0.1, -0.7);
        glVertex2d(-0.1, -0.65);
        glVertex2d(-0.12, -0.65);

        glVertex2d(0.1, -0.7);
        glVertex2d(0.12, -0.7);
        glVertex2d(0.12, -0.65);
        glVertex2d(0.1, -0.65);

        glVertex2d(-0.12, -0.85);
        glVertex2d(-0.1, -0.85);
        glVertex2d(-0.1, -0.8);
        glVertex2d(-0.12, -0.8);

        glVertex2d(0.1, -0.85);
        glVertex2d(0.12, -0.85);
        glVertex2d(0.12, -0.8);
        glVertex2d(0.1, -0.8);
    glEnd();
}

void cloud(){
    glPushMatrix();
    if(moonY>0.5){
        glColor3f(0.0,0.0,0.2);
    }else{
     glColor3f(1.0f,1.0f,1.0f);
    }

    glTranslatef(Angle , 0,0);

    circle(-0.7f,0.65f,0.11f);
    circle(-0.8f,0.65f,0.09f);
    circle(-0.6f,0.65f,0.08f);
    circle(0.3f,0.65f,0.11f);
    circle(0.4f,0.65f,0.09f);
    circle(0.2f,0.65f,0.08f);
    glPopMatrix();
}

void Sky(){

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.81f,0.92f);
    glVertex2d(1,1);

    glVertex2d(-1,1);
    glColor3f(1.0,1.0,1.0);
    glVertex2d(-1,0.2);
    glVertex2d(1,0.2);
    glEnd();
}

void Sun(){
    glColor3f(1.0f,0.8f,0.0f);

    circle(-sunY * 0.4f, sunY, 0.1f);

}

void Left_Tree(){
    glPushMatrix();
    glTranslatef(0.0, Angle_tree, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.5f,0.2f);
    glVertex2d(-0.8,0.2);
    glVertex2d(-1.0,0.2);
    glVertex2d(-0.9,0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.55f,0.35f,0.18f);
    glVertex2d(-0.85,0.0);
    glVertex2d(-0.95,0.0);
    glVertex2d(-0.95,0.2);
    glVertex2d(-0.85,0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.5f,0.2f);
    glVertex2d(-0.8,-0.6);
    glVertex2d(-1.0,-0.6);
    glVertex2d(-0.9,-0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.55f,0.35f,0.18f);
    glVertex2d(-0.85,-0.6);
    glVertex2d(-0.95,-0.6);
    glVertex2d(-0.95,-0.8);
    glVertex2d(-0.85,-0.8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,Angle_tree,0);
    glColor3f(0.0f, 0.5f, 0.2f);
    circle(0.9, -0.1, 0.05);
    circle(0.85, -0.2, 0.04);
    circle(0.95,-0.23,0.04);
    circle(-0.9, -0.1, 0.05);
    circle(-0.85, -0.2, 0.04);
    circle(-0.95,-0.23,0.04);
    glPopMatrix();
}

void Road_Environment(){
    glBegin(GL_QUADS);
      glColor3f(0.0f,0.6f,0.2f);
    glVertex2f(0.8, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0.5);
    glVertex2f(0.8, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.6f,0.2f);
    glVertex2f(-0.8, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, 0.5);
    glVertex2f(-0.8, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.18f,0.18f,0.20f);
    glVertex2f(-0.8, -1);
    glVertex2f(0.8, -1.0);
    glVertex2f(0.8, 0.5);
    glVertex2f(-0.8, 0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2d(-0.6,-1);
    glVertex2d(-0.6,0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2d(0.6,-1);
    glVertex2d(0.6,0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2d(0.0,-1);
    glVertex2d(0.0,0.5);
    glEnd();
}

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void Right_Tree(){
    glPushMatrix();
    glTranslatef(0.0,Angle_tree,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.5f,0.2f);
    glVertex2d(0.8,0.2);
    glVertex2d(1,0.2);
    glVertex2d(0.9,0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.55f,0.35f,0.18f);
    glVertex2d(0.85,0.0);
    glVertex2d(0.95,0.0);
    glVertex2d(0.95,0.2);
    glVertex2d(0.85,0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.5f,0.2f);
    glVertex2d(0.8,-0.6);
    glVertex2d(1,-0.6);
    glVertex2d(0.9,-0.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.55f,0.35f,0.18f);
    glVertex2d(0.85,-0.6);
    glVertex2d(0.95,-0.6);
    glVertex2d(0.95,-0.8);
    glVertex2d(0.85,-0.8);
    glEnd();
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Sun();
    moon();
    cloud();
    Road_Environment();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1, 0.9);
    glVertex2f(1, 0.9);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

    Left_Tree();
    Right_Tree();

    if(moonY > 0.5f){
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0f, 0.0f, 0.1f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(-1, -1);
        glVertex2f( 1, -1);
        glVertex2f( 1,  1);
        glVertex2f(-1,  1);
        glEnd();
        glDisable(GL_BLEND);
    }

    glPushMatrix();
    glTranslatef(car, 0, 0);
    Player_car();
    glPopMatrix();
    enemy_car();


    char scoreStr[20];
    sprintf(scoreStr, "Score: %d", (int)score);
    glColor3f(1, 1, 1);
    drawText(scoreStr, -0.1f, 0.93f);

    if(!gameStarted){
        glColor3f(1.0f, 0.0f, 0.0f);

        drawText("Press 'Space' to start", -0.2f, -0.3f);

    }

    if(isGameOver){
        glColor3f(1.0f, 0.0f, 0.0f);
        drawText("GAME OVER!", -0.15f, 0.0f);
        drawText("Press 'r' to Restart", -0.2f, -0.1f);
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    if (isGameOver && key != 'r')
        return;

    switch (key) {
        case 'a':
            if (car > -0.65) car -= 0.1f;
            break;
        case 'd':
            if (car < 0.65) car += 0.1f;
            break;
        case ' ':
            gameStarted=1;
            isGameOver=0;
            score=0;
            enemy_y=1.0f;
            car=0.0f;
            glutTimerFunc(16,update,0);
            break;
        case 'r':
            isGameOver = 0;
            score = 0;
            enemy_y = 1.0f;
            car = 0.0f;
            glutTimerFunc(16, update, 0);
            break;

        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc , char **argv){
    srand(time(0));
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,500);
    glutCreateWindow("Final Scene");

    glClearColor(1.0, 1.0, 1.0, 1.0);


    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
