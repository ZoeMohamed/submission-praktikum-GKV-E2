#include <GL/glut.h>

void init() {
    // Mengatur warna background (hitam)
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30.0, 30.0, -20.0, 20.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(2.0);
    
    // 1. GL_LINE_STRIP - Bintang 
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 0.0, 0.0); // Merah
        glVertex2f(-20.0, 10.0);  // Puncak
        
        glColor3f(0.0, 1.0, 0.0); // Hijau
        glVertex2f(-25.0, 0.0);   // Kiri
        
        glColor3f(0.0, 0.0, 1.0); // Biru
        glVertex2f(-20.0, 0.0);   // Tengah
        
        glColor3f(1.0, 1.0, 0.0); // Kuning
        glVertex2f(-15.0, 0.0);   // Kanan
        
        glColor3f(1.0, 0.0, 1.0); // Ungu
        glVertex2f(-20.0, 5.0);   // Atas tengah
        
        glColor3f(1.0, 0.0, 0.0); // Merah lagi
        glVertex2f(-20.0, 10.0);  // Kembali ke puncak
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-24.0, 12.0);
    
    // 2. GL_LINE_LOOP - Hexagon 
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0); // Merah
        glVertex2f(0.0, 10.0);    // Atas
        
        glColor3f(1.0, 0.5, 0.0); // Oranye
        glVertex2f(5.0, 7.0);     // Kanan atas
        
        glColor3f(1.0, 1.0, 0.0); // Kuning
        glVertex2f(5.0, 3.0);     // Kanan bawah
        
        glColor3f(0.0, 1.0, 0.0); // Hijau
        glVertex2f(0.0, 0.0);     // Bawah
        
        glColor3f(0.0, 0.0, 1.0); // Biru
        glVertex2f(-5.0, 3.0);    // Kiri bawah
        
        glColor3f(0.5, 0.0, 1.0); // Ungu
        glVertex2f(-5.0, 7.0);    // Kiri atas
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-4.0, 12.0);
    
    // 3. GL_TRIANGLE_FAN - Matahari 
    glBegin(GL_TRIANGLE_FAN);
        // Titik pusat
        glColor3f(1.0, 1.0, 0.0);  // Kuning
        glVertex2f(20.0, 5.0);     // Pusat
        
        glColor3f(1.0, 0.5, 0.0);  // Oranye kemerahan
        glVertex2f(20.0, 10.0);    // Atas
        glVertex2f(23.0, 9.0);     // Kanan atas
        glVertex2f(25.0, 5.0);     // Kanan
        glVertex2f(23.0, 1.0);     // Kanan bawah
        glVertex2f(20.0, 0.0);     // Bawah
        glVertex2f(17.0, 1.0);     // Kiri bawah
        glVertex2f(15.0, 5.0);     // Kiri
        glVertex2f(17.0, 9.0);     // Kiri atas
        glVertex2f(20.0, 10.0);    // Kembali ke atas
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(16.0, 12.0);
    
    // 4. GL_TRIANGLE_STRIP - Zigzag 
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0, 0.0, 0.0);  // Merah
        glVertex2f(-25.0, -5.0);   // Kiri atas
        
        glColor3f(0.0, 1.0, 0.0);  // Hijau
        glVertex2f(-25.0, -10.0);  // Kiri bawah
        
        glColor3f(0.0, 0.0, 1.0);  // Biru
        glVertex2f(-20.0, -3.0);   // Tengah atas 1
        
        glColor3f(1.0, 1.0, 0.0);  // Kuning
        glVertex2f(-20.0, -12.0);  // Tengah bawah 1
        
        glColor3f(1.0, 0.0, 1.0);  // Ungu
        glVertex2f(-15.0, -5.0);   // Tengah atas 2
        
        glColor3f(0.0, 1.0, 1.0);  // Cyan
        glVertex2f(-15.0, -10.0);  // Tengah bawah 2
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-24.0, -15.0);
    
    // 5. GL_QUADS - Kotak 
    glBegin(GL_QUADS);
        // Kotak 1
        glColor3f(1.0, 0.0, 0.0);  // Merah
        glVertex2f(-5.0, -5.0);    // Kiri atas
        
        glColor3f(0.0, 1.0, 0.0);  // Hijau
        glVertex2f(0.0, -5.0);     // Kanan atas
        
        glColor3f(0.0, 0.0, 1.0);  // Biru
        glVertex2f(0.0, -10.0);    // Kanan bawah
        
        glColor3f(1.0, 1.0, 0.0);  // Kuning
        glVertex2f(-5.0, -10.0);   // Kiri bawah
        
        // Kotak 2
        glColor3f(1.0, 0.0, 1.0);  // Ungu
        glVertex2f(0.0, -5.0);     // Kiri atas
        
        glColor3f(0.0, 1.0, 1.0);  // Cyan
        glVertex2f(5.0, -5.0);     // Kanan atas
        
        glColor3f(0.5, 0.5, 0.5);  // Abu-abu
        glVertex2f(5.0, -10.0);    // Kanan bawah
        
        glColor3f(1.0, 0.5, 0.0);  // Oranye
        glVertex2f(0.0, -10.0);    // Kiri bawah
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-2.0, -15.0);
    
    // 6. GL_QUAD_STRIP - Pita 
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0, 0.0, 0.0);  // Merah
        glVertex2f(15.0, -5.0);    // Kiri atas 1
        
        glColor3f(0.0, 1.0, 0.0);  // Hijau
        glVertex2f(15.0, -10.0);   // Kiri bawah 1
        
        glColor3f(0.0, 0.0, 1.0);  // Biru
        glVertex2f(20.0, -3.0);    // Tengah atas 1
        
        glColor3f(1.0, 1.0, 0.0);  // Kuning
        glVertex2f(20.0, -12.0);   // Tengah bawah 1
        
        glColor3f(1.0, 0.0, 1.0);  // Ungu
        glVertex2f(25.0, -5.0);    // Kanan atas 1
        
        glColor3f(0.0, 1.0, 1.0);  // Cyan
        glVertex2f(25.0, -10.0);   // Kanan bawah 1
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(17.0, -15.0);
    
    glColor3f(1.0, 1.0, 1.0);
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("6 Primitif OpenGL");
    
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
