#include <GL/glut.h>
#include <stdlib.h>

static void retangulo(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

static void triangulo(GLfloat x1, GLfloat y1,
                      GLfloat x2, GLfloat y2,
                      GLfloat x3, GLfloat y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

static void circulo(GLfloat cx, GLfloat cy, GLfloat raio) {
    GLUquadric *q = gluNewQuadric();
    glPushMatrix();
        glTranslatef(cx, cy, 0.0f);
        gluDisk(q, 0.0, raio, 40, 1);
    glPopMatrix();
    gluDeleteQuadric(q);
}

static void Terra(void) {
    glColor3f(0.16f, 0.72f, 0.28f);
    retangulo(-320.0f, -240.0f, 320.0f, -80.0f);
}

static void Casa(void) {
    glColor3f(0.10f, 0.63f, 0.86f);
    retangulo(110.0f, -80.0f, 250.0f, 75.0f);

    glColor3f(0.77f, 0.53f, 0.36f);
    triangulo(95.0f, 75.0f, 180.0f, 150.0f, 265.0f, 75.0f);

    glColor3f(0.72f, 0.50f, 0.34f);
    retangulo(165.0f, -80.0f, 195.0f, -5.0f);
}

static void Arvore(void) {
    glColor3f(0.72f, 0.50f, 0.34f);
    retangulo(-220.0f, -80.0f, -198.0f, 20.0f);

    glColor3f(0.15f, 0.74f, 0.24f);
    circulo(-238.0f, 18.0f, 22.0f);
    circulo(-209.0f, 42.0f, 24.0f);
    circulo(-180.0f, 18.0f, 22.0f);
    circulo(-209.0f, 18.0f, 24.0f);
}

static void Sol(void) {
    glColor3f(1.0f, 0.84f, 0.0f);
    circulo(-40.0f, 150.0f, 20.0f);

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-40.0f, 178.0f); glVertex2f(-40.0f, 205.0f);
        glVertex2f(-40.0f, 122.0f); glVertex2f(-40.0f, 95.0f);
        glVertex2f(-68.0f, 150.0f); glVertex2f(-95.0f, 150.0f);
        glVertex2f(-12.0f, 150.0f); glVertex2f(15.0f, 150.0f);

        glVertex2f(-60.0f, 170.0f); glVertex2f(-78.0f, 188.0f);
        glVertex2f(-20.0f, 170.0f); glVertex2f(-2.0f, 188.0f);
        glVertex2f(-60.0f, 130.0f); glVertex2f(-78.0f, 112.0f);
        glVertex2f(-20.0f, 130.0f); glVertex2f(-2.0f, 112.0f);
    glEnd();
}

static void Desenha(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Terra();
    Arvore();
    Casa();
    Sol();

    glFlush();
}

static void Altera(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        GLfloat fator = (GLfloat) h / (GLfloat) w;
        gluOrtho2D(-320.0, 320.0, -240.0 * fator, 240.0 * fator);
    } else {
        GLfloat fator = (GLfloat) w / (GLfloat) h;
        gluOrtho2D(-320.0 * fator, 320.0 * fator, -240.0, 240.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void Inicializa(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(350, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Pratica 1 - Cena 2D");

    Inicializa();

    glutDisplayFunc(Desenha);
    glutReshapeFunc(Altera);

    glutMainLoop();
    return 0;
}