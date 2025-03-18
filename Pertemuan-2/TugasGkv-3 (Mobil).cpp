#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>

float mobilPosisiX = 0.0, mobilPosisiY = -0.35;
bool bergerak = false;
int arahX = 0, arahY = 0;
float kecepatan = 0.01;

void gambarLingkaran(float x, float y, float radius) {
    int jumlahSegmen = 20;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i = 0; i <= jumlahSegmen; i++) {
        float sudut = i * 2.0f * M_PI / jumlahSegmen;
        glVertex2f(x + (radius * cos(sudut)), y + (radius * sin(sudut)));
    }
    glEnd();
}

void gambarPegununganEs() {
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.9, 1.0);
    glVertex2f(-1.0, 1.0); glVertex2f(1.0, 1.0);
    glColor3f(0.8, 0.95, 1.0);
    glVertex2f(1.0, 0.1); glVertex2f(-1.0, 0.1);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.9, 0.95);
    glVertex2f(-0.9, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, 0.6);
    glColor3f(0.8, 0.9, 0.95);
    glVertex2f(-0.2, 0.1);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.75, 0.85, 0.9);
    glVertex2f(-0.3, 0.1);
    glColor3f(0.9, 0.95, 1.0);
    glVertex2f(0.2, 0.8);
    glColor3f(0.75, 0.85, 0.9);
    glVertex2f(0.6, 0.1);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.9, 0.95);
    glVertex2f(0.4, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.8, 0.5);
    glColor3f(0.8, 0.9, 0.95);
    glVertex2f(1.0, 0.1);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95);
    glVertex2f(-1.0, 0.1); glVertex2f(1.0, 0.1);
    glVertex2f(1.0, -0.2); glVertex2f(-1.0, -0.2);
    glEnd();
}

void gambarJalan() {
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.15, 0.15);
    glVertex2f(-1.0, -0.2); glVertex2f(1.0, -0.2);
    glVertex2f(1.0, -0.8); glVertex2f(-1.0, -0.8);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    for(float x = -0.9; x < 1.0; x += 0.3) {
        glVertex2f(x, -0.5); glVertex2f(x + 0.15, -0.5);
    }
    glEnd();
    
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.2); glVertex2f(1.0, -0.2);
    glVertex2f(-1.0, -0.8); glVertex2f(1.0, -0.8);
    glEnd();
}

void gambarMobil() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.1); glVertex2f(0.7, -0.1);
    glVertex2f(0.7, 0.1); glVertex2f(0.5, 0.1);
    glVertex2f(0.4, 0.3); glVertex2f(-0.4, 0.3);
    glVertex2f(-0.5, 0.1); glVertex2f(-0.7, 0.1);
    glEnd();
    
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.05);
    glVertex2f(-0.85, -0.05);
    glVertex2f(-0.85, 0.0);
    glVertex2f(-0.7, 0.0);
    glEnd();
    
    glColor3f(0.7, 0.7, 0.7);
    gambarLingkaran(-0.88, -0.025, 0.02);
    gambarLingkaran(-0.92, -0.025, 0.015);
    gambarLingkaran(-0.95, -0.025, 0.01);
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.45, 0.11); glVertex2f(0.37, 0.28);
    glVertex2f(-0.37, 0.28); glVertex2f(-0.45, 0.11);
    glEnd();
    
    glColor3f(0.7, 0.9, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.43, 0.13); glVertex2f(0.36, 0.26);
    glVertex2f(-0.36, 0.26); glVertex2f(-0.43, 0.13);
    glEnd();
    
    glColor3f(0.1, 0.1, 0.1);
    gambarLingkaran(0.4, -0.1, 0.15);
    gambarLingkaran(-0.4, -0.1, 0.15);
    
    glColor3f(0.7, 0.7, 0.7);
    gambarLingkaran(0.4, -0.1, 0.07);
    gambarLingkaran(-0.4, -0.1, 0.07);
    
    glColor3f(1.0, 1.0, 0.0);
    gambarLingkaran(0.69, 0.0, 0.05);
    
    glColor3f(1.0, 0.0, 0.0);
    gambarLingkaran(-0.69, 0.0, 0.05);
    
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, -0.1); glVertex2f(0.0, 0.11);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    gambarPegununganEs();
    gambarJalan();
    
    glPushMatrix();
    glTranslatef(mobilPosisiX, mobilPosisiY, 0.0);
    glScalef(0.7, 0.7, 1.0);
    gambarMobil();
    glPopMatrix();
    
   
    
    glutSwapBuffers();
}

void timer(int value) {
    if (bergerak) {
        if (arahX == -1 && mobilPosisiX > -0.9) mobilPosisiX -= kecepatan;
        else if (arahX == 1 && mobilPosisiX < 0.9) mobilPosisiX += kecepatan;
    
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0);
}

void specialKeys(int key, int x, int y) {
    bergerak = true;
    
    switch (key) {
        case GLUT_KEY_LEFT: arahX = -1; break;
        case GLUT_KEY_RIGHT: arahX = 1; break;
    }
}

void specialKeysUp(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT: arahX = 0; break;
        
    }
    
    if (arahX == 0) bergerak = false;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil");
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutSpecialUpFunc(specialKeysUp);
    glutTimerFunc(0, timer, 0);
    
    glutMainLoop();
    return 0;
}
