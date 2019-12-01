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
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

/* struck declare */

typedef struct {
    float x, y;
} point2D_t;

typedef struct {
    float r, g, b;
} color_t;

/* triangle declare */

point2D_t triangleHorizontal[3] = {{-310, 200}, {-310, 160}, {-260, 180}};
point2D_t triangleVertical[3] = {{-310, -200}, {-270, -200}, {-290, -170}};

/* circle declare */

point2D_t circleHorizontal[1] = {{-300, 100}};
point2D_t circleVertical[1] = {{-250, -200}};

/* star declare */

point2D_t starHorizontal[10] = {{-280, 80}, {-275, 70}, {-256, 70},
{-275, 65}, {-270, 55}, {-280, 60}, {-290, 55}, {-285, 65}, {-295, 70}, {-285, 70}};
point2D_t starVertical[10] = {{-180, -230}, {-175, -220}, {-165, -220},
{-175, -215}, {-170, -205}, {-180, -210}, {-190, -205}, {-185, -215}, {-195, -220}, {-185, -220}};

void setColor(color_t col) {
    glColor3f(col.r, col.g, col.b);
}

void drawPolyline(point2D_t pnt[], int n, color_t color) {
    int i;
    setColor(color);

    glBegin(GL_LINE_LOOP);
    for(i=0; i<n; i++) {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void drawCircle(point2D_t pnt[], int radio, color_t color) {
    int i;
    float theta;
    setColor(color);

    glBegin(GL_POLYGON);
    for(i=0; i<360; i++) {
        theta = i*3.1415/180;
        glVertex2f(pnt[0].x + radio*cos(theta), pnt[0].y + radio*sin(theta));
    }
    glEnd();
}

void triangle_hori() {
    int i;
    color_t col = {1.0, 0.0, 0.0};
    drawPolyline(triangleHorizontal, 3, col);

    for(i=0; i<3; i++) {
        triangleHorizontal[i].x += 5;
    }

    if(triangleHorizontal[0].x > 320) {

        triangleHorizontal[0].x = -310, 0;
        triangleHorizontal[1].x = -310, 0;
        triangleHorizontal[2].x = -260, 0;

        triangleHorizontal[0].y = 200, 0;
        triangleHorizontal[1].y = 160, 0;
        triangleHorizontal[2].y = 180, 0;
    }
}

void drawCircleHori() {
    color_t col = {0.0, 1.0, 0.0};
    drawCircle(circleHorizontal, 10, col);
    circleHorizontal[0].x += 4;

    if(circleHorizontal[0].x > 300) {
        circleHorizontal[0].x = -300;
        circleHorizontal[0].y = 100;
    }
}

void star_hori() {
    int i;
    color_t col = {0.0, 0.0, 1.0};
    drawPolyline(starHorizontal, 10, col);

    for(i=0; i<10; i++) {
        starHorizontal[i].x += 3;
    }

    if(starHorizontal[3].x > 320) {

        starHorizontal[0].x = -280, 0;
        starHorizontal[1].x = -275, 0;
        starHorizontal[2].x = -265, 0;
        starHorizontal[3].x = -275, 0;
        starHorizontal[4].x = -270, 0;
        starHorizontal[5].x = -280, 0;
        starHorizontal[6].x = -290, 0;
        starHorizontal[7].x = -285, 0;
        starHorizontal[8].x = -295, 0;
        starHorizontal[9].x = -285, 0;

        starHorizontal[0].y = 80, 0;
        starHorizontal[1].y = 70, 0;
        starHorizontal[2].y = 70, 0;
        starHorizontal[3].y = 65, 0;
        starHorizontal[4].y = 55, 0;
        starHorizontal[5].y = 60, 0;
        starHorizontal[6].y = 55, 0;
        starHorizontal[7].y = 65, 0;
        starHorizontal[8].y = 70, 0;
        starHorizontal[9].y = 70, 0;
    }
}

void triangle_verti() {
    int i;
    color_t col = {1.0, 0.0, 0.0};
    drawPolyline(triangleVertical, 3, col);

    for(i=0; i<3; i++) {
        triangleVertical[i].y += 5;
    }

    if(triangleVertical[2].y > 240) {

        triangleVertical[0].x = -310, 0;
        triangleVertical[1].x = -270, 0;
        triangleVertical[2].x = -290, 0;

        triangleVertical[0].y = -200, 0;
        triangleVertical[0].y = -200, 0;
        triangleVertical[0].y = -170, 0;
    }
}

void drawCircleVerti() {
    color_t col = {0.0, 1.0, 0.0};
    drawCircle(circleVertical, 20, col);
    circleVertical[0].y += 4;

    if(circleVertical[0].y > 280) {

        circleVertical[0].x = -250;
        circleVertical[0].y = -200;
    }
}

void star_verti() {
    int i;
    color_t col = {0.0, 0.0, 1.0};
    drawPolyline(starVertical, 10, col);

    for(i=0; i<10; i++) {
        starVertical[i].y += 3;
    }

    if(starVertical[3].y > 240) {

        starVertical[0].x = -180.0;
        starVertical[1].x = -175.0;
        starVertical[2].x = -165.0;
        starVertical[3].x = -175.0;
        starVertical[4].x = -170.0;
        starVertical[5].x = -180.0;
        starVertical[6].x = -190.0;
        starVertical[7].x = -185.0;
        starVertical[8].x = -195.0;
        starVertical[9].x = -185.0;

        starVertical[0].y = -230.0;
        starVertical[1].y = -220.0;
        starVertical[2].y = -220.0;
        starVertical[3].y = -210.0;
        starVertical[4].y = -205.0;
        starVertical[5].y = -210.0;
        starVertical[6].y = -205.0;
        starVertical[7].y = -215.0;
        starVertical[8].y = -220.0;
        starVertical[9].y = -220.0;
    }
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void userDraw() {
    glClearColor(0., 0., 0., 0.);

    triangle_hori();
    triangle_verti();

    star_hori();
    star_verti();

    drawCircleHori();
    drawCircleVerti();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    userDraw();
    glutSwapBuffers();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Created by Adhitya Musthofa 2103187091");

    glClearColor(0,0,0,0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);

    glutDisplayFunc(display);

    glutTimerFunc(10, timer, 0);

    glutMainLoop();

    return EXIT_SUCCESS;
}
