#include <GL/glut.h>
#include <stdlib.h>

// Sudut-sudut sendi
static int shoulder = 0, elbow = 0, wrist = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0, thumb = 0;
static int fingerBase = 0, fingerUp = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(float xPos, float yPos, float zPos, int baseAngle, int upAngle) {
    // Menggambar setiap jari sebagai dua segmen dengan sendi
    glPushMatrix();
        // Posisikan jari pada telapak tangan
        glTranslatef(xPos, yPos, zPos);
        
        // Segmen dasar jari
        glRotatef((GLfloat) baseAngle, 0.0, 0.0, 1.0);
        glPushMatrix();
            glScalef(0.4, 0.1, 0.1);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Pindah ke sendi antara segmen
        glTranslatef(0.2, 0.0, 0.0);
        
        // Segmen atas jari
        glRotatef((GLfloat) upAngle, 0.0, 0.0, 1.0);
        glPushMatrix();
            glTranslatef(0.2, 0.0, 0.0);
            glScalef(0.4, 0.1, 0.1);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
        // Posisi awal lengan
        glTranslatef(-1.0, 0.0, 0.0);
        
        // Sendi bahu
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        
        // Lengan atas
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Pindah ke siku
        glTranslatef(1.0, 0.0, 0.0);
        
        // Sendi siku
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        
        // Lengan bawah
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Pindah ke pergelangan tangan
        glTranslatef(1.0, 0.0, 0.0);
        
        // Sendi pergelangan tangan
        glRotatef((GLfloat) wrist, 0.0, 0.0, 1.0);
        
        // Telapak tangan
        glPushMatrix();
            glTranslatef(0.4, 0.0, 0.0);
            glScalef(0.8, 0.5, 0.3);
            glutWireCube(1.0);
        glPopMatrix();
        
        // Menggambar semua jari dari telapak tangan
        
        // Jari tengah
        drawFinger(0.8, 0.0, 0.0, fingerBase + finger3, fingerUp + finger3);
        
        // Jari telunjuk
        drawFinger(0.8, 0.15, 0.0, fingerBase + finger2, fingerUp + finger2);
        
        // Jari manis
        drawFinger(0.8, -0.15, 0.0, fingerBase + finger4, fingerUp + finger4);
        
        // Jari kelingking
        drawFinger(0.8, -0.25, 0.0, fingerBase + finger1, fingerUp + finger1);
        
        // Ibu jari (pada sudut tertentu)
        glPushMatrix();
            glTranslatef(0.4, 0.3, 0.0);
            glRotatef(-45.0, 0.0, 0.0, 1.0);
            glRotatef((GLfloat) thumb, 0.0, 0.0, 1.0);
            
            glPushMatrix();
                glScalef(0.4, 0.1, 0.1);
                glutWireCube(1.0);
            glPopMatrix();
            
            // Sendi kedua ibu jari
            glTranslatef(0.2, 0.0, 0.0);
            glRotatef((GLfloat) thumb/2, 0.0, 0.0, 1.0);
            
            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0);
                glScalef(0.4, 0.1, 0.1);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();
        
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -8.0); // Mundur lebih jauh untuk melihat lengan dan tangan secara penuh
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Kontrol bahu - sama seperti sebelumnya
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        
        // Kontrol siku - sama seperti sebelumnya
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        
        // Kontrol pergelangan tangan - baru
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        
        // Semua jari bersama-sama menekuk pada sendi dasar
        case 'f': fingerBase = (fingerBase + 5) % 90; break;
        case 'F': fingerBase = (fingerBase - 5) % 90; break;
        
        // Semua jari bersama-sama menekuk pada sendi kedua
        case 'g': fingerUp = (fingerUp + 5) % 90; break;
        case 'G': fingerUp = (fingerUp - 5) % 90; break;
        
        // Kontrol jari individu (1-4 dan 't' untuk ibu jari)
        case '1': finger1 = (finger1 + 5) % 90; break;
        case '!': finger1 = (finger1 - 5) % 90; break;
        
        case '2': finger2 = (finger2 + 5) % 90; break;
        case '@': finger2 = (finger2 - 5) % 90; break;
        
        case '3': finger3 = (finger3 + 5) % 90; break;
        case '#': finger3 = (finger3 - 5) % 90; break;
        
        case '4': finger4 = (finger4 + 5) % 90; break;
        case '$': finger4 = (finger4 - 5) % 90; break;
        
        case 't': thumb = (thumb + 5) % 90; break;
        case 'T': thumb = (thumb - 5) % 90; break;
        
        // Keluar
        case 27: exit(0); break;
        
        default: break;
    }
    
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Proyeksi Tangan dengan jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
