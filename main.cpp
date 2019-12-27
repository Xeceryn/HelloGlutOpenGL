/*
 * GLUT drawGrafikSinus Dot Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test drawGrafikSinus in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void drawGrafikSinus(){
    double i;
    glColor3f(0, 0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(0, 10);
        glVertex2f(0, -1);
        glVertex2f(6.283, 0);
        glVertex2f(-0.15, 0);
    glEnd();
    glColor3f(0, 1.0, 0);
    glBegin(GL_LINE_STRIP);
    for(i=0; i<6.3; i+=0.1)
        glVertex2f(i, cos(i));
    glEnd();
    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    drawGrafikSinus();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    gluOrtho2D(-1, 7, -1.25, 1.25);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Draw Grafik Sinus");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
