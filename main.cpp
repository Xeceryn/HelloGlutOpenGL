/*
 * GLUT Shapes Demo
 *
 * Written by Adhitya Musthofa December 2019
 *
 * This program is test Tabung.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static GLint fogMode;

/*  inisialisasi kedalaman buffer, fog, sumber cahaya, sifat-sifat bahan dan model pencahayaan */

static void init(void)
{


   glEnable(GL_FOG);
   {
      GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

      fogMode = GL_EXP;
      glFogi (GL_FOG_MODE, fogMode);
      glFogfv (GL_FOG_COLOR, fogColor);
      glFogf (GL_FOG_DENSITY, 0.40);
      glHint (GL_FOG_HINT, GL_DONT_CARE);
      glFogf (GL_FOG_START, 1.0);
      glFogf (GL_FOG_END, 5.0);
   }
   glClearColor(1.0, 1.0, 1.0, 1.0);  /* memberi warna kabut */
}

double rx = 1.0;
double ry = 1.0;
GLUquadricObj *qobj;

float l[] = { 45.0,  45.0, 45.0 }; // koordinat sumber cahaya
float n[] = { 0.0,  -1.0, 0.0 }; //menentukan vektor normal bidang
float e[] = { 50.0, -50.0, 50.0 }; //menentukan titik bidang

void help();

// obyek yang akan digambar
void draw()
{
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    gluCylinder(qobj, 15, 15, 50, 45, 50);
}

//membuat proyeksi bayangan
void glShadowProjection(float * l, float * e, float * n)
{
  float d, c;
  float mat[16];

  d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
  c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;

  mat[0]  = l[0]*n[0]+c;            // membuat matrik. OpenGL menggunakan kolom matrik
  mat[4]  = n[1]*l[0];
  mat[8]  = n[2]*l[0];
  mat[12] = -l[0]*c-l[0]*d;

  mat[1]  = n[0]*l[1];
  mat[5]  = l[1]*n[1]+c;
  mat[9]  = n[2]*l[1];
  mat[13] = -l[1]*c-l[1]*d;

  mat[2]  = n[0]*l[2];
  mat[6]  = n[1]*l[2];
  mat[10] = l[2]*n[2]+c;
  mat[14] = -l[2]*c-l[2]*d;

  mat[3]  = n[0];
  mat[7]  = n[1];
  mat[11] = n[2];
  mat[15] = -d;

  glMultMatrixf(mat);              // kalikan matrik
}

void render()
{
  glClearColor(0.5, 0.5, 1.0, 1.0); //warna background atas;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glLightfv(GL_LIGHT0, GL_POSITION, l);

  glDisable(GL_CULL_FACE);
  glDisable(GL_LIGHTING);

  //glColor3f(1.0,1.0,1.0);
  glBegin(GL_POINTS);
  glVertex3f(l[0],l[1],l[2]);
  glEnd();

  glColor3f(0.5, 1.0, 0.5); //mengatur warna background bawah;
  glBegin(GL_QUADS);
  glNormal3f(0.0,1.0,0.0);

  glVertex3f(-1300.0,e[1]-0.1, 1300.0);
  glVertex3f( 1300.0,e[1]-0.1, 1300.0);
  glVertex3f( 1300.0,e[1]-0.1,-1300.0);
  glVertex3f(-1300.0,e[1]-0.1,-1300.0);

  glEnd();

  // gambar bayangan
  glPushMatrix();
  glTranslatef(1.0, 0.0, 1.0);
  glRotatef(45, 45, 0, 0);
  glRotatef(45, 45, 0, 0);
  glEnable(GL_LIGHTING);
  glColor3f(1.0,0.0,0.0); //warna tabung
  draw();
  glPopMatrix();

  //sekarang  gambar bayangan yang muncul
  glPushMatrix();
  glShadowProjection(l,e,n);

  glRotatef(45, 45, 0, 0);
  glRotatef(45, 45, 0, 0);
  glDisable(GL_LIGHTING);
  glColor3f(0.2,0.2,0.2); //mengatur warna bayangan
  draw();
  glPopMatrix();

  glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'f':
      case 'F':
         if (fogMode == GL_EXP) {
        fogMode = GL_EXP2;
        printf ("Kabut dalam mode GL_EXP2\n");
         }
         else if (fogMode == GL_EXP2) {
            fogMode = GL_LINEAR;
            printf ("Kabut dalam mode GL_LINEAR\n");
         }
         else if (fogMode == GL_LINEAR) {
            fogMode = GL_EXP;
            printf ("Kabut dalam mode GL_EXP\n");
         }
         glFogi (GL_FOG_MODE, fogMode);
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

/*void keypress(unsigned char c, int a, int b)
{
  if ( c==27 ) exit(0);
  else if ( c=='s' ) l[1]-=5.0;
  else if ( c=='w' ) l[1]+=5.0;
  else if ( c=='a' ) l[0]-=5.0;
  else if ( c=='d' ) l[0]+=5.0;
  else if ( c=='q' ) l[2]-=5.0;
  else if ( c=='e' ) l[2]+=5.0;
  else if ( c=='?' ) help();
}
*/
void help()
{
  printf("==================================================    \n");
  printf("proyeksi contoh bayangan sebuah obyek tabung            \n");
  printf("----------------------------------------------------------------        \n");
  printf("s/w        memindahkan sumber cahaya naik/turun        \n");
  printf("a/d     memindahkan sumber cahaya kekanan/kekiri        \n");
  printf("q/e        memindahkan sumber cahaya kedepan atau kebelakang\n");
  printf("?              ini adalah contoh\n");
  printf("==================================================    \n");
}

void idle()
{
  rx+=0.5;
  ry+=0.5;
  render();
}

void resize(int w, int h)
{
  glViewport(0, 0, w, h);
}

int main(int argc, char * argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Adhitya Musthofa 2103187091");
  glutReshapeFunc(resize);
  glutReshapeWindow(620,480);
  //glutKeyboardFunc(keypress);
  glutDisplayFunc(render);
  glutIdleFunc(idle);
  glutKeyboardFunc (keyboard);


  glEnable(GL_NORMALIZE);
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);
  glEnable(GL_TEXTURE_2D);
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  gluPerspective(60.0f, 1.0, 2.0, 500.0);

  // Reset koordinat  sebelum dimodifikasi/diubah
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(1.0, 1.0, -150.0);

  glutMainLoop();
  return 0;
}
