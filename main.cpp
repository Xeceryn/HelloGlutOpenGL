/*
 * GLUT Simple Dot Line Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test Dot Line in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void userDrawDotLine(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
        glVertex3f(15.0, 15.0, 0.0);
        glVertex3f(-15.0, 15.0, 0.0);
        glVertex3f(-15.0, -15.0, 0.0);
        glVertex3f(15.0, -15.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
        glVertex3f(25, 25, 0.0);
        glVertex3f(175.0, 175.0, 0.0);
    glEnd();

    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    userDrawDotLine();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400,400);
    glutInitWindowSize(200, 200);
    glutCreateWindow("Dot Line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}


