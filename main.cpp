/*
 * GLUT Shapes Demo
 *
 * Written by Adhitya MUsthofa December 2019
 *
 * 3D abjad S
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D1
glColor3f(1.0,0.0,1.0);glVertex2f(-4, 6.0);
glColor3f(1.0,0.0,1.0);glVertex2f(-4, -1);
glColor3f(1.0,0.0,1.0);glVertex2f(-3, -1);
glColor3f(1.0,0.0,1.0);glVertex2f(-3, 6.0);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D1 bayangan atas1
glColor3f(1.0,1.0,0.0);glVertex2f(-3.5, 6.5);
glColor3f(1.0,1.0,0.0);glVertex2f(-4, 6.0);
glColor3f(1.0,1.0,0.0);glVertex2f(-3, 6.0);
glColor3f(1.0,1.0,0.0);glVertex2f(-2.5, 6.5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D1 bayangan samping kanan1
glColor3f(0.0,1.0,1.0);glVertex2f(-3, 6);
glColor3f(0.0,1.0,1.0);glVertex2f(-3, -1);
glColor3f(0.0,1.0,1.0);glVertex2f(-2.5, -0.5);
glColor3f(0.0,1.0,1.0);glVertex2f(-2.5, 6.5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2
glColor3f(1.0,0.0,1.0);glVertex2f(-3, 6);
glColor3f(1.0,0.0,1.0);glVertex2f(-3, 5);
glColor3f(1.0,0.0,1.0);glVertex2f(2, 5);
glColor3f(1.0,0.0,1.0);glVertex2f(2, 6);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2 bayangan atas2
glColor3f(1.0,1.0,0.0);glVertex2f(-3, 6);
glColor3f(1.0,1.0,0.0);glVertex2f(2, 6);
glColor3f(1.0,1.0,0.0);glVertex2f(2.5, 6.5);
glColor3f(1.0,1.0,0.0);glVertex2f(-3, 6.5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2 bayangan samping kanan2
glColor3f(0.0,1.0,1.0);glVertex2f(2, 5);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, 5.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, 6.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2, 6);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2
glColor3f(1.0,0.0,1.0);glVertex2f(-3, 0);
glColor3f(1.0,0.0,1.0);glVertex2f(-3, -1);
glColor3f(1.0,0.0,1.0);glVertex2f(2, -1);
glColor3f(1.0,0.0,1.0);glVertex2f(2, 0);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2 bayangan atas2
glColor3f(1.0,1.0,0.0);glVertex2f(-3, 0);
glColor3f(1.0,1.0,0.0);glVertex2f(2, 0);
glColor3f(1.0,1.0,0.0);glVertex2f(2.5, 0.5);
glColor3f(1.0,1.0,0.0);glVertex2f(-3, 0.5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D2 bayangan samping kanan2
glColor3f(0.0,1.0,1.0);glVertex2f(2, -1);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, -0.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, 0.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2, 0);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D3
glColor3f(1.0,0.0,1.0);glVertex2f(-4, -5);
glColor3f(1.0,0.0,1.0);glVertex2f(-4, -6.5);
glColor3f(1.0,0.0,1.0);glVertex2f(2, -6.5);
glColor3f(1.0,0.0,1.0);glVertex2f(2, -5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D3 bayangan atas3
glColor3f(1.0,1.0,0.0);glVertex2f(-4, -5.5);
glColor3f(1.0,1.0,0.0);glVertex2f(2, -5.5);
glColor3f(1.0,1.0,0.0);glVertex2f(2.5, -5);
glColor3f(1.0,1.0,0.0);glVertex2f(-4, -5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D3 bayangan samping kanan3
glColor3f(0.0,1.0,1.0);glVertex2f(2, -6.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, -6);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, -5);
glColor3f(0.0,1.0,1.0);glVertex2f(2, -5.5);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D1
glColor3f(1.0,0.0,1.0);glVertex2f(2, -1.0);
glColor3f(1.0,0.0,1.0);glVertex2f(2, -6);
glColor3f(1.0,0.0,1.0);glVertex2f(1, -6);
glColor3f(1.0,0.0,1.0);glVertex2f(1, -1.0);
glEnd();

glTranslatef(0,0.0,0.0);
glBegin(GL_QUADS);//membuat D1 bayangan samping kanan1
glColor3f(0.0,1.0,1.0);glVertex2f(2, -1);
glColor3f(0.0,1.0,1.0);glVertex2f(2, -6);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, -5.5);
glColor3f(0.0,1.0,1.0);glVertex2f(2.5, -0.5);
glEnd();

glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y){
switch(key){
	case'w':
	case'W':
	glRotatef(3,1,0,0);//rotasi depan
	break;
	case'x':
	case'X':
	glRotatef(-3,1,0,0);//rotasi belakang
	break;
	case'a':
	case'A':
	glRotatef(3,0,1,0);//rotasi kenanan
	break;
	case'd':
	case'D':
	glRotatef(-3,0,1,0);//rotasi kekiri
	break;
	case'q':
	case'Q':
	glRotatef(3,0,0,1);//rotasi berputar ke arah kiri
	break;
	case'e':
	case'E':
	glRotatef(-3,0,0,1);//rotasi berputar ke arah kanan
	break;
	case'-':
	case'_':
	glScaled(0.2,0.2,0.0);//skala -
	break;
	case'=':
	case'+':
	glScaled(2,2,0);//skala +
	break;
	case'1':
	case'!':
	glTranslatef(-1.0f,0.0f,0.0f);//translasi ke kiri
	break;
	case'2':
	case'@':
	glTranslatef(1.0f,0.0f,0.0f);//translasi ke kanan
	break;
	case'3':
	case'#':
	glTranslatef(0.0f,1.0f,0.0f);//translasi ke atas
	break;
	case'4':
	case'$':
	glTranslatef(0.0f,-1.0f,0.0f);//translasi ke bawah
	break;
}
display();//repain windows
}
void catchMainMenu(int cmd)
{
	if(cmd==1)
	{
		exit(0);
	}
}

int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutInitWindowPosition(50, 50);
glutCreateWindow("Adhitya Musthofa 2103187091");
init();
glutCreateMenu(catchMainMenu);
glutAddMenuEntry("Out",1);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
int _tmain(int argc,_TCHAR* argv[]){
	return 0;
}
