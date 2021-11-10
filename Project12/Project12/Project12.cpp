#include "stdafx.h"
#include <glut.h>
#include <cmath>


int r, n = 5;
const int m = 16385; double knx[m], kny[m];
void Traf(double xA, double yA, double xB,
    double yB, int r)
{
    knx[r] = xA;   kny[r] = yA;
    knx[r + 1] = (2 * xA + xB) / 3; kny[r + 1] = (2 * yA + yB) / 3;
    knx[r + 2] = (xB + xA) / 2 + (yA - yB) / (2 * sqrt(3.0));
    kny[r + 2] = (yB + yA) / 2 + (xB - xA) / (2 * sqrt(3.0));
    knx[r + 3] = (xA + 2 * xB) / 3; kny[r + 3] = (yA + 2 * yB) / 3;
    knx[r + 4] = xB;   kny[r + 4] = yB;
}

void Fract()
{
    Traf(-1.0, 0.0, 1.0, 0.0, 0);
    for (int j = 0; j < n; j++)
    {
        double kn1x[m], kn1y[m]; r = pow(4.0, j + 1);
        for (int i = 0; i <= r; i++)
        {
            kn1x[i] = knx[i]; kn1y[i] = kny[i];
        }
        for (int i = 0; i < r; i++)
        {
            Traf(kn1x[i], kn1y[i], kn1x[i + 1], kn1y[i + 1], 4 * i);
        }
    }
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 0.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 4 * r; i++)
    {
        glVertex2d(knx[i], kny[i]);
        glVertex2d(knx[i + 1], kny[i + 1]);
    }
    glEnd();
    glFinish();
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Кривая Коха");
    Fract();
    glutDisplayFunc(Draw);
    glClearColor(0.82, 0.95, 0.98, 1.0);
    glutMainLoop();
}