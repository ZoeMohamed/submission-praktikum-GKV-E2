#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535898

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 15.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;
int strafe = 0;

const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLUquadric* quad;

void Reshape(int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void moveMe(int direction, int sideways) {
    if (direction != 0) {
        x = x + direction * (lx) * 0.01;
        z = z + direction * (lz) * 0.01;
    }
    if (sideways != 0) {
        x = x + sideways * (lz) * 0.01;
        z = z - sideways * (lx) * 0.01;
    }
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    glColor3f(0.0, 0.0, 0.0); // Grid hitam
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Mobil() {
    // Body bawah mobil - biru tua
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.8f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(6.0f, 0.8f, 3.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Body atas mobil - biru muda
    glPushMatrix();
    glColor3f(0.3f, 0.5f, 1.0f);
    glTranslatef(0.0f, 1.5f, 0.0f);
    glScalef(4.0f, 1.0f, 2.0f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kaca depan
    glPushMatrix();
    glColor3f(0.8f, 0.9f, 1.0f);
    glTranslatef(1.5f, 1.5f, 0.0f);
    glRotatef(90, 0, 1, 0);
    glRotatef(45, 1, 0, 0);
    glScalef(2.5f, 1.5f, 0.1f);
    glutSolidCube(0.5);
    glPopMatrix();

    // Roda
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(2.5f, 0.4f, 1.5f);
    glutSolidTorus(0.2, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(-2.5f, 0.4f, 1.5f);
    glutSolidTorus(0.2, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(2.5f, 0.4f, -1.5f);
    glutSolidTorus(0.2, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(-2.5f, 0.4f, -1.5f);
    glutSolidTorus(0.2, 0.4, 20, 20);
    glPopMatrix();

    // Lampu depan
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(3.0f, 0.5f, 1.0f);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(3.0f, 0.5f, -1.0f);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();

    // Lampu belakang
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-3.0f, 0.5f, 1.2f);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-3.0f, 0.5f, -1.2f);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    // Knalpot
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glTranslatef(-3.0f, 0.3f, 0.0f);
    glRotatef(-90, 0, 1, 0);
    gluCylinder(quad, 0.1, 0.1, 0.5, 10, 10);
    glPopMatrix();
}

void display() {
    if (deltaMove || strafe)
        moveMe(deltaMove, strafe);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Grid();
    Mobil();
    glutSwapBuffers();
    glFlush();
}

void keyboardNormal(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': deltaMove = 1; break;
    case 's': deltaMove = -1; break;
    case 'a': strafe = 1; break;
    case 'd': strafe = -1; break;
    case 'q': deltaAngle = -0.001f; break;
    case 'e': deltaAngle = 0.001f; break;
    }
}

void keyboardNormalUp(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 's': deltaMove = 0; break;
    case 'a':
    case 'd': strafe = 0; break;
    case 'q':
    case 'e': deltaAngle = 0.0f; break;
    }
}

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - Warna Biru");

    quad = gluNewQuadric();

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboardNormal);
    glutKeyboardUpFunc(keyboardNormalUp);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);

    lighting();
    init();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background putih
    glutMainLoop();
    return 0;
}

