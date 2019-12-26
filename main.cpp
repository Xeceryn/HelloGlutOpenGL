/*
 * GLUT Star 2D Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test Star 2D in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void userDrawStar(){
    glColor3f(0,0,0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.40, -1.60);
    glVertex2f(-0.90, -0.15);
    glVertex2f(-2.0, 0.75);
    glVertex2f(-0.5, 0.75);
    glVertex2f(0.0, 2.0);
    glVertex2f(0.5, 0.75);
    glVertex2f(2.0, 0.75);
    glVertex2f(0.90, -0.15);
    glVertex2f(1.40, -1.60);
    glVertex2f(0.0, -0.75);
    glEnd();
    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    userDrawStar();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Draw Dot");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
