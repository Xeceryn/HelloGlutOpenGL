/*
 * GLUT Simple Dot Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test Dot in GLUT.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void userDrawAbstract(){
    glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_STRIP);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(-0.4, 0.4, 0.0);
        glVertex3f(-0.4, -0.4, 0.0);
        glVertex3f(0.4, -0.4, 0.0);
        glEnd();

        /* titik random */
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(5);
        glBegin(GL_POINTS);
        for(int i=0; i<100; i++){
            float a=(float)(rand()%100)/100;
            float b=(float)(rand()%100)/100;
            glVertex3f(a, b, 0.0);
            glVertex3f(-a, b, 0.0);
            glVertex3f(a, -b, 0.0);
            glVertex3f(-a, -b, 0.0);
        }
        glEnd();

        /* kotak mendatar */
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
        glVertex3f(-0.2, 1.0, 0.0);
        glVertex3f(-0.2, -1.0, 0.0);
        glVertex3f(-0.4, 1.0, 0.0);
        glVertex3f(-0.4, -1.0, 0.0);
        glVertex3f(-0.6, 1.0, 0.0);
        glVertex3f(-0.6, -1.0, 0.0);
        glVertex3f(-0.8, 1.0, 0.0);
        glVertex3f(-0.8, -1.0, 0.0);
        glVertex3f(0.2, 1.0, 0.0);
        glVertex3f(0.2, -1.0, 0.0);
        glVertex3f(0.4, 1.0, 0.0);
        glVertex3f(0.4, -1.0, 0.0);
        glVertex3f(0.6, 1.0, 0.0);
        glVertex3f(0.6, -1.0, 0.0);
        glVertex3f(0.8, 1.0, 0.0);
        glVertex3f(0.8, -1.0, 0.0);
        glVertex3f(-1.0, 0.2, 0.0);
        glVertex3f(1.0, 0.2, 0.0);
        glVertex3f(-1.0, 0.4, 0.0);
        glVertex3f(1.0, 0.4, 0.0);
        glVertex3f(1.0, 0.6, 0.0);
        glVertex3f(-1.0, 0.6, 0.0);
        glVertex3f(-1.0, 0.8, 0.0);
        glVertex3f(1.0, 0.8, 0.0);
        glVertex3f(-1.0, -0.2, 0.0);
        glVertex3f(1.0, -0.2, 0.0);
        glVertex3f(-1.0, -0.4, 0.0);
        glVertex3f(1.0, -0.4, 0.0);
        glVertex3f(-1.0, -0.6, 0.0);
        glVertex3f(1.0, -0.6, 0.0);
        glVertex3f(-1.0, 0.8, 0.0);
        glVertex3f(1.0, 0.8, 0.0);
        glEnd();
    glFlush();
}

void userDraw(void){
    /* for drawwing here :) */
    userDrawAbstract();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
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


