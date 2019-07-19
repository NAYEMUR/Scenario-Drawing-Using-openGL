#include<iostream>
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

# define PI           3.14159265358979323846

GLfloat x=0;
GLfloat y=0;
GLfloat radius =1;
int i;
int triangleAmount = 16;
GLfloat twicePi = 2.0f * PI;

GLfloat t=0;
GLfloat pan=-1;
GLfloat dd=1;
GLfloat car=0;
GLfloat wind=1;
GLfloat tree=0;
GLfloat tf=0.05;

GLfloat pl=-1.5;
GLfloat flag=-1;

GLfloat spd=0.001;
GLfloat cl1=0;
GLfloat cl2=0.5;
GLfloat cl3=-0.7;
GLfloat cl4=0.9;
GLfloat cl5=-0.2;


GLfloat rain1x=0;
GLfloat rain1y=0;

GLfloat rain2x=0.75;
GLfloat rain2y=0.75;

GLfloat rain3x=0.5;
GLfloat rain3y=0.5;

GLfloat rain4x=-0.25;
GLfloat rain4y=-0.25;

GLfloat rain5x=-0;
GLfloat rain5y=-0;

GLfloat rain6x=-0.25;
GLfloat rain6y=-0.25;

GLfloat rain7x=-0.5;
GLfloat rain7y=-0.5;

GLfloat rain8x=-0.75;
GLfloat rain8y=-0.75;


GLfloat rainax=-1;
GLfloat rainay=-1;


GLfloat rainbx=1;
GLfloat rainby=1;


GLfloat raincx=1;
GLfloat raincy=0;




void night();

void day();

void rain();

void evening();

void dayswitch(int dd)
{
    if (dd==0)
    {
        wind=1;
        tf=0.05;
        glutDisplayFunc(day);
        PlaySound(NULL, NULL, 0);
    }

    else if (dd==1)
    {
        wind=1;
        tf=0.05;

        glutDisplayFunc(night);
        PlaySound(NULL, NULL, 0);
    }

    else if (dd==2)
    {
        wind=2.5;
        tf=0.25;

        glutDisplayFunc(rain);
        PlaySound(TEXT("rain.wav"), NULL, SND_LOOP|SND_FILENAME|SND_ASYNC);
    }

    else if (dd==3)
    {
        wind=1.5;
        tf=0.1;

        glutDisplayFunc(evening);
        PlaySound(NULL, NULL, 0);
    }
}

void day(void)
{
    glClearColor(0.7,0.9,0.95,1);
    glClear(GL_COLOR_BUFFER_BIT);


    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //SUN
    {
        x=0.8; y=0.45; radius =0.05;
        int triangleAmount = 16;

        glColor3f(1,1,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    }

    //PLANE
    {
        glTranslatef(((pl*0.15)),((pl*0.15)+0.3),0);
        glColor3f(0.5,0.5,0.5);
        glScalef(flag,flag,1);
        glScalef(0.2,0.2,1);
        glRotatef(45,0,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,-0.1);
        glVertex2f(0.04,-0.02);
        glVertex2f(0.08,-0.02);
        glVertex2f(0.1,0);
        glVertex2f(0.08,0.02);
        glVertex2f(0.04,0.02);
        glVertex2f(0,0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.09,0.01);
        glVertex2f(-0.1,0);
        glVertex2f(-0.09,-0.01);
        glVertex2f(-0.09,-0.06);
        glVertex2f(-0.07,-0.01);
        glVertex2f(0,-0.02);
        glVertex2f(0,0.02);
        glVertex2f(-0.07,0.01);
        glVertex2f(-0.09,0.06);
        glEnd();

	}
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //BG
    {
        glColor3f(0.3,0.5,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);
        glVertex2f(1,-1);
        glEnd();
    }
    gluOrtho2D(-1000,1000,-1000,1000);

    //HORIZON TREE LINE
    {
        glTranslatef(0,-100,0);
        glColor3f(0.05,0.3,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(769.792,0);
        glVertex2f(465.266,0);
        glVertex2f(465.266,82.584);
        glVertex2f(564.485,112.571);
        glVertex2f(607.257,94.628);
        glVertex2f(665,112.571);
        glVertex2f(714.188,94.628);
        glVertex2f(769.792,97.578);
        glVertex2f(774.069,124.615);
        glVertex2f(842.505,112.571);
        glVertex2f(876.723,94.628);
        glVertex2f(921.634,103.6);
        glVertex2f(955.851,124.615);
        glVertex2f(1000,102.762);
        glVertex2f(1056.366,115.594);
        glVertex2f(1056.366,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-737.931,0);
        glVertex2f(-1063,0);
        glVertex2f(-1063,102.821);
        glVertex2f(-1000,94.628);
        glVertex2f(-951.792,114.525);
        glVertex2f(-921.228,96.347);
        glVertex2f(-829.891,112.571);
        glVertex2f(-774.095,92.043);
        glVertex2f(-728.781,96.064);
        glVertex2f(-691.313,112.571);
        glVertex2f(-667.356,94.628);
        glVertex2f(-601.059,97.578);
        glVertex2f(-554.01,112.571);
        glVertex2f(-517.653,112.571);
        glVertex2f(-491.99,80.54);
        glVertex2f(-491.99,0);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //SHANGSHAD BHABAN
    {
        gluOrtho2D(-1000,1000,-1000,1000);
        glTranslatef(0,-100,0);
        glScalef(0.75,0.75,1);


        {
            glColor3f(0.775,0.775,0.775);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.75,0.75,0.75);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.65,0.65,0.65);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

        glScalef(-1,1,1);
        {
            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.6,0.6,0.6);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //STREET
    {
        glColor3f(0.2,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-1);
        glEnd();
    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //FOOTPATH
    {
        glColor3f(0.4,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.4);
        glVertex2f(-1,-0.38);
        glVertex2f(1,-0.38);
        glVertex2f(1,-0.4);
        glEnd();

        glColor3f(0.6,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.38);
        glVertex2f(-1,-0.35);
        glVertex2f(1,-0.35);
        glVertex2f(1,-0.38);
        glEnd();
    }


    glLoadIdentity();

    //TREE 1
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(-1.5,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 2
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.4,0.4,1);
    glTranslatef(-1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 3
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(1.1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }


    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,0);

    glTranslatef(-1.25,-0.725,0);

    //LAMP POST L
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(-0.5,0.5,0);
    glTranslatef(-1.25,-0.725,0);
    //LAMP POST R
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }

    glLoadIdentity();

    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(car,-0.85,0);
    gluOrtho2D(-1000,1000,-1000,1000);
    //CAR
    {
        glColor3f(0.8,0.2,0.2);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-648.109,0);
        glVertex2f(-793.535,14.366);
        glVertex2f(-787.832,60.703);
        glVertex2f(-791.04,129.139);
        glVertex2f(-763.594,195.436);
        glVertex2f(-717.97,234.644);
        glVertex2f(-635.99,266.723);
        glVertex2f(-346.564,295.238);
        glVertex2f(-95.634,417.139);
        glVertex2f(22.703,446.366);
        glVertex2f(240.129,449.574);
        glVertex2f(374.149,432.109);
        glVertex2f(491.772,398.96);
        glVertex2f(598.703,356.188);
        glVertex2f(743.059,332.663);
        glVertex2f(770.861,288.822);
        glVertex2f(770.861,203.277);
        glVertex2f(791.178,179.752);
        glVertex2f(784.762,92.069);
        glVertex2f(769.792,46.089);
        glVertex2f(608.683,0);
        glEnd();


        glColor3f(0.4,0.75,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-92.307,280.98);
        glVertex2f(-262.446,280.98);
        glVertex2f(-210.168,327.079);
        glVertex2f(-116.767,381.14);
        glVertex2f(-29.155,416.109);
        glVertex2f(63.337,430.683);
        glVertex2f(144.248,430.683);
        glVertex2f(107.891,289.891);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(381.11,307.179);
        glVertex2f(144.248,292.386);
        glVertex2f(168.604,430.683);
        glVertex2f(238.941,427.832);
        glVertex2f(321.634,415.475);
        glVertex2f(382.465,398.366);
        glVertex2f(453.752,369.376);
        glVertex2f(477.99,346.089);
        glVertex2f(473.713,315.198);
        glEnd();

        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-698.901,159.436);
        glVertex2f(-764.663,159.436);
        glVertex2f(-747.554,193.653);
        glVertex2f(-718.683,220.386);
        glVertex2f(-679.119,234.287);
        glVertex2f(-633.139,238.564);
        glVertex2f(-641.693,199);
        glEnd();

        glColor3f(0.7,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(770.861,213.495);
        glVertex2f(694.228,213.495);
        glVertex2f(682.371,227.943);
        glVertex2f(689,253.891);
        glVertex2f(717.515,272.901);
        glVertex2f(770.861,288.822);
        glEnd();


        x=-490; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        glTranslatef(-490,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {
            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(23.873*(car*1000/120),0,0,1);
        glTranslatef(+490,-37.991,0);

        x=-490; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        x=469; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
            );
		}
        glEnd();

        glTranslatef(469,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {

            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(+23.873*(car*1000/120),0,0,1);
        glTranslatef(-469,-37.991,0);

        x=469; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();





        }

    glLoadIdentity();



    glLoadIdentity();

    glFlush();
}

void night(void)
{
    glClearColor(0.0,0.0,0.0,1);
    glClear(GL_COLOR_BUFFER_BIT);


    gluOrtho2D(pan,pan+1,-0.5,0.5);
    //STARS
    {
        glColor3f(1,1,1);
        glPointSize(3);
        glBegin(GL_POINTS);
        glVertex2f(-0.9,0.3);
        glVertex2f(-0.7,0.4);
        glVertex2f(-0.4,0.35);
        glVertex2f(-0.2,0.25);
        glVertex2f(0,0.45);
        glVertex2f(0.3,0.25);
        glVertex2f(0.6,0.4);
        glVertex2f(0.7,0.2);
        glVertex2f(0.8,0.3);
        glEnd();
    }





    //MOON
    {
        x=0.8f; y=0.45; radius =0.025;
        int triangleAmount = 16;

        glColor3f(1,1,1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    }



    //BG
    {
        glColor3f(0.1,0.3,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);
        glVertex2f(1,-1);
        glEnd();
    }
    gluOrtho2D(-1000,1000,-1000,1000);

    //HORIZON TREE LINE
    {
        glTranslatef(0,-100,0);
        glColor3f(0.025,0.15,0.05);

        glBegin(GL_POLYGON);
        glVertex2f(769.792,0);
        glVertex2f(465.266,0);
        glVertex2f(465.266,82.584);
        glVertex2f(564.485,112.571);
        glVertex2f(607.257,94.628);
        glVertex2f(665,112.571);
        glVertex2f(714.188,94.628);
        glVertex2f(769.792,97.578);
        glVertex2f(774.069,124.615);
        glVertex2f(842.505,112.571);
        glVertex2f(876.723,94.628);
        glVertex2f(921.634,103.6);
        glVertex2f(955.851,124.615);
        glVertex2f(1000,102.762);
        glVertex2f(1056.366,115.594);
        glVertex2f(1056.366,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-737.931,0);
        glVertex2f(-1063,0);
        glVertex2f(-1063,102.821);
        glVertex2f(-1000,94.628);
        glVertex2f(-951.792,114.525);
        glVertex2f(-921.228,96.347);
        glVertex2f(-829.891,112.571);
        glVertex2f(-774.095,92.043);
        glVertex2f(-728.781,96.064);
        glVertex2f(-691.313,112.571);
        glVertex2f(-667.356,94.628);
        glVertex2f(-601.059,97.578);
        glVertex2f(-554.01,112.571);
        glVertex2f(-517.653,112.571);
        glVertex2f(-491.99,80.54);
        glVertex2f(-491.99,0);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //SHANGSHAD BHABAN
    {
        gluOrtho2D(-1000,1000,-1000,1000);
        glTranslatef(0,-100,0);
        glScalef(0.75,0.75,1);


        {
            glColor3f(0.675,0.675,0.675);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.65,0.65,0.65);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.25,0.25,0.25);

        }

        {
            glColor3f(0.6,0.6,0.6);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.55,0.55,0.55);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.575,0.575,0.575);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.6,0.6,0.6);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.5,0.1,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.8,0.8,0.8);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.8,0.8,0.8);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(0,0);
        glColor3f(0.8,0.8,0.8);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(907.677,0);
        glEnd();

    }

        glScalef(-1,1,1);
        {
            glColor3f(0.65,0.65,0.65);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.6,0.6,0.6);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.6,0.6,0.6);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.6,0.6,0.6);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.5,0.5,0.5);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.6,0.6,0.6);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.25,0.25,0.25);

        }

        {
            glColor3f(0.6,0.6,0.6);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.65,0.65,0.65);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.575,0.575,0.575);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.25,0.25,0.25);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.5,0.1,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.8,0.8,0.8);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.8,0.8,0.8);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(0,0);
        glColor3f(0.8,0.8,0.8);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(907.677,0);
        glEnd();

    }

    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //STREET
    {
        glColor3f(0.1,0.1,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-1);
        glEnd();
    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //FOOTPATH
    {
        glColor3f(0.3,0.1,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.4);
        glVertex2f(-1,-0.38);
        glVertex2f(1,-0.38);
        glVertex2f(1,-0.4);
        glEnd();

        glColor3f(0.5,0.1,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.38);
        glVertex2f(-1,-0.35);
        glVertex2f(1,-0.35);
        glVertex2f(1,-0.38);
        glEnd();
    }


    glLoadIdentity();

    //TREE 1
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(-1.5,-0.65,0);

    {
        glColor3f(0.3,0.15,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 2
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.4,0.4,1);
    glTranslatef(-1,-0.65,0);

    {
        glColor3f(0.3,0.15,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 3
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(1.1,-0.65,0);

    {
        glColor3f(0.3,0.15,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.05,0.3,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.2,0.1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }


    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,0);

    glTranslatef(-1.25,-0.725,0);

    //LAMP POST L
    {
        glColor3f(0.75,0.75,0.75);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(-0.5,0.5,0);
    glTranslatef(-1.25,-0.725,0);
    //LAMP POST R
    {
        glColor3f(0.75,0.75,0.75);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }

    glLoadIdentity();

    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(car,-0.85,0);
    gluOrtho2D(-1000,1000,-1000,1000);
    //CAR
    {
        glColor3f(0.6,0.1,0.1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-648.109,0);
        glVertex2f(-793.535,14.366);
        glVertex2f(-787.832,60.703);
        glVertex2f(-791.04,129.139);
        glVertex2f(-763.594,195.436);
        glVertex2f(-717.97,234.644);
        glVertex2f(-635.99,266.723);
        glVertex2f(-346.564,295.238);
        glVertex2f(-95.634,417.139);
        glVertex2f(22.703,446.366);
        glVertex2f(240.129,449.574);
        glVertex2f(374.149,432.109);
        glVertex2f(491.772,398.96);
        glVertex2f(598.703,356.188);
        glVertex2f(743.059,332.663);
        glVertex2f(770.861,288.822);
        glVertex2f(770.861,203.277);
        glVertex2f(791.178,179.752);
        glVertex2f(784.762,92.069);
        glVertex2f(769.792,46.089);
        glVertex2f(608.683,0);
        glEnd();


        glColor3f(0.3,0.65,0.7);
        glBegin(GL_POLYGON);
        glVertex2f(-92.307,280.98);
        glVertex2f(-262.446,280.98);
        glVertex2f(-210.168,327.079);
        glVertex2f(-116.767,381.14);
        glVertex2f(-29.155,416.109);
        glVertex2f(63.337,430.683);
        glVertex2f(144.248,430.683);
        glVertex2f(107.891,289.891);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(381.11,307.179);
        glVertex2f(144.248,292.386);
        glVertex2f(168.604,430.683);
        glVertex2f(238.941,427.832);
        glVertex2f(321.634,415.475);
        glVertex2f(382.465,398.366);
        glVertex2f(453.752,369.376);
        glVertex2f(477.99,346.089);
        glVertex2f(473.713,315.198);
        glEnd();

        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-698.901,159.436);
        glVertex2f(-764.663,159.436);
        glVertex2f(-747.554,193.653);
        glVertex2f(-718.683,220.386);
        glVertex2f(-679.119,234.287);
        glVertex2f(-633.139,238.564);
        glVertex2f(-641.693,199);
        glEnd();

        glColor3f(0.7,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(770.861,213.495);
        glVertex2f(694.228,213.495);
        glVertex2f(682.371,227.943);
        glVertex2f(689,253.891);
        glVertex2f(717.515,272.901);
        glVertex2f(770.861,288.822);
        glEnd();


        x=-490; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        glTranslatef(-490,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {
            glColor3f(0.6,0.6,0.6);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(23.873*(car*1000/120),0,0,1);
        glTranslatef(+490,-37.991,0);

        x=-490; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.6,0.6,0.6);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        x=469; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
            );
		}
        glEnd();

        glTranslatef(469,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {

            glColor3f(0.6,0.6,0.6);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(+23.873*(car*1000/120),0,0,1);
        glTranslatef(-469,-37.991,0);

        x=469; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.6,0.6,0.6);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();





        }

    glLoadIdentity();



    glLoadIdentity();

    glFlush();
}

void rain(void)
{
    glClearColor(0.6,0.6,0.55,1);
    glClear(GL_COLOR_BUFFER_BIT);


    //GRADIENT SKY
    {
        glBegin(GL_QUADS);
        glColor3f(0.6,0.6,0.55);
        glVertex2f(1,-0.1);
        glVertex2f(-1,-0.1);
        glColor3f(0.3,0.3,0.25);
        glVertex2f(-1,1);
        glVertex2f(1,1);
        glEnd();
    }

    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //BG
    {
        glColor3f(0.3,0.5,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);
        glVertex2f(1,-1);
        glEnd();
    }

    //CLOUDS
    {
        glColor3f(0.3,0.3,0.3);
        glTranslatef(cl1,0.25,0);
        glScalef(1,1,0);
        glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(-0.125,0);
        glVertex2f(-0.1,0.01);
        glVertex2f(-0.075,0.03);
        glVertex2f(-0.05,0.02);
        glVertex2f(-0.025,0.05);
        glVertex2f(0.0,0.06);
        glVertex2f(0.025,0.04);
        glVertex2f(0.05,0.03);
        glVertex2f(0.075,0.01);
        glVertex2f(0.1,0.0);

        glEnd();
        glLoadIdentity();
        gluOrtho2D(pan,pan+1,-0.5,0.5);
        glTranslatef(cl2,0.2,0);
        glScalef(-1.5,1.5,0);
        glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(-0.125,0);
        glVertex2f(-0.1,0.01);
        glVertex2f(-0.075,0.03);
        glVertex2f(-0.05,0.02);
        glVertex2f(-0.025,0.05);
        glVertex2f(0.0,0.06);
        glVertex2f(0.025,0.04);
        glVertex2f(0.05,0.03);
        glVertex2f(0.075,0.01);
        glVertex2f(0.1,0.0);

        glEnd();
        glLoadIdentity();
gluOrtho2D(pan,pan+1,-0.5,0.5);
        glTranslatef(cl3,0.225,0);
        glScalef(0.8,0.8,0);
        glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(-0.125,0);
        glVertex2f(-0.1,0.01);
        glVertex2f(-0.075,0.03);
        glVertex2f(-0.05,0.02);
        glVertex2f(-0.025,0.05);
        glVertex2f(0.0,0.06);
        glVertex2f(0.025,0.04);
        glVertex2f(0.05,0.03);
        glVertex2f(0.075,0.01);
        glVertex2f(0.1,0.0);

        glEnd();
        glLoadIdentity();
gluOrtho2D(pan,pan+1,-0.5,0.5);
        glTranslatef(cl4,0.1,0);
        glScalef(-0.6,0.6,0);
        glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(-0.125,0);
        glVertex2f(-0.1,0.01);
        glVertex2f(-0.075,0.03);
        glVertex2f(-0.05,0.02);
        glVertex2f(-0.025,0.05);
        glVertex2f(0.0,0.06);
        glVertex2f(0.025,0.04);
        glVertex2f(0.05,0.03);
        glVertex2f(0.075,0.01);
        glVertex2f(0.1,0.0);

        glEnd();
        glLoadIdentity();
gluOrtho2D(pan,pan+1,-0.5,0.5);
        glTranslatef(cl5,0.3,0);
        glScalef(-1,1,0);
        glBegin(GL_POLYGON);

        glVertex2f(0,0);
        glVertex2f(-0.125,0);
        glVertex2f(-0.1,0.01);
        glVertex2f(-0.075,0.03);
        glVertex2f(-0.05,0.02);
        glVertex2f(-0.025,0.05);
        glVertex2f(0.0,0.06);
        glVertex2f(0.025,0.04);
        glVertex2f(0.05,0.03);
        glVertex2f(0.075,0.01);
        glVertex2f(0.1,0.0);

        glEnd();
        glLoadIdentity();
    }
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    gluOrtho2D(-1000,1000,-1000,1000);

    //HORIZON TREE LINE
    {
        glTranslatef(0,-100,0);
        glColor3f(0.05,0.3,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(769.792,0);
        glVertex2f(465.266,0);
        glVertex2f(465.266,82.584);
        glVertex2f(564.485,112.571);
        glVertex2f(607.257,94.628);
        glVertex2f(665,112.571);
        glVertex2f(714.188,94.628);
        glVertex2f(769.792,97.578);
        glVertex2f(774.069,124.615);
        glVertex2f(842.505,112.571);
        glVertex2f(876.723,94.628);
        glVertex2f(921.634,103.6);
        glVertex2f(955.851,124.615);
        glVertex2f(1000,102.762);
        glVertex2f(1056.366,115.594);
        glVertex2f(1056.366,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-737.931,0);
        glVertex2f(-1063,0);
        glVertex2f(-1063,102.821);
        glVertex2f(-1000,94.628);
        glVertex2f(-951.792,114.525);
        glVertex2f(-921.228,96.347);
        glVertex2f(-829.891,112.571);
        glVertex2f(-774.095,92.043);
        glVertex2f(-728.781,96.064);
        glVertex2f(-691.313,112.571);
        glVertex2f(-667.356,94.628);
        glVertex2f(-601.059,97.578);
        glVertex2f(-554.01,112.571);
        glVertex2f(-517.653,112.571);
        glVertex2f(-491.99,80.54);
        glVertex2f(-491.99,0);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //SHANGSHAD BHABAN
    {
        gluOrtho2D(-1000,1000,-1000,1000);
        glTranslatef(0,-100,0);
        glScalef(0.75,0.75,1);


        {
            glColor3f(0.775,0.775,0.775);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.75,0.75,0.75);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.65,0.65,0.65);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

        glScalef(-1,1,1);
        {
            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.6,0.6,0.6);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //STREET
    {
        glColor3f(0.2,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-1);
        glEnd();
    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //FOOTPATH
    {
        glColor3f(0.4,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.4);
        glVertex2f(-1,-0.38);
        glVertex2f(1,-0.38);
        glVertex2f(1,-0.4);
        glEnd();

        glColor3f(0.6,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.38);
        glVertex2f(-1,-0.35);
        glVertex2f(1,-0.35);
        glVertex2f(1,-0.38);
        glEnd();
    }


    glLoadIdentity();

    //TREE 1
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(-1.5,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 2
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.4,0.4,1);
    glTranslatef(-1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 3
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(1.1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }


    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,0);

    glTranslatef(-1.25,-0.725,0);

    //LAMP POST L
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(-0.5,0.5,0);
    glTranslatef(-1.25,-0.725,0);
    //LAMP POST R
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }

    glLoadIdentity();

    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(car,-0.85,0);
    gluOrtho2D(-1000,1000,-1000,1000);
    //CAR
    {
        glColor3f(0.8,0.2,0.2);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-648.109,0);
        glVertex2f(-793.535,14.366);
        glVertex2f(-787.832,60.703);
        glVertex2f(-791.04,129.139);
        glVertex2f(-763.594,195.436);
        glVertex2f(-717.97,234.644);
        glVertex2f(-635.99,266.723);
        glVertex2f(-346.564,295.238);
        glVertex2f(-95.634,417.139);
        glVertex2f(22.703,446.366);
        glVertex2f(240.129,449.574);
        glVertex2f(374.149,432.109);
        glVertex2f(491.772,398.96);
        glVertex2f(598.703,356.188);
        glVertex2f(743.059,332.663);
        glVertex2f(770.861,288.822);
        glVertex2f(770.861,203.277);
        glVertex2f(791.178,179.752);
        glVertex2f(784.762,92.069);
        glVertex2f(769.792,46.089);
        glVertex2f(608.683,0);
        glEnd();


        glColor3f(0.4,0.75,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-92.307,280.98);
        glVertex2f(-262.446,280.98);
        glVertex2f(-210.168,327.079);
        glVertex2f(-116.767,381.14);
        glVertex2f(-29.155,416.109);
        glVertex2f(63.337,430.683);
        glVertex2f(144.248,430.683);
        glVertex2f(107.891,289.891);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(381.11,307.179);
        glVertex2f(144.248,292.386);
        glVertex2f(168.604,430.683);
        glVertex2f(238.941,427.832);
        glVertex2f(321.634,415.475);
        glVertex2f(382.465,398.366);
        glVertex2f(453.752,369.376);
        glVertex2f(477.99,346.089);
        glVertex2f(473.713,315.198);
        glEnd();

        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-698.901,159.436);
        glVertex2f(-764.663,159.436);
        glVertex2f(-747.554,193.653);
        glVertex2f(-718.683,220.386);
        glVertex2f(-679.119,234.287);
        glVertex2f(-633.139,238.564);
        glVertex2f(-641.693,199);
        glEnd();

        glColor3f(0.7,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(770.861,213.495);
        glVertex2f(694.228,213.495);
        glVertex2f(682.371,227.943);
        glVertex2f(689,253.891);
        glVertex2f(717.515,272.901);
        glVertex2f(770.861,288.822);
        glEnd();


        x=-490; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        glTranslatef(-490,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {
            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(23.873*(car*1000/120),0,0,1);
        glTranslatef(+490,-37.991,0);

        x=-490; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        x=469; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
            );
		}
        glEnd();

        glTranslatef(469,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {

            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(+23.873*(car*1000/120),0,0,1);
        glTranslatef(-469,-37.991,0);

        x=469; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();





        }

    glLoadIdentity();

    //RAIN
    glLoadIdentity();

    {
        glColor3f(1,1,1);
        glLineWidth(1);

        glTranslatef(rain1x,rain1y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain2x,rain2y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain3x,rain3y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain4x,rain4y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain5x,rain5y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain6x,rain6y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain7x,rain7y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rain8x,rain8y,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rainax,rainay,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(rainbx,rainby,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();
        glLoadIdentity();

        glTranslatef(raincx,raincy,0);
        glBegin(GL_LINES);
        glVertex2f(-0.025f,-0.05f);
        glVertex2f(0.025f,0.05f);
        glEnd();

        glLoadIdentity();
    }

    glLoadIdentity();

    glFlush();
}

void evening(void)
{
    glClearColor(0.2,0.4,0.7,1);
    glClear(GL_COLOR_BUFFER_BIT);


    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //GRADIENT SKY
    {
        glBegin(GL_QUADS);
        glColor3f(0.7,0.5,0.2);
        glVertex2f(1,-0.1);
        glVertex2f(-1,-0.1);
        glColor3f(0.2,0.4,0.7);
        glVertex2f(-1,0.5);
        glVertex2f(1,0.5);
        glEnd();
    }


    //SUN
    {
        x=0.8; y=0.05; radius =0.075;
        int triangleAmount = 32;

        glColor3f(1,0.4,0);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    }

    //PLANE
    {
        glTranslatef(((pl*0.15)),((pl*0.15)+0.3),0);
        glColor3f(0.5,0.5,0.5);
        glScalef(flag,flag,1);
        glScalef(0.2,0.2,1);
        glRotatef(45,0,0,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,-0.1);
        glVertex2f(0.04,-0.02);
        glVertex2f(0.08,-0.02);
        glVertex2f(0.1,0);
        glVertex2f(0.08,0.02);
        glVertex2f(0.04,0.02);
        glVertex2f(0,0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-0.09,0.01);
        glVertex2f(-0.1,0);
        glVertex2f(-0.09,-0.01);
        glVertex2f(-0.09,-0.06);
        glVertex2f(-0.07,-0.01);
        glVertex2f(0,-0.02);
        glVertex2f(0,0.02);
        glVertex2f(-0.07,0.01);
        glVertex2f(-0.09,0.06);
        glEnd();

	}
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //BG
    {
        glColor3f(0.3,0.5,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);
        glVertex2f(1,-1);
        glEnd();
    }
    gluOrtho2D(-1000,1000,-1000,1000);

    //HORIZON TREE LINE
    {
        glTranslatef(0,-100,0);
        glColor3f(0.05,0.3,0.1);

        glBegin(GL_POLYGON);
        glVertex2f(769.792,0);
        glVertex2f(465.266,0);
        glVertex2f(465.266,82.584);
        glVertex2f(564.485,112.571);
        glVertex2f(607.257,94.628);
        glVertex2f(665,112.571);
        glVertex2f(714.188,94.628);
        glVertex2f(769.792,97.578);
        glVertex2f(774.069,124.615);
        glVertex2f(842.505,112.571);
        glVertex2f(876.723,94.628);
        glVertex2f(921.634,103.6);
        glVertex2f(955.851,124.615);
        glVertex2f(1000,102.762);
        glVertex2f(1056.366,115.594);
        glVertex2f(1056.366,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-737.931,0);
        glVertex2f(-1063,0);
        glVertex2f(-1063,102.821);
        glVertex2f(-1000,94.628);
        glVertex2f(-951.792,114.525);
        glVertex2f(-921.228,96.347);
        glVertex2f(-829.891,112.571);
        glVertex2f(-774.095,92.043);
        glVertex2f(-728.781,96.064);
        glVertex2f(-691.313,112.571);
        glVertex2f(-667.356,94.628);
        glVertex2f(-601.059,97.578);
        glVertex2f(-554.01,112.571);
        glVertex2f(-517.653,112.571);
        glVertex2f(-491.99,80.54);
        glVertex2f(-491.99,0);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //SHANGSHAD BHABAN
    {
        gluOrtho2D(-1000,1000,-1000,1000);
        glTranslatef(0,-100,0);
        glScalef(0.75,0.75,1);


        {
            glColor3f(0.775,0.775,0.775);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.75,0.75,0.75);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.65,0.65,0.65);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

        glScalef(-1,1,1);
        {
            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(59.41,485.503);
            glVertex2f(177.72,475.671);
            glVertex2f(177.72,463.545);
            glVertex2f(208.198,448.797);
            glVertex2f(59.41,448.797);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(503.791,85.676);
            glVertex2f(492.392,377.782);
            glVertex2f(508.031,377.782);
            glVertex2f(519.993,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(254.244,384.071);
            glVertex2f(251.295,460.268);
            glVertex2f(285.706,440.112);
            glVertex2f(289.311,388.004);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(363.213,85.676);
            glVertex2f(352.726,411.436);
            glVertex2f(493.102,385.218);
            glVertex2f(504.791,85.676);
            glEnd();

            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(518.993,85.676);
            glVertex2f(507.031,382.432);
            glVertex2f(624.739,359);
            glVertex2f(642.901,84.338);
            glEnd();


            glBegin(GL_POLYGON);

            glColor3f(0.6,0.6,0.6);
            glVertex2f(639.815,85.676);
            glVertex2f(625.886,338.872);

            glColor3f(0.7,0.7,0.7);
            glVertex2f(710.549,338.872);
            glVertex2f(723.9,84.338);

            glEnd();

            ////

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(74.595,443.99);
            glVertex2f(83.116,460.268);
            glVertex2f(94.477,468.242);
            glVertex2f(108.242,473.267);
            glVertex2f(121.351,473.267);
            glVertex2f(136.645,467.15);
            glVertex2f(149.535,458.192);
            glVertex2f(158.93,443.99);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(256.702,393.575);
            glVertex2f(256.702,409.142);
            glVertex2f(258.505,427.167);
            glVertex2f(261.454,437.654);
            glVertex2f(264.567,441.915);
            glVertex2f(268.992,442.406);
            glVertex2f(273.088,438.801);
            glVertex2f(277.84,429.461);
            glVertex2f(281.773,413.73);
            glVertex2f(284.723,398.327);
            glEnd();

            glColor3f(0.35,0.35,0.35);

        }

        {
            glColor3f(0.7,0.7,0.7);

            glBegin(GL_POLYGON);
            glVertex2f(0,377.362);
            glVertex2f(0,480.477);
            glVertex2f(59.41,480.477);
            glVertex2f(59.41,377.353);
            glEnd();

            glColor3f(0.75,0.75,0.75);

            glBegin(GL_POLYGON);
            glVertex2f(208.619,371.938);
            glVertex2f(207.198,448.797);
            glVertex2f(251.295,460.268);
            glVertex2f(254.244,384.071);
            glEnd();

            glBegin(GL_POLYGON);

            glColor3f(0.675,0.675,0.675);
            glVertex2f(212.77,85.676);
            glVertex2f(208.301,389.135);

            glColor3f(0.8,0.8,0.8);
            glVertex2f(352.726,411.436);
            glVertex2f(363.213,85.676);

            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(0,71.911);
            glVertex2f(0,377.362);
            glVertex2f(36.797,377.353);
            glVertex2f(36.797,71.911);
            glEnd();


            glColor3f(0.8,0.8,0.8);

            glBegin(GL_POLYGON);
            glVertex2f(36.797,71.911);
            glVertex2f(36.797,448.797);
            glVertex2f(208.198,448.797);
            glVertex2f(213.77,85.676);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(311.533,136.582);
            glVertex2f(299.307,139.751);
            glVertex2f(288.492,148.272);
            glVertex2f(278.933,161.982);
            glVertex2f(275.3,180.997);
            glVertex2f(276.366,202.347);
            glVertex2f(281.282,217.422);
            glVertex2f(296.029,231.729);
            glVertex2f(312.416,237.741);
            glVertex2f(331.424,231.729);
            glVertex2f(344.205,219.716);
            glVertex2f(351.415,203.33);
            glVertex2f(352.726,185.305);
            glVertex2f(348.466,165.641);
            glVertex2f(339.945,151.549);
            glVertex2f(326.18,139.095);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(372.062,109.6);
            glVertex2f(370.751,165.641);
            glVertex2f(423.187,162.692);
            glVertex2f(424.826,113.205);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(368.785,210.212);
            glVertex2f(390.742,364.244);
            glVertex2f(423.187,204.641);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(587.051,109.6);
            glVertex2f(587.051,149.583);
            glVertex2f(629.655,146.961);
            glVertex2f(629.655,110.911);
            glEnd();

            glColor3f(0.35,0.35,0.35);

            glBegin(GL_POLYGON);
            glVertex2f(584.32,189.675);
            glVertex2f(598.74,331.689);
            glVertex2f(626.651,184.868);
            glEnd();

        }

        {
        glColor3f(0.6,0.2,0.0);

        glBegin(GL_POLYGON);
        glVertex2f(739.881,36.298);
        glVertex2f(80.057,31.055);
        glVertex2f(380.583,125.659);
        glVertex2f(551.622,125.659);
        glVertex2f(587.051,136.582);
        glVertex2f(734.105,137.621);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(208.198,31.055);
        glVertex2f(557.227,136.582);
        glVertex2f(587.051,136.582);
        glVertex2f(244.795,31.055);
        glEnd();

        glColor3f(0.9,0.9,0.9);

        glBegin(GL_POLYGON);
        glVertex2f(59.083,31.055);
        glVertex2f(359.036,125.659);
        glVertex2f(380.583,125.659);
        glVertex2f(90.057,31.055);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,93.541);
        glVertex2f(487.749,93.541);
        glVertex2f(907.677,0);
        glEnd();

    }

    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //STREET
    {
        glColor3f(0.2,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-1);
        glEnd();
    }

    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);

    //FOOTPATH
    {
        glColor3f(0.4,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.4);
        glVertex2f(-1,-0.38);
        glVertex2f(1,-0.38);
        glVertex2f(1,-0.4);
        glEnd();

        glColor3f(0.6,0.2,0.2);

        glBegin(GL_POLYGON);
        glVertex2f(-1,-0.38);
        glVertex2f(-1,-0.35);
        glVertex2f(1,-0.35);
        glVertex2f(1,-0.38);
        glEnd();
    }


    glLoadIdentity();

    //TREE 1
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(-1.5,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 2
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.4,0.4,1);
    glTranslatef(-1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }

    glLoadIdentity();

    //TREE 3
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(1.1,-0.65,0);

    {
        glColor3f(0.4,0.25,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.05,0);
        glVertex2f(-0.025,0.6);
        glVertex2f(0.025,0.6);
        glVertex2f(0.05,0);
        glEnd();

        glTranslatef(0,0.3,0);
        glScalef(3,3,3);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(-tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(-tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();

        glRotatef(tree,0,0,1);
        glTranslatef(0,0.06,0);
        glScalef(0.85,0.85,0.85);
        glRotatef(tree,0,0,1);
        glColor3f(0.1,0.4,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.1);
        glVertex2f(-0.1,-0.075);
        glVertex2f(0.1,-0.075);
        glEnd();
        glColor3f(0.0,0.3,0.2);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.095);
        glVertex2f(-0.09,-0.075);
        glVertex2f(0.09,-0.075);
        glEnd();







    }


    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,0);

    glTranslatef(-1.25,-0.725,0);

    //LAMP POST L
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }
    glLoadIdentity();
    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(-0.5,0.5,0);
    glTranslatef(-1.25,-0.725,0);
    //LAMP POST R
    {
        glColor3f(0.85,0.85,0.85);

        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-0.025,0);
        glVertex2f(-0.0125,0.1);
        glVertex2f(-0.0125,1);
        glVertex2f(0.0125,1);
        glVertex2f(0.0125,0.1);
        glVertex2f(0.025,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-0.025,1.035);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.12,1.08);
        glVertex2f(-0.1,1.09);
        glVertex2f(-0.04,1.09);
        glVertex2f(-0.0125,1.07);
        glVertex2f(0.01,1.03);
        glVertex2f(0.0125,1);
        glVertex2f(-0.0125,1);
        glEnd();

        glColor3f(1,1,0.4);

        glBegin(GL_POLYGON);
        glVertex2f(-0.04,1.03);
        glVertex2f(-0.1,1.03);
        glVertex2f(-0.12,1.05);
        glVertex2f(-0.02,1.05);
        glEnd();

    }

    glLoadIdentity();

    gluOrtho2D(pan,pan+1,-0.5,0.5);
    glScalef(0.5,0.5,1);
    glTranslatef(car,-0.85,0);
    gluOrtho2D(-1000,1000,-1000,1000);
    //CAR
    {
        glColor3f(0.8,0.2,0.2);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(-648.109,0);
        glVertex2f(-793.535,14.366);
        glVertex2f(-787.832,60.703);
        glVertex2f(-791.04,129.139);
        glVertex2f(-763.594,195.436);
        glVertex2f(-717.97,234.644);
        glVertex2f(-635.99,266.723);
        glVertex2f(-346.564,295.238);
        glVertex2f(-95.634,417.139);
        glVertex2f(22.703,446.366);
        glVertex2f(240.129,449.574);
        glVertex2f(374.149,432.109);
        glVertex2f(491.772,398.96);
        glVertex2f(598.703,356.188);
        glVertex2f(743.059,332.663);
        glVertex2f(770.861,288.822);
        glVertex2f(770.861,203.277);
        glVertex2f(791.178,179.752);
        glVertex2f(784.762,92.069);
        glVertex2f(769.792,46.089);
        glVertex2f(608.683,0);
        glEnd();


        glColor3f(0.4,0.75,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-92.307,280.98);
        glVertex2f(-262.446,280.98);
        glVertex2f(-210.168,327.079);
        glVertex2f(-116.767,381.14);
        glVertex2f(-29.155,416.109);
        glVertex2f(63.337,430.683);
        glVertex2f(144.248,430.683);
        glVertex2f(107.891,289.891);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(381.11,307.179);
        glVertex2f(144.248,292.386);
        glVertex2f(168.604,430.683);
        glVertex2f(238.941,427.832);
        glVertex2f(321.634,415.475);
        glVertex2f(382.465,398.366);
        glVertex2f(453.752,369.376);
        glVertex2f(477.99,346.089);
        glVertex2f(473.713,315.198);
        glEnd();

        glColor3f(0.9,0.9,0.9);
        glBegin(GL_POLYGON);
        glVertex2f(-698.901,159.436);
        glVertex2f(-764.663,159.436);
        glVertex2f(-747.554,193.653);
        glVertex2f(-718.683,220.386);
        glVertex2f(-679.119,234.287);
        glVertex2f(-633.139,238.564);
        glVertex2f(-641.693,199);
        glEnd();

        glColor3f(0.7,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(770.861,213.495);
        glVertex2f(694.228,213.495);
        glVertex2f(682.371,227.943);
        glVertex2f(689,253.891);
        glVertex2f(717.515,272.901);
        glVertex2f(770.861,288.822);
        glEnd();


        x=-490; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        glTranslatef(-490,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {
            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(23.873*(car*1000/120),0,0,1);
        glTranslatef(+490,-37.991,0);

        x=-490; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();

        x=469; y=37.891; radius =120;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.1,0.1,0.1);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
            );
		}
        glEnd();

        glTranslatef(469,37.991,0);
        glRotatef(-23.873*(car*1000/120),0,0,1);
        {

            glColor3f(0.7,0.7,0.7);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
            glRotatef(60,0,0,1);
            glBegin(GL_TRIANGLES);
            glVertex2f(0,0);
            glVertex2f(-10,80);
            glVertex2f(10,80);
            glEnd();
        }
        glRotatef(+23.873*(car*1000/120),0,0,1);
        glTranslatef(-469,-37.991,0);

        x=469; y=37.891; radius =25;
            i;
            triangleAmount = 16;
            twicePi = 2.0f * PI;

        glColor3f(0.7,0.7,0.7);
      	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
        glEnd();





        }

    glLoadIdentity();



    glLoadIdentity();

    glFlush();
}


/*void initGL() {
	glClearColor(0.7f,0.9f,0.9f,1.0f);
}
*/

void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
break;
case GLUT_KEY_DOWN:
break;
case GLUT_KEY_LEFT:
    {
    pan-=0.1;
    if (pan<-1)
    {
        pan=0;
    }
        break;
    }
case GLUT_KEY_RIGHT:
    {
    pan+=0.1;
    if (pan>0)
    {
        pan=-1;
    }
        break;
    }
break;
}
glutPostRedisplay();
}
void handleKeypress(unsigned char key, int x, int y){
	switch (key) {

case 'e':
    {
    dayswitch(3);
    break;
    }
case 'd':
    {
    dayswitch(0);
    break;
	}

case 'n':
    {
    dayswitch(1);
    break;
    }
case 'r':
    {
    dayswitch(2);
    break;
    }

	}
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
	if(button==GLUT_LEFT_BUTTON)
	if(button==GLUT_LEFT_BUTTON)
    {
        {
            flag=1;
        }
    }

	if(button==GLUT_RIGHT_BUTTON)
    {
        {
            flag=-1;
        }
    }

}

void update(int value)
{
    t++;
    car-=0.05;
    if (car<=-5)
        car=5;
    else if (car>=5)
        car=-5;

    if(flag==1&&pl<1.5)
        {
            pl += 0.025;
        }
    if(flag==-1&&pl>-1.5)
        {
            pl -= 0.025;
        }

    cl1+=(spd*2);
    if (cl1>=1.25)
        cl1=-1.25;

    else if (cl1<=-1.25)
        cl1=1.25;

	cl2+=(spd*3);
    if (cl2>=1.25)
        cl2=-1.25;

    else if (cl2<=-1.25)
        cl2=1.25;

	cl3+=(spd*2.25);
    if (cl3>=1.25)
        cl3=-1.25;

    else if (cl3<=-1.25)
        cl3=1.25;

	cl4+=(spd*1.5);
    if (cl4>=1.25)
        cl4=-1.25;

    else if (cl4<=-1.25)
        cl4=1.25;

	cl5+=(spd*2);
    if (cl5>=1.25)
        cl5=-1.25;

    else if (cl5<=-1.25)
        cl5=1.25;


    tree=wind*1*sin(t*wind*tf);

    rain1x-=0.075;
    if (rain1x<=-1)
        rain1x=1;
    rain1y-=0.15;
    if (rain1y<=-1)
        rain1y=1;

    rain2x-=0.075;
    if (rain2x<=-1)
        rain2x=1;
    rain2y-=0.15;
    if (rain2y<=-1)
        rain2y=1;

    rain3x-=0.075;
    if (rain3x<=-1)
        rain3x=1;
    rain3y-=0.15;
    if (rain3y<=-1)
        rain3y=1;

    rain4x-=0.075;
    if (rain4x<=-1)
        rain4x=1;
    rain4y-=0.15;
    if (rain4y<=-1)
        rain4y=1;

    rain5x-=0.075;
    if (rain5x<=-1)
        rain5x=1;
    rain5y-=0.15;
    if (rain5y<=-1)
        rain5y=1;

    rain6x-=0.075;
    if (rain6x<=-1)
        rain6x=1;
    rain6y-=0.15;
    if (rain6y<=-1)
        rain6y=1;

    rain7x-=0.075;
    if (rain7x<=-1)
        rain7x=1;
    rain7y-=0.15;
    if (rain7y<=-1)
        rain7y=1;

    rain8x-=0.075;
    if (rain8x<=-1)
        rain8x=1;
    rain8y-=0.15;
    if (rain8y<=-1)
        rain8y=1;

    rainax-=0.075;
    if (rainax<=-1)
        rainax=1;
    rainay-=0.15;
    if (rainay<=-1)
        rainay=1;

    rainbx-=0.075;
    if (rainbx<=-1)
        rainbx=1;
    rainby-=0.15;
    if (rainby<=-1)
        rainby=1;

    raincx-=0.075;
    if (raincx<=-1)
        raincx=1;
    raincy-=0.15;
    if (raincy<=-1)
        raincy=1;

glutPostRedisplay();

glutTimerFunc(25, update, 0);

}

void Idle()
{
    glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(800,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Scene");
    //glutIdleFunc(Idle);
    glutDisplayFunc(day);

    glutTimerFunc(100, update, 0);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
//    initGL();

    glutMainLoop();
    return 0;

}
