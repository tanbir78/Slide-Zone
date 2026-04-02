#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r)
{
    int i;
    float angle;

    glBegin(GL_POLYGON);
    for(i = 0; i < 100; i++)
    {
        angle = 2 * 3.1416 * i / 100;
        glVertex2f(cx + cos(angle)*r, cy + sin(angle)*r);
    }
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);
    drawCircle(1.7, 1.7, 0.2);

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(0.8, 0.8);
    glVertex2f(1.5, 0.8);
    glEnd();

    glutSwapBuffers();
}
void init(void)
{
    glClearColor(0,0,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0,2,0,2,-1,1);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HELLOW");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
