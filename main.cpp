/*
 * GLUT Shapes Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test kerucut.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

int w=400, h=400, z=0;
int x1=0, y1=0, sudut=0, z1=0;
void renderScene(void){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glClearColor(1,1,1,1);
 glLoadIdentity();
 glTranslatef(0,0,z);
 glRotatef(sudut,x1,y1,z1);
 glColor3f(1,0,0);
 glutWireCone(2,4,25,25);
 glutSwapBuffers();
}


void resize(int w1, int h1){
 glViewport(0,0,w1,h1);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}
void myKeyboard(unsigned char key, int x, int y){
 if (key =='a') z+=5;
 else if (key == 'd') z-=5;
 else if (key == 'x') {
  x1=1;
  y1=0;
  z1=0;
  sudut+=10;
 }
 else if (key == 'y') {
  y1=1;
  x1=0;
  z1=0;
  sudut+=-10;
 }
 else if (key == 'z') {
  y1=0;
  x1=0;
  z1=1;
  sudut+=-10;
 }
}
void init(){
 glClearColor(0,0,0,1);
 glEnable(GL_DEPTH_TEST);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0,(GLdouble) w/(GLdouble) h, 1.0,300.0);
 glMatrixMode(GL_MODELVIEW);
}
void timer(int value){
 glutPostRedisplay();
 glutTimerFunc(50,timer,0);
}
int main (int argc, char **argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(w,h);
 glutCreateWindow("Adhitya Musthofa 2103187091");
 gluOrtho2D(-w/2,w/2,-h/2,h/2);
 glutDisplayFunc(renderScene);
 glutReshapeFunc(resize);
 glutKeyboardFunc(myKeyboard);
 glutTimerFunc(1,timer,0);
 init();
 glutMainLoop();
}
