/*
 * GLUT drawStarRed Dot Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test drawStarRed in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

typedef struct {float x; float y;} Point2D_t;
typedef struct {int x; int y;} Point2D_i;

void createStar(Point2D_t *bintang, int n){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<n; i++){
            glVertex3f(bintang[i].x, bintang[i].y, 0);
        }
    glEnd();
}

void drawStar(){
    glClear(GL_COLOR_BUFFER_BIT);
    Point2D_t bintang[10]={{70, 136}, {89, 80}, {147, 80}, {100, 45}, {118, -9}, {70, 24}, {22, -9}, {44, 45}, {-7, 80}, {53, 80}};

    createStar(bintang, 10);

    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    drawStar();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(200, 200);
    glutCreateWindow("Draw Star");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}


