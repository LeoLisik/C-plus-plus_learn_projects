#include <glut.h>
#include <math.h>
#include <stdlib.h>

void Lines() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(300, 250);
    glVertex2f(350, 300);
    glVertex2f(325, 250);
    glVertex2f(325, 300);
    glVertex2f(300, 275);
    glVertex2f(350, 275);
    glVertex2f(350, 250);
    glVertex2f(300, 300);
    glEnd();
    glFlush();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Snow");
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(Lines);
    glutMainLoop();

    return 0;
}
/*int r, n = 5;
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
    glutCreateWindow("Кривая");
    Fract();
    glutDisplayFunc(Draw);
    glClearColor(0.82, 0.95, 0.98, 1.0);
    glutMainLoop();
}



#include <stdio.h>

#include <stdlib.h>

  //assign alternative names to existing types

 typedef GLfloat point2[2];

 int level;

 point2 a, b;

 int l, yv, k, t;

 int value;

  //initialization

 void myinit(void) {

      // set colour for window

         glClearColor(1.0, 1.0, 1.0, 1.0);

     // set colour for snowflake

         glColor3f(0.5, 0.6, 0.7);

      //load the matrix

         glMatrixMode(GL_PROJECTION);

     //load identity matrix

         glLoadIdentity();

      // set koordinates for painting

        gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glMatrixMode(GL_MODELVIEW);

    
}

  //find points and divide our length
 void paint(point2 a, point2 b, int level) {

     point2 p1, p2, p3, c1, c2, c3, a1, a2, a3;

     float dx, dy;

     dx = b[0] - a[0];

     dy = b[1] - a[1];

      //point p1

         p1[0] = a[0] + dx / 3;

     p1[1] = a[1] + dy / 3;

      //point p2

         p2[0] = a[0] + 2 * dx / 3;

     p2[1] = a[1] + 2 * dy / 3;

      //point p3

         p3[0] = -0.2886751f * dy + 0.5 * dx + a[0];

     p3[1] = 0.2886751f * dx + 0.5 * dy + a[1];

      //point c1

         c1[0] = a[0] + dx / 3;

     c1[1] = a[1] + dy / 3;

      //point c2

         c2[0] = a[0] + 2 * dx / 3;

     c2[1] = a[1] + 2 * dy / 3;

      //point c3

         c3[0] = -0.2886751f * dy + 0.5 * dx + a[0];

    c3[1] = 0.2886751f * dx + 0.5 * dy + a[1];

     dx = b[0] - a[0];

     dy = b[1] - a[1];

      //point a1

         a1[0] = a[0] + dx / 3;

     a1[1] = a[1] + dy / 3;

      //point a2

         a2[0] = a[0] + 2 * dx / 3;

    a2[1] = a[1] + 2 * dy / 3;

      //point a3

         a3[0] = -0.2886751f * dy + 0.5 * dx + a[0];

     a3[1] = 0.2886751f * dx + 0.5 * dy + a[1];

     if (level > 1)

         {

          // low interecion's number

         level --;

         paint(a, p1, level);

         paint(p1, p3, level);

         paint(p3, p2, level);

         paint(p2, b, level);

         paint(a, c1, level);

         paint(c1, c3, level);

         paint(c3, c2, level);

         paint(c2, b, level);

         paint(a, a1, level);

         paint(a1, a3, level);

         paint(a3, a2, level);

         paint(a2, b, level);

         }

    else if (level == 1) {

          //draw right triangle

             glBegin(GL_LINE_LOOP);

         glVertex2fv(a);

         glVertex2fv(p1);

         glVertex2fv(p1);

         glVertex2fv(p2);

         glVertex2fv(p2);

         glVertex2fv(p3);

         glVertex2fv(p3);

         glVertex2fv(b);

         glEnd();

         glBegin(GL_LINES);

        glVertex2fv(a);

         glVertex2fv(c1);

         glVertex2fv(c1);

         glVertex2fv(c2);

         glVertex2fv(c2);

         glVertex2fv(c3);

         glVertex2fv(c3);

         glVertex2fv(b);

         glEnd();

         glBegin(GL_LINES);

         glVertex2fv(a);

         glVertex2fv(a1);

         glVertex2fv(a1);

         glVertex2fv(a2);

         glVertex2fv(a2);

         glVertex2fv(a3);

         glVertex2fv(a3);

         glVertex2fv(b);

         glEnd();

        
    }

    
}

  // output on display

 void display(void) {

    //point's koordinates

        point2 p1 = { 50.0,600.0 }, p2 = { 75.0,665.0 }, p3 = { 105.0,600.0 };

     point2 a1 = { 105.0,740.0 }, a2 = { 150.0,770.0 }, a3 = { 200.0,740.0 };

    point2 c1 = { 335.0,670.0 }, c2 = { 395.0,710.0 }, c3 = { 400.0,670.0 };

    glClear(GL_COLOR_BUFFER_BIT);

    //push current matrix

        glPushMatrix();

      //translate on l parameter along y koordinates

        glTranslatef(1, -l, 1);

     paint(p1, p2, 5);

    paint(p2, p3, 5);

    paint(p3, p1, 5);

    //pop current matrix

        glPopMatrix();

     glPushMatrix();

    //translate k parameter along y koordinates

        glTranslatef(1, -k, 1);

     paint(c1, c2, 5);

    paint(c2, c3, 5);

    paint(c3, c1, 5);

    glPopMatrix();

    glPushMatrix();

    //translate t parameter along y koordinates

        glTranslatef(1, -t, 1);

     paint(a1, a2, 5);

    paint(a2, a3, 5);

    paint(a3, a1, 5);

    glPopMatrix();

    // change buffers

        glutSwapBuffers();

    
}

  // function timer fo animation

void timer(int value) {

    l = yv;

    // translate with step 3

        yv += 3;

     if (yv > 670) {

        yv -= 670;

        
    }

      // translate with step 1

        k += 1;

     if (k > 670) {

        k -= 670;

        
    };

      // translate with step 8

        t += 8;

     if (t > 670) {

        t -= 670;

        
    };

      //call function display after 30

        display();

      // call function timer

        glutTimerFunc(30, timer, value);

      //redrawing display

        glutPostRedisplay();

    
};

 int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(640, 480);

    glutInitWindowPosition(40, 30);

    glutCreateWindow("Koch Snowflake");

    glutDisplayFunc(display);

    glutTimerFunc(30, timer, value);

    myinit();

    glutMainLoop();

    return 0;

    
}*/