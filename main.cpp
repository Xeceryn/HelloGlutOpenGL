/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void drawDot(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void userDraw(void){
    /* for drawwing here :) */
    glPointSize(5);
    glColor3f(1, 0, 0);
    drawDot(200, 200);
    drawDot(220, 180);
    drawDot(220, 200);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
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


