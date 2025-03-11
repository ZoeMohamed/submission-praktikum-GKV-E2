
#include <GL/glut.h>

void init() {
    // Mengatur warna background (hitam)
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void gambarPersegiGlow(float x, float y, float ukuran, float r, float g, float b) {
    glColor3f(r * 0.6, g * 0.6, b * 0.6);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.2, y - 0.2);                   // kiri bawah
    glVertex2f(x + ukuran + 0.2, y - 0.2);          // kanan bawah
    glVertex2f(x + ukuran + 0.2, y + ukuran + 0.2); // kanan atas
    glVertex2f(x - 0.2, y + ukuran + 0.2);          // kiri atas
    glEnd();
    
    // Persegi utama dengan warna cerah/neon
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);                       // kiri bawah
    glVertex2f(x + ukuran, y);              // kanan bawah
    glVertex2f(x + ukuran, y + ukuran);     // kanan atas
    glVertex2f(x, y + ukuran);              // kiri atas
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float ukuranPersegi = 2.0;  // Ukuran persegi
    
    // Tingkat 1 (paling atas) - 1 persegi
    gambarPersegiGlow(-1.0, 6.0, ukuranPersegi, 1.0, 1.0, 0.0);  
    
    // Tingkat 2 - 2 persegi
    gambarPersegiGlow(-3.0, 4.0, ukuranPersegi, 1.0, 0.2, 0.2);  
    gambarPersegiGlow(-1.0, 4.0, ukuranPersegi, 0.0, 1.0, 1.0);  
    
    // Tingkat 3 - 3 persegi
    gambarPersegiGlow(-5.0, 2.0, ukuranPersegi, 0.0, 1.0, 1.0);  
    gambarPersegiGlow(-3.0, 2.0, ukuranPersegi, 0.2, 1.0, 0.2);  
    gambarPersegiGlow(-1.0, 2.0, ukuranPersegi, 1.0, 0.2, 1.0);
    
    // Tingkat 4 - 4 persegi
    gambarPersegiGlow(-7.0, 0.0, ukuranPersegi, 0.2, 1.0, 0.2);  
    gambarPersegiGlow(-5.0, 0.0, ukuranPersegi, 0.2, 0.2, 1.0); 
    gambarPersegiGlow(-3.0, 0.0, ukuranPersegi, 1.0, 0.2, 1.0);  
    gambarPersegiGlow(-1.0, 0.0, ukuranPersegi, 1.0, 1.0, 0.0);  
    
    // Tingkat 5 (paling bawah) - 5 persegi
    gambarPersegiGlow(-9.0, -2.0, ukuranPersegi, 1.0, 1.0, 0.0); 
    gambarPersegiGlow(-7.0, -2.0, ukuranPersegi, 1.0, 1.0, 1.0);  
    gambarPersegiGlow(-5.0, -2.0, ukuranPersegi, 1.0, 0.2, 0.2); 
    gambarPersegiGlow(-3.0, -2.0, ukuranPersegi, 0.2, 0.2, 1.0);  
    gambarPersegiGlow(-1.0, -2.0, ukuranPersegi, 0.2, 1.0, 0.2);  
    
    glFlush();
}

// Fungsi main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Piramida Persegi");
    
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
