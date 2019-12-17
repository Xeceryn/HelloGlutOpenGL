/*
 * GLUT HomeWork Animation 2D
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test animation 2D in GLUT.
 *
 */
#include<windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

typedef struct {
	float r, g, b;
} Color_t;

typedef struct {
	float x, y;
} Point2D_t;

typedef struct {
	float v[2];
} Vector2D_t;

typedef struct {
	float m[2][2];
} Matrix2D_t;

typedef struct {
	float m[3][3];
} Matrix3D_t;

typedef struct {
	float x, y, z;
} Point3D_t;

typedef struct {
	float v[3];
} Vector3D_t;

Matrix2D_t matrix2D;
Matrix3D_t matrixTranslasi2D;
Matrix3D_t matrix3DX, matrix3DY ,matrix3DZ;
Vector2D_t vec2D;
Vector3D_t vec3D;
Point2D_t segitiga[3]={{-310.0,-240.0},{-260.0,-240.0},{-285.0,-190.0}};
Point2D_t bintangRotasi[10]={{0,76},{19,20},{77,20},{30,-15},{48,-69},{0,-36},{-48,-69},{-26,-15},{-77,20},{-17,20}};
Point3D_t bintangRotasi2[10]={{0,76},{19,20},{77,20},{30,-15},{48,-69},{0,-36},{-48,-69},{-26,-15},{-77,20},{-17,20}};
Point2D_t jarum[2]={{0.0,0.0},{100.0,0.0}};
Point3D_t segiempatRotasi[4]={{-75.0,75.0,0.0},{75.0,75.0,0.0},{75.0,-75.0,0.0},{-75.0,-75.0,0.0}};
Point2D_t segiempatScale01[4]={{-15.0,15.0},{15.0,15.0},{15.0,-15.0},{-15.0,-15.0}};

float sudut = 2;
float sudut2 = 0.7;
float sudut3 = 1;

void setColor(Color_t col){
	glColor3f(col.r, col.g, col.b);
}

Matrix2D_t createIdentity2D(){
	Matrix2D_t rotate;
	rotate.m[0][0]=0.0;
	rotate.m[0][1]=0.0;
	rotate.m[1][0]=0.0;
	rotate.m[1][1]=0.0;
	return rotate;
}

Matrix2D_t rotation2D(float teta){
	Matrix2D_t rotate=createIdentity2D();
	rotate.m[0][0]=cos(teta/57.3);
	rotate.m[0][1]=-sin(teta/57.3);
	rotate.m[1][0]=sin(teta/57.3);
	rotate.m[1][1]=cos(teta/57.3);
	return rotate;
}

Matrix3D_t scale2D(float kx, float ky){
	Matrix3D_t rotate;
	rotate.m[0][0]=kx;
	rotate.m[0][1]=0;
	rotate.m[0][2]=0.0;
	rotate.m[1][0]=0.0;
	rotate.m[1][1]=ky;
	rotate.m[1][2]=0.0;
	rotate.m[2][0]=0.0;
	rotate.m[2][1]=0.0;
	rotate.m[2][2]=1.0;
	return rotate;
}

Matrix3D_t createIdentity(){
	Matrix3D_t rotate;
	rotate.m[0][0]=0.0;
	rotate.m[0][1]=0.0;
	rotate.m[0][2]=0.0;
	rotate.m[1][0]=0.0;
	rotate.m[1][1]=0.0;
	rotate.m[1][2]=0.0;
	rotate.m[2][0]=0.0;
	rotate.m[2][1]=0.0;
	rotate.m[2][1]=0.0;
	return rotate;
}

Matrix3D_t translation2D(float dx, float dy){
	Matrix3D_t translation=createIdentity();
	translation.m[0][0]=1.0;
	translation.m[0][1]=0.0;
	translation.m[0][2]=dx;
	translation.m[1][0]=0.0;
	translation.m[1][1]=1.0;
	translation.m[1][2]=dy;
	translation.m[2][0]=0.0;
	translation.m[2][1]=0.0;
	translation.m[2][2]=1;
	return translation;
}

Matrix3D_t rotationX(float teta){
	Matrix3D_t rotate=createIdentity();
	rotate.m[0][0]=1.0; rotate.m[0][1]=0.0;
	rotate.m[0][2]=0.0; rotate.m[1][0]=0.0;
	rotate.m[1][1]=cos(teta/57.3);
	rotate.m[1][2]=-sin(teta/57.3);
	rotate.m[2][0]=0.0;
	rotate.m[2][1]=sin(teta/57.3);
	rotate.m[2][2]=cos(teta/57.3);
	return rotate;
}

Matrix3D_t rotationY(float teta){
	Matrix3D_t rotate=createIdentity();
	rotate.m[0][0]=cos(teta/57.3);
	rotate.m[0][1]=0.0;
	rotate.m[0][2]=sin(teta/57.3);
	rotate.m[1][0]=0.0;
	rotate.m[1][1]=1.0;
	rotate.m[1][2]=0.0;
	rotate.m[2][0]=-sin(teta/57.3);
	rotate.m[2][1]=0.0;
	rotate.m[2][2]=cos(teta/57.3);
	return rotate;
}

Matrix3D_t rotationZ(float teta){
	Matrix3D_t rotate=createIdentity();
	rotate.m[0][0]=cos(teta/57.3);
	rotate.m[0][1]=-sin(teta/57.3);
	rotate.m[0][2]=0.0;
	rotate.m[1][0]=sin(teta/57.3);
	rotate.m[1][1]=cos(teta/57.3);
	rotate.m[1][2]=0.0;
	rotate.m[2][0]=0.0;
	rotate.m[2][1]=0.0;
	rotate.m[2][2]=1.0;
	return rotate;
}

//START SEGITIGA VERTIKAL
Vector3D_t Point2Vector2D(Point2D_t pnt){
	Vector3D_t vec;
	vec.v[0]=pnt.x;
	vec.v[1]=pnt.y;
	vec.v[2]=1;
	return vec;
}
void drawPolygon(Point2D_t pnt[],int n){
	int i;
	glBegin(GL_POLYGON);
	for (i=0;i<n;i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}
void segitiga_vertical(){
	drawPolygon(segitiga,3);
	for ( int i=0; i<3; i++) {
		segitiga[i].y+=5;
	}
	if (segitiga[0].y>240){
		segitiga[0].x=-300.0;
		segitiga[0].y=-240.0;
		segitiga[1].x=-250.0;
		segitiga[1].y=-240.0;
		segitiga[2].x=-275.0;
		segitiga[2].y=-190.0;
	}
}
void drawPolyline3D(Point3D_t pnt[], int n, Color_t color){
	int i;
	setColor(color);
	glBegin(GL_LINE_LOOP);
	for (i=0;i<n;i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}
Vector3D_t Point2Vector3D(Point3D_t pnt){
	Vector3D_t vec;
	vec.v[0]=pnt.x;
	vec.v[1]=pnt.y;
	vec.v[2]=1;
	return vec;
}
Point3D_t Vector2Point3D(Vector3D_t vec) {
	Point3D_t pnt;
	pnt.x=vec.v[1];
	pnt.y=vec.v[2];
}
Vector3D_t operator * (Matrix3D_t a, Vector3D_t b) {
	Vector3D_t c;//c=a*b
	int i,j;
	for (i=0;i<3;i++) {
		c.v[i]=0;
		for (j=0;j<3;j++)
			c.v[i]+=a.m[i][j]*b.v[j];
		}
	return c;
}
void segiempat_rotasi(){
	Color_t col={1.0,0.0,0.0};
	matrix3DZ=rotationZ(-sudut);
	drawPolyline3D(segiempatRotasi,4,col);
	for ( int i=0; i<4; i++){
		//1. Ubah point to vector untuk setiap titik
		vec3D=Point2Vector3D(segiempatRotasi[i]);
		//2. Kalikan Matrix Rotasi dengan vector titik
		vec3D=operator*(matrix3DZ, vec3D);
		//3. Ubah vector to point
		segiempatRotasi[i]=Vector2Point3D(vec3D);
	}
}
void bintang_rotasi2(){
	Color_t col={0.0,0.0,1.0};
	matrix3DZ=rotationZ(-sudut2);
	drawPolyline3D(bintangRotasi2,10,col);
	for ( int i=0; i<10; i++){
		//1. Ubah point to vector untuk setiap titik
		vec3D=Point2Vector3D(bintangRotasi2[i]);
		//2. Kalikan Matrix Rotasi dengan vector titik
		vec3D=operator*(matrix3DZ, vec3D);
		//3. Ubah vector to point
		bintangRotasi2[i]=Vector2Point3D(vec3D);
	}
}
void drawPolyline(Point2D_t pnt[], int n, Color_t color){
	int i;
	setColor(color);
	glBegin(GL_LINE_LOOP);
	for (i=0;i<n;i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}
Vector2D_t Point2Vector2DD(Point2D_t pnt) {
	Vector2D_t vec;
	vec.v[0]=pnt.x;
	vec.v[1]=pnt.y;
	vec.v[2]=1;
	return vec;
}
Vector2D_t KaliMatrix2D(Matrix2D_t a, Vector2D_t b) {
	Vector2D_t c;//c=a*b
	int i,j;
	for (i=0;i<3;i++) {
		c.v[i]=0;
		for (j=0;j<3;j++)
			c.v[i]+=a.m[i][j]*b.v[j];
		}
	return c;
}
Point2D_t Vector2Point2D(Vector2D_t vec) {
	Point2D_t pnt;
	pnt.x=vec.v[1];
	pnt.y=vec.v[2];
}
void bintang_rotasi(){
	Color_t col={0.0,1.0,0.0};
	matrix2D=rotation2D(sudut);
	drawPolyline(bintangRotasi,10,col);
	for ( int i=0; i<10; i++){
		//1. Ubah point to vector untuk setiap titik
		vec2D=Point2Vector2DD(bintangRotasi[i]);
		//2. Kalikan Matrix Rotasi dengan vector titik
		vec2D=KaliMatrix2D(matrix2D,vec2D);
		//3. Ubah vector to point
		bintangRotasi[i]=Vector2Point2D(vec2D);
	}
}
Point3D_t point3D={100.0,100.0,1.0};

void drawDot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void drawLine(Point2D_t pnt[], int n, Color_t color){
	int i;
	glBegin(GL_LINES);
	setColor(color);
	for (i=0;i<n;i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}
void titik_rotasi(){
	Color_t col={0.0,1.0,0.0};
	//matrix2D=rotation2D(sudut);
	matrix3DZ=rotationZ(sudut3);
	drawDot(point3D.x,point3D.y);
	drawLine(jarum,2,col);
		vec3D=Point2Vector3D(point3D);
		//vec3D=KaliMatrix2D(matrix2D,vec2D);
		vec3D=operator*(matrix3DZ, vec3D);
		point3D=Vector2Point3D(vec3D);
		jarum[1].x=point3D.x;
		jarum[1].y=point3D.y;
}


void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

void userdraw() {
	glClearColor(0.0, 0.0, 0.0,0.0);
	segitiga_vertical();
	segiempat_rotasi();
	//bintang_rotasi();
	bintang_rotasi2();
	titik_rotasi();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);

    glutCreateWindow("Adhitya Musthofa 2103187091");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();

}
