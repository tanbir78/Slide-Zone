#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r)
{
    int i;
    float angle;

    glBegin(GL_POLYGON);
    for (i = 0; i < 100; i++)
    {
        angle = 2 * 3.1416 * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
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
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 2, 0, 2, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HELLOW");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

/*

#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
int xs, ys, xe, ye;
void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void Bresenham(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int x = x0;
    int y = y0;
    if (dx >= 0 && dy >= 0 && dy <= dx)
    {
        cout << "Case 1: Gentle Positive";
        int p = 2*dy - dx;
        while (x <= x1)
        {
            drawPixel(x, y);
            if (p < 0)
                p += 2*dy;
            else
            {
                y++;
                p += 2*(dy - dx);
            }
            x++;
        }
    }
    else if (dx >= 0 && dy >= 0 && dy > dx)
    {
        cout << "Case 2: Steep Positive";
        int p = 2*dx - dy;
        while (y <= y1)
        {
            drawPixel(x, y);
            if (p < 0)
                p += 2*dx;
            else
            {
                x++;
                p += 2*(dx - dy);
            }
            y++;
        }
    }
    else if (dx >= 0 && dy < 0 && abs(dy) <= dx)
    {
        cout << "Case 3: Gentle Negative";
        dy = abs(dy);
        int p = 2*dy - dx;
        while (x <= x1)
        {
            drawPixel(x, y);

            if (p < 0)
                p += 2*dy;
            else
            {
                y--;
                p += 2*(dy - dx);
            }
            x++;
        }
    }
    else if (dx >= 0 && dy < 0 && abs(dy) > dx)
    {
        cout << "Case 4: Steep Negative";
        dy = abs(dy);
        int p = 2*dx - dy;
        while (y >= y1)
        {
            drawPixel(x, y);
            if (p < 0)
                p += 2*dx;
            else
            {
                x++;
                p += 2*(dx - dy);
            }
            y--;
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(.0, 1.5, 0.0);
    Bresenham(xs, ys, xe, ye);
    glFlush();
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(3.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 300, 0, 300);
}
int main(int argc, char** argv)
{
    cout << "Enter x0 y0: ";
    cin >> xs >> ys;
    cout << "Enter x1 y1: ";
    cin >> xe >> ye;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bresenham Line A");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}





#include <windows.h>
#ifdef APPLE
#else
#include <GL/gl.h>
#endif
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
float p = -10.0;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (p <= 10)      // moving limit with the display measurement
        p = p + .005; // changing the object position for redisplaying
    else
        p = -10; // For backing the object continuously

    glutPostRedisplay(); // To redraw the object in the display
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p, 3); // To draw the object position from the left limit,p
    glVertex2f(p + 3, 3);
    glVertex2f(p + 3, -3);
    glVertex2f(p, -3);
    glEnd();

    glFlush();
}
void init(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glOrtho(-10, 10, -10, 10, -10, 10);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("moving_object");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}




#include <GL/glut.h>
#include <cmath>
int xc = 0, yc = 0, r = 100;
void plot(int x, int y)
{
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}
void midpointCircle()
{
    int x = 0;
    int y = r;
    int p = 1 - r;
    glBegin(GL_POINTS);
    while (x <= y)
    {
        plot(x, y);
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.1, 1.0);
    midpointCircle();
    glFlush();
}
void init()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Midpoint Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}




#include <GL/glut.h>
#include <stdio.h>
float x1 = 50, y1 = 50;
float x2 = 150, y2 = 50;
float x3 = 100, y3 = 150;
float tx, ty;
float tx1, ty1, tx2, ty2, tx3, ty3;
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,400.0,0.0,400.0,-1.0,1.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Original Triangle
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
    //Translated Triangle
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(tx1,ty1);
        glVertex2f(tx2,ty2);
        glVertex2f(tx3,ty3);
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    printf("factor X-axis (tx): ");
    scanf("%f",&tx);
    printf("factor Y-axis (ty): ");
    scanf("%f",&ty);
    tx1 = x1 + tx;
    ty1 = y1 + ty;
    tx2 = x2 + tx;
    ty2 = y2 + ty;
    tx3 = x3 + tx;
    ty3 = y3 + ty;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("2D Translation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}





#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

// Original coordinates
float x1 = 50, y1 = 50;
float x2 = 150, y2 = 50;
float x3 = 100, y3 = 150;

// Scaling factors
float sx, sy;

// Scaled coordinates
float sx1, sy1, sx2, sy2, sx3, sy3;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400.0, 0.0, 400.0, -1.0, 1.0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Original Triangle (Blue)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    // Draw Scaled Triangle (white)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(sx1, sy1);
    glVertex2f(sx2, sy2);
    glVertex2f(sx3, sy3);
    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    printf("Enter scaling factor along X-axis (sx): ");
    scanf("%f", &sx);

    printf("Enter scaling factor along Y-axis (sy): ");
    scanf("%f", &sy);

    // Apply Scaling Transformation
    sx1 = sx * x1;
    sy1 = sy * y1;

    sx2 = sx * x2;
    sy2 = sy * y2;

    sx3 = sx * x3;
    sy3 = sy * y3;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Scaling Transformation");

    init();
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}






*/
