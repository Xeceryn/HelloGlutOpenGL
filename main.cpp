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
#include <math.h>

typedef struct {float x; float y;} Point2D_t;
typedef struct {int x; int y;} Point2D_i;
typedef struct {float x, y, z;} Point3D_t;
typedef struct {float v[3];} Vector3D_t;
typedef struct {float m[3][3];} matrix3D_t;
typedef struct {int m[3][3];} matrix3D_i;
typedef struct {float r; float g; float b;} color_t;
typedef struct {
    int numofVertices;
    long int pnt[32];
} face_t;
typedef struct {
    int numofVertices;
    Point2D_t pnt[100];
    int numofFaces;
    face_t fc[32];
} object3D_t;

matrix3D_t createIdentity(){
    matrix3D_t rotate;
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

matrix3D_t rotationX(float teta){
    matrix3D_t rotate = createIdentity();
    rotate.m[0][0]=1.0;
    rotate.m[0][1]=0.0;
    rotate.m[0][2]=0.0;

    rotate.m[1][0]=0.0;
    rotate.m[1][1]=cos(teta/57.3);
    rotate.m[1][2]=-sin(teta/57.3);

    rotate.m[2][0]=0.0;
    rotate.m[2][1]=sin(teta/57.3);
    rotate.m[2][1]=cos(teta/57.3);
    return rotate;
}

matrix3D_t rotationY(float teta){
    matrix3D_t rotate = createIdentity();
    rotate.m[0][0]=cos(teta/57.3);
    rotate.m[0][1]=0.0;
    rotate.m[0][2]=-sin(teta/57.3);

    rotate.m[1][0]=0.0;
    rotate.m[1][1]=1.0;
    rotate.m[1][2]=0.0;

    rotate.m[2][0]=-sin(teta/57.3);
    rotate.m[2][1]=0.0;
    rotate.m[2][1]=cos(teta/57.3);
    return rotate;
}

matrix3D_t rotationZ(float teta){
    matrix3D_t rotate = createIdentity();
    rotate.m[0][0]=cos(teta/57.3);
    rotate.m[0][1]=-sin(teta/57.3);
    rotate.m[0][2]=0.0;

    rotate.m[1][0]=sin(teta/57.3);
    rotate.m[1][1]=cos(teta/57.3);
    rotate.m[1][2]=0.0;

    rotate.m[2][0]=0.0;
    rotate.m[2][1]=0.0;
    rotate.m[2][1]=1.0;
    return rotate;
}

Vector3D_t operator +(Vector3D_t a, Vector3D_t b){
    Vector3D_t c;
    for(int i=0; i<3; i++){
        c.v[i]=a.v[i]+b.v[i];
    }
    return c;
}

Vector3D_t operator -(Vector3D_t a, Vector3D_t b){
    Vector3D_t c;
    for(int i=0; i<3; i++){
        c.v[i]=a.v[i]-b.v[i];
    }
    return c;
}

Vector3D_t operator *(matrix3D_t a, Vector3D_t b){
    Vector3D_t c;
    for(int i=0; i<3; i++){
        c.v[i]=0;
        for(int j=0; j<3; j++){
            c.v[i]+=a.m[i][j]*b.v[j];
        }
    }
    return c;
}

void createKubus(Vector3D_t kubus[], int n){
    float z1=0.0;
    float z2=0.0;

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(-210.0, 0.0, 0.0);
        glVertex3f(210.0, 0.0, 0.0);
        glVertex3f(0.0, -210.0, 0.0);
        glVertex3f(0.0, 210.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(kubus[0].v[0], kubus[0].v[1], z1);
        glVertex3f(kubus[1].v[0], kubus[1].v[1], z2);
        glVertex3f(kubus[1].v[0], kubus[1].v[1], z1);
        glVertex3f(kubus[2].v[0], kubus[2].v[1], z2);
        glVertex3f(kubus[2].v[0], kubus[2].v[1], z1);
        glVertex3f(kubus[3].v[0], kubus[3].v[1], z2);
        glVertex3f(kubus[3].v[0], kubus[3].v[1], z1);
        glVertex3f(kubus[0].v[0], kubus[0].v[1], z2);
        glVertex3f(kubus[4].v[0], kubus[4].v[1], z1);
        glVertex3f(kubus[5].v[0], kubus[5].v[1], z2);
        glVertex3f(kubus[5].v[0], kubus[5].v[1], z1);
        glVertex3f(kubus[6].v[0], kubus[6].v[1], z2);
        glVertex3f(kubus[6].v[0], kubus[6].v[1], z1);
        glVertex3f(kubus[7].v[0], kubus[7].v[1], z2);
        glVertex3f(kubus[7].v[0], kubus[7].v[1], z1);
        glVertex3f(kubus[4].v[0], kubus[4].v[1], z2);
        glVertex3f(kubus[0].v[0], kubus[0].v[1], z1);
        glVertex3f(kubus[4].v[0], kubus[4].v[1], z2);
        glVertex3f(kubus[1].v[0], kubus[1].v[1], z1);
        glVertex3f(kubus[5].v[0], kubus[5].v[1], z2);
        glVertex3f(kubus[2].v[0], kubus[2].v[1], z1);
        glVertex3f(kubus[6].v[0], kubus[6].v[1], z2);
        glVertex3f(kubus[3].v[0], kubus[3].v[1], z1);
        glVertex3f(kubus[7].v[0], kubus[7].v[1], z2);
    glEnd();
}

void userDrawKubus(){
    int n=8;
    float sudut=0.0;
    Vector3D_t kubus[8]={
        {-50.0, 50.0, 50.0},
        {50.0, 50.0, 55.0},
        {50.0, -50.0, 50.0},
        {-50.0, -50.0, 50.0},
        {-25.0, 25.0, -50.0},
        {25.0, 25.0, -50.0},
        {25.0, -25.0, -50.0},
        {-25.0, -25.0, -50.0}
    };
    /*TODO: create rotate*/

    matrix3D_t matrix_X=rotationX(sudut);
    matrix3D_t matrix_Y=rotationY(sudut);
    matrix3D_t matrix_Z=rotationZ(sudut);

    for(int i=0; i<n; i++){
        kubus[i]=operator *(matrix_X, kubus[i]);
        kubus[i]=operator *(matrix_Y, kubus[i]);
        kubus[i]=operator *(matrix_Z, kubus[i]);
    }

    createKubus(kubus, 8);
    sudut++; if(sudut>=360) sudut=0.0;
    glFlush();
}

void userDraw(){
    /* user draw here */
    userDrawKubus();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Create Box");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(1, timer, 0);
    glutMainLoop();
    return 0;
}
