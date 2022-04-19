#include <windows.h>
#include <GL/glut.h>
#include<Gl/gl.h>
#include <iostream>
#include<stdlib.h>
#include<math.h>
//#define PI   3.14159265358979323846
const double PI = 2.0 * acos(0.0);



using namespace std;

GLfloat boatPosition = 0.0f,carPosition = 0.0f,carPosition1 = 0.0f,railPosition=0.0f,rotatei=-10.0f,rotatei1=0.0f,sunPosition=0.0f,moonPosition=0.0f,positionRain = 0.0f;
GLfloat boatSpeed= 0.0f,carSpeed= 0.0f,carSpeed1= 0.0f,railSpeed=0.0f,sunSpeed=0.0005f,moonSpeed=0.0f,rainSpeed=0.01;
double rainX = -1.0,rainY;
static GLint f1=0,f2=0,f3=0,f4=0;
bool rt = true,rainday=false,night=false;

void update(int value)
{
    if (boatPosition < -1.1)
        boatPosition = 1.0f;
    else if (boatPosition > 1.0)
        boatPosition = -1.0f;

    if (carPosition < -0.2)
        carPosition = 1.98f;
    else if (carPosition > 1.98)
        carPosition = -0.2f;

    if (carPosition1 < -1.5)
        carPosition1 = 1.0f;

    if (railPosition < -1.9)
        railPosition = 0.7;
    else if (railPosition > 1.98)
        railPosition = -1.0f;

    if (sunPosition < -1.0)
    {
        sunPosition=-1.0;
        night=true;
    }

    if (moonPosition > 0.8)
        moonPosition=0.8;

    if (positionRain < -0.5)
        positionRain=0.0;

    boatPosition -=boatSpeed;
    carPosition -=carSpeed;
    carPosition1 -=carSpeed1;
    railPosition-=railSpeed;
    sunPosition-=sunSpeed;
    moonPosition-=moonSpeed;
    positionRain-=rainSpeed;
    glutPostRedisplay();
    glutTimerFunc(100, update,0);
}

void stop()
{
    carSpeed = 0.0f;
    carSpeed1 = 0.0f;
    boatSpeed = 0.0f;
    railSpeed = 0.0f;
}

void circle(GLfloat x, GLfloat y, GLfloat r)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x+(r*cos(i * twicePi / triangleAmount)),
            y+(r*sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void river()
{

    glBegin(GL_QUADS);
    glColor3ub	(30,144,255);
    //between river and road
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-1.0f, -0.95f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.0f, -0.70f);
    //river with sky blue colour
    glColor3ub	(240,230,140);
    glVertex2f(-1.0f, -0.70f);
    glVertex2f(-1.0f, -0.65f);
    glVertex2f(1.0f, -0.65f);
    glVertex2f(1.0f, -0.70f);

    glFlush();
    glEnd();
}

void field()
{

    glBegin(GL_QUADS);
    glColor3ub	(205,133,63);
    //field after road
    glVertex3f(-1.0f, -0.25f,0.0f);
    glVertex3f(-1.0f, -0.45f,0.0f);
    glVertex3f(1.0f, -0.45f,0.0f);
    glVertex3f(1.0f, -0.25f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub	(205,133,63);
    glVertex3f(-1.0f, -0.20f,0.0f);
    glVertex3f(-1.0f, -0.02f,0.0f);
    glVertex3f(1.0f, -0.02f,0.0f);
    glVertex3f(1.0f, -0.20f,0.0f);
    glEnd();

}

void hill()
{
    glBegin(GL_QUADS);
    if (night==true)
    {
        glColor3ub(10, 41, 14);
    }
    else
        glColor3ub(3, 99, 17);
    //glColor3ub(3, 99, 17);
    glVertex2f(1.0f, 0.20f);
    glVertex2f(1.0f, -0.02f);
    glVertex2f(-1.0f, -0.02f);
    glVertex2f(-1.0f, 0.20f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, 0.20f);
    glVertex2f(-0.885f, 0.33f);
    glVertex2f(-0.75f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.71f, 0.20f);
    glVertex2f(-0.55, 0.38f);
    glVertex2f(-0.40f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.55f, 0.20f);
    glVertex2f(-0.32f, 0.37f);
    glVertex2f(-0.27f, 0.35f);
    glVertex2f(-0.15f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.13f, 0.20f);
    glVertex2f(0.0f, 0.37f);
    glVertex2f(0.12f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.15f, 0.20f);
    glVertex2f(0.28f, 0.39f);
    glVertex2f(0.38f, 0.20f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.28f, 0.20f);
    glVertex2f(0.46f, 0.39f);
    glVertex2f(0.49f, 0.37f);
    glVertex2f(0.60f, 0.20f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.53f, 0.20f);
    glVertex2f(0.68f, 0.36f);
    glVertex2f(0.80f, 0.20f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.78f, 0.20f);
    glVertex2f(0.90f, 0.38f);
    glVertex2f(1.0f, 0.20f);
    glEnd();

}

void building()
{
    glBegin(GL_QUADS);
    glColor3ub	(0,0,255);

    //1st building blue color

    glVertex3f(-.60f, -0.10f,0.0f);
    glVertex3f(-.60f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.10f,0.0f);

    //2nd tall building
    glColor3ub	(135,206,235);
    glVertex3f(-.45f, -0.05f,0.0f);
    glVertex3f(-.45f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.40f,0.0f);
    glVertex3f(-.40f, -0.05f,0.0f);
    glEnd();

    glBegin(GL_QUADS);

    //red shades window in 1st building
    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.13f,0.0f);
    glVertex3f(-0.60f, -0.15f,0.0f);
    glVertex3f(-0.45f, -0.15f,0.0f);
    glVertex3f(-0.45f, -0.13f,0.0f);

    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.20f,0.0f);
    glVertex3f(-0.60f, -0.22f,0.0f);
    glVertex3f(-0.45f, -0.22f,0.0f);
    glVertex3f(-0.45f, -0.20f,0.0f);

    glColor3ub	(255,0,0);
    glVertex3f(-0.60f, -0.27f,0.0f);
    glVertex3f(-0.60f, -0.29f,0.0f);
    glVertex3f(-0.45f, -0.29f,0.0f);
    glVertex3f(-0.45f, -0.27f,0.0f);
    glEnd();
}

void grass()
{
    glBegin(GL_QUADS);
    glColor3ub		(34,139,34);
    // grass field
    glVertex3f(-1.0f, -0.20f,0.0f);
    glVertex3f(-1.0f, -0.25f,0.0f);
    glVertex3f(1.0f, -0.25f,0.0f);
    glVertex3f(1.0f, -0.20f,0.0f);
    glEnd();


}
void Sky(void)
{

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(5, 245, 237);


    glBegin(GL_QUADS);
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0, 0.8);
    glVertex2f(1.0, 0.8);
    glVertex2f(1.0, 1.0);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(81, 245, 239);


    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.8);
    glVertex2f(-1.0, 0.6);
    glVertex2f(1.0, 0.6);
    glVertex2f(1.0, 0.8);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(131, 242, 238);

    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.6);
    glVertex2f(-1.0, 0.4);
    glVertex2f(1.0, 0.4);
    glVertex2f(1.0, 0.6);
    glEnd();

    if (night==true)
    {
        glColor3ub(3, 135, 138);
    }
    else
        glColor3ub(167, 242, 240);

    glBegin(GL_QUADS);
    glVertex2f(-1.0, 0.4);
    glVertex2f(-1.0, 0.2);
    glVertex2f(1.0, 0.2);
    glVertex2f(1.0, 0.4);
    glEnd();

}

void clouds()
{
    glColor3ub(204, 219, 219);
    circle(-0.45f,0.85f,0.1f);
    circle(-0.61f,0.85f,0.15f);
    circle(-0.71f,0.85f,0.13f);
    circle(-0.82f,0.85f,0.1f);

    circle(0.54f,0.85f,0.1f);
    circle(0.64f,0.85f,0.15f);
    circle(0.75,0.85f,0.13f);
}


void car()
{
    glPushMatrix();
    glTranslatef(carPosition, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(3, 98, 252);
    glVertex2f(-0.90f, -0.40f);
    glVertex2f(-0.95f, -0.45f);
    glVertex2f(-0.95f, -0.50f);
    glVertex2f(-0.75f, -0.50f);
    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.80f, -0.40f);
    glVertex2f(-0.90f, -0.40f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(-0.89f, -0.41f);
    glVertex2f(-0.94f, -0.45f);
    glVertex2f(-0.86f, -0.45f);
    glVertex2f(-0.86f, -0.41f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(-0.84f, -0.41f);
    glVertex2f(-0.84f, -0.45f);
    glVertex2f(-0.76f, -0.45f);
    glVertex2f(-0.81f, -0.41f);
    glEnd();

    glColor3ub(250, 17, 5);
    circle(-0.80,-0.50,0.02);
    circle(-0.91,-0.50,0.02);

    if (night==true)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(255, 242, 0);
        glVertex2f(-0.75, -0.45f);
        glVertex2f(-0.73f, -0.52f);
        glVertex2f(-0.70f, -0.52f);
        glEnd();
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosition1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(3, 98, 252);
    glVertex2f(0.30f, -0.53f);
    glVertex2f(0.25f, -0.58f);
    glVertex2f(0.25f, -0.63f);
    glVertex2f(0.45f, -0.63f);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.40f, -0.53f);
    glVertex2f(0.30f, -0.53f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(0.31f, -0.54f);
    glVertex2f(0.26f, -0.58f);
    glVertex2f(0.34f, -0.58f);
    glVertex2f(0.34f, -0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 250, 238);
    glVertex2f(0.36f, -0.54f);
    glVertex2f(0.36f, -0.58f);
    glVertex2f(0.44f, -0.58f);
    glVertex2f(0.40f, -0.54f);
    glEnd();

    glColor3ub(250, 17, 5);
    circle(0.29,-0.63,0.02);
    circle(0.40,-0.63,0.02);

    if (night==true)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(255, 242, 0);
        glVertex2f(0.25f, -0.58f);
        glVertex2f(0.23f, -0.65f);
        glVertex2f(0.20f, -0.65f);
        glEnd();

    }

    glPopMatrix();

    glFlush();
}

void sun()
{
    glColor3ub(255, 126, 5);
    glPushMatrix();
    glTranslatef(0.0, sunPosition, 0.0f);
    circle(0.9, 0.9, 0.1);
    glPopMatrix();

    glFlush();

}
void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);

    Sky();
    sun();
    grass();
    field();
    clouds();
    hill();
    glPushMatrix();
    building();
    glTranslatef(.60f,0.0f,0.0f);
    building();
    glTranslatef(.70f,0.0f,0.0f);
    building();
    glPopMatrix();
    glPushMatrix();
    glPopMatrix();
    river();
    car();

    //if (f1==1)
    {
        //dayNight();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='a')
    {
        //sun();
        f1=0;
        night=false;
        sunPosition=0.0;
        glutPostRedisplay();
    }
    if(key=='b')
    {
        //sun();
        f1=0;
        night=true;
        sunPosition=-1.0;
        glutPostRedisplay();
    }

    else if(key=='q')
    {
        carSpeed -= 0.01f;
        glutPostRedisplay();
    }
    else if(key=='r')
    {
        carSpeed = 0.0f;
        glutPostRedisplay();
    }
    else if(key=='s')
    {
        carSpeed1 += 0.01f;
        glutPostRedisplay();
    }
    else if(key=='t')
    {
        carSpeed1 = 0.0f;
        glutPostRedisplay();
    }

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(700,700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Portland City");
    glutDisplayFunc(display);
    glutTimerFunc(200, update, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

