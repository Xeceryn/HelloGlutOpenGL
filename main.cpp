/*
 * GLUT HomeWork Animation 2D
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test animation 2D in GLUT.
 *
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point2D_t;

typedef struct {
    float r;
    float g;
    float b;
} color_t;

void setColor(color_t col){
    glColor3f(col.r, col.g, col.b);
}

int increment = 0;

point2D_t matahari[360];
point2D_t lintasanBumi[360];
point2D_t bumi[360];
point2D_t lintasanBulan[360];
point2D_t pusatBumi[1];
point2D_t titikBumi[360];
point2D_t titikBulan[360];
point2D_t bulan[360];

void drawLineLoop(point2D_t pnt[], int n){
    int i;
    glBegin(GL_LINE_LOOP);
    for (i=0;i<n;i++) {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void drawPolygon(point2D_t pnt[], int n){
    int i;
    glBegin(GL_POLYGON);
    for (i=0;i<n;i++) {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void drawLintasan(point2D_t pnt[], int R1, color_t color){
    setColor(color);
    for(int i=0; i<360; i++){
        pnt[i].x= (float) (R1 * cos(i*3.14/180) );
        pnt[i].y= (float) (R1 * sin(i*3.14/180) );
        drawLineLoop(pnt, 360);
    }
}

void drawLintasanBumi(){
    int R1 = 175;
    color_t color = {1.0,1.0,1.0};
    drawLintasan(lintasanBumi, R1, color);
}

void drawSegitiga(point2D_t pnt[], int n, color_t color){
    setColor(color);
    drawPolygon(pnt, n);
}

void drawCircle(point2D_t pnt[], int R1, color_t color){
    setColor(color);
    for(int i=0; i<360; i++){
        pnt[i].x= (float) (R1 * cos(i*3.14/180) );
        pnt[i].y= (float) (R1 * sin(i*3.14/180) );
    }
    drawPolygon(pnt, 360);
}

void drawMatahari(){
    int R1 = 50;
    color_t color = {0.0,1.0,0.0};
    drawCircle(matahari, R1, color);
    point2D_t segitiga1[3] = {{-15.0,55.0},{15.0,55.0},{0.0,90.0}};
    drawSegitiga(segitiga1, 3, color);
    point2D_t segitiga2[3] = {{55,15.0},{55.0,-15.0},{90.0,0.0}};
    drawSegitiga(segitiga2, 3, color);
    point2D_t segitiga3[3] = {{15.0,-55.0},{-15.0,-55.0},{0.0,-90.0}};
    drawSegitiga(segitiga3, 3, color);
    point2D_t segitiga4[3] = {{-55,-15.0},{-55.0,15.0},{-90.0,0.0}};
    drawSegitiga(segitiga4, 3, color);
    point2D_t segitiga5[3] = {{30.0,50.0},{65.0,65.0},{50.0,30.0}};
    drawSegitiga(segitiga5, 3, color);
    point2D_t segitiga6[3] = {{30.0,-50.0},{65.0,-65.0},{50.0,-30.0}};
    drawSegitiga(segitiga6, 3, color);
    point2D_t segitiga7[3] = {{-30.0,-50.0},{-65.0,-65.0},{-50.0,-30.0}};
    drawSegitiga(segitiga7, 3, color);
    point2D_t segitiga8[3] = {{-30.0,50.0},{-65.0,65.0},{-50.0,30.0}};
    drawSegitiga(segitiga8, 3, color);
}

int increment2 = 0;

void drawBumi(){
    titikBumi[increment].x = (float) (175 * cos(increment*3.14/180) );
    titikBumi[increment].y = (float) (175 * sin(increment*3.14/180) );
    color_t color = {1.0,0.0,1.0};
    setColor(color);
    int R = 30;
    for ( int i=0; i<360; i++){
         bumi[i].x=titikBumi[increment].x + (float) (R * cos(i*3.14/180) );
         bumi[i].y=titikBumi[increment].y + (float) (R * sin(i*3.14/180) );
    }
    drawPolygon(bumi, 360);
    color_t colorLintasanBulan = {1.0,1.0,1.0};
    setColor(colorLintasanBulan);
    for ( int i=0; i<360; i++){
         lintasanBulan[i].x=titikBumi[increment].x + (float) (50 * cos(i*3.14/180) );
         lintasanBulan[i].y=titikBumi[increment].y + (float) (50 * sin(i*3.14/180) );
    }
    drawLineLoop(lintasanBulan, 360);
    titikBulan[increment].x =lintasanBulan[increment2].x + (float) (cos(increment*3.14/180) );
    titikBulan[increment].y =lintasanBulan[increment2].y + (float) (sin(increment*3.14/180) );
    color_t colorBulan = {0.75,0.75,0.75};
    setColor(colorBulan);
    for ( int i=0; i<360; i++){
         bulan[i].x=titikBulan[increment].x + (float) (10 * cos(i*3.14/180) );
         bulan[i].y=titikBulan[increment].y + (float) (10 * sin(i*3.14/180) );
    }
    drawPolygon(bulan, 360);
    if(increment == 360){
        increment = 0;
    }else{
        increment++;
    }
    if(increment2 == 360){
        increment2 = 0;
    }else{
        increment2+=2;
    }
}

void userdraw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    drawMatahari();
    drawLintasanBumi();
    drawBumi();
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow ("Adhitya Musthofa 2103187091");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(-320., 320., -240.0, 240.0);
	glutDisplayFunc(display);
	glutTimerFunc(1,timer,0);
	glutMainLoop();
	return 0;
}
