/*
 * GLUT TV Rusak Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test TV Rusak in GLUT.
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

void userDrawDot(){
    glPointSize(5);
    glColor3f(0,0,0);
    drawDot(200, 200);
    drawDot(220, 180);
    drawDot(220, 200);
}

void userDrawTVRUsak(){
    float x, y;
    int i;
    for(int i=0; i<1000; i++){
        x=640*(float)rand()/RAND_MAX-320;
        y=480*(float)rand()/RAND_MAX-240;
        glColor3f(0,0,0);
        glPointSize(5);
        drawDot(x, y);
    }
}

void userDraw(void){
    /* for drawwing here :) */
    userDrawTVRUsak();
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
    glutCreateWindow("Draw TV Rusak :D");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}


