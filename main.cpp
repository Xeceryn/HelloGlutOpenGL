/*
 * GLUT drawLingkaran Dot Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test drawLingkaran in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

typedef struct {float x; float y;} Point2D_t;
typedef struct {int x; int y;} Point2D_i;

void createLingkaran(Point2D_t *p, int n){
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<360; i++){
        glVertex3f(p[i].x, p[i].y, 0.0);
    }
    glEnd();
}

void drawLingkaran(){
    Point2D_t p[360];
    float jari=100.0;
    float jari1=75.0;
    glClearColor(1.0, 1.0, 1.0, 0.0);
    for(int i=0; i<360; i++){
        double teta=(float)(i/57.3);
        p[i].x=(float)(jari*cos(teta));
        p[i].y=(float)(jari*sin(teta));
    }
    createLingkaran(p, 360);

    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    drawLingkaran();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Draw Lingkaran");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}


