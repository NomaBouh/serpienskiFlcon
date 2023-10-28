#include <GL/glut.h>

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth) {
    if (depth == 0) {
        drawTriangle(x1, y1, x2, y2, x3, y3);
        return;
    }
    float mx1 = (x1 + x2) / 2;
    float my1 = (y1 + y2) / 2;

    float mx2 = (x2 + x3) / 2;
    float my2 = (y2 + y3) / 2;

    float mx3 = (x1 + x3) / 2;
    float my3 = (y1 + y3) / 2;

    sierpinski(x1, y1, mx1, my1, mx3, my3, depth - 1);
    sierpinski(x2, y2, mx1, my1, mx2, my2, depth - 1);
    sierpinski(x3, y3, mx2, my2, mx3, my3, depth - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    sierpinski(0.0, 0.0, 1.0, 0.0, 0.5, 0.87, 9); // depth = 12 pour cet exemple
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flocon de Sierpinski");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
