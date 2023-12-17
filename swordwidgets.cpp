#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>
#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include "math.h"
#include <QDebug>
#include "swordwidgets.h"
#include <QAction>
#include <QShortcut>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

swordwidgets::swordwidgets(QWidget *parent)
    : QGLWidget(parent){}

void swordwidgets::initializeGL()
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(20);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
}

void swordwidgets::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = {x1, y1, z1, w1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,50.);
    glPopMatrix();
}

typedef struct materialStruct {
    GLfloat ambient[5];
    GLfloat diffuse[5];
    GLfloat specular[5];
    GLfloat shininess;
} materialStruct;

static materialStruct yellow =
{
    {0.12f, 0.12f, 0.012f, 0.6f},
    {0.614, 0.4, 0.04, 0.5f},
    {0.7f, 0.63f, 0.063f, 0.6f },
    76.8f
};

void setMaterialProperties(GLfloat ambient[], GLfloat diffuse[], GLfloat specular[], GLfloat shininess) {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

GLfloat blade_ambient[] = {0.19225f, 0.19225f, 0.19225f, 1.0f};
GLfloat blade_diffuse[] = {0.50754f, 0.50754f, 0.50754f, 1.0f};
GLfloat blade_specular[] = {0.508273f, 0.508273f, 0.508273f, 1.0f};
GLfloat blade_shininess = 51.2f;

GLfloat handle_ambient[] = {0.05f, 0.0f, 0.0f, 1.0f};
GLfloat handle_diffuse[] = {0.5f, 0.4f, 0.4f, 1.0f};
GLfloat handle_specular[] = {0.7f, 0.04f, 0.04f, 1.0f};
GLfloat handle_shininess = 10.0f;

void swordwidgets::playPause()
{
    if (playingscene == true)
    {
        timer->stop();
        playingscene = false;
    }
    else
    {
        timer->start();
        playingscene = true;
    }
}

void swordwidgets::drawSword()
{
    setMaterialProperties(blade_ambient, blade_diffuse, blade_specular, blade_shininess);
    // Draw Blade
    glBegin(GL_QUADS);
    // Bottom left
    glVertex3f(-0.1f, 0.0f, 0.0f);
    // Bottom right
    glVertex3f(0.1f, 0.0f, 0.0f);
    // Top right (starting point of the triangle tip)
    glVertex3f(0.1f, 2.8f, 0.0f);
    // Top left (starting point of the triangle tip)
    glVertex3f(-0.1f, 2.8f, 0.0f);
    glEnd();

    // Tip of the Blade - A triangle
    glBegin(GL_TRIANGLES);
    // Left side of the tip
    glVertex3f(-0.1f, 2.8f, 0.0f);
    // Right side of the tip
    glVertex3f(0.1f, 2.8f, 0.0f);
    // Top point of the tip
    glVertex3f(0.0f, 3.0f, 0.0f);
    glEnd();

    glVertex3f(-0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f); // Point of the blade
    glEnd();

    setMaterialProperties(handle_ambient, handle_diffuse, handle_specular, handle_shininess);
    // Guard
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.0f, 0.05f);
    glVertex3f(0.3f, 0.0f, 0.05f);
    glVertex3f(0.3f, 0.2f, 0.05f);
    glVertex3f(-0.3f, 0.2f, 0.05f);
    glEnd();

    // Draw Hilt
    glBegin(GL_QUADS);
    // Left bottom
    glVertex3f(-0.1f, -0.6f, 0.0f);
    // Right bottom
    glVertex3f(0.1f, -0.6f, 0.0f);
    // Right top
    glVertex3f(0.1f, -0.1f, 0.0f);
    // Left top
    glVertex3f(-0.1f, -0.1f, 0.0f);
    glEnd();

    // Draw Pommel
    glBegin(GL_QUADS);
    // Left bottom
    glVertex3f(-0.15f, -0.75f, 0.0f);
    // Right bottom
    glVertex3f(0.15f, -0.75f, 0.0f);
    // Right top
    glVertex3f(0.15f, -0.6f, 0.0f);
    // Left top
    glVertex3f(-0.15f, -0.6f, 0.0f);
    glEnd();
}

void swordwidgets::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(0.0f, -0.80f, 0.0f);
    glRotatef(rotVal_, rx1, ry1, rz1);

    drawSword();

    glPopMatrix();

    rotVal_ += 3.0f;

    glFlush();
}

// Mouse Click (Interaction)
void swordwidgets::mousePressEvent(QMouseEvent *event)
{
    playPause();
    event->accept();
}

void swordwidgets::mouseDoubleClickEvent(QMouseEvent *event)
{
    playPause();
    event->accept();
}

// Rotation
void swordwidgets::l_xax(int x)
{
    if (x != rx1)
    {
        rx1 = x;
        updateGL();
    }
}

void swordwidgets::l_yax(int y)
{
    if (y != ry1)
    {
        ry1 = y;
        updateGL();
    }
}

void swordwidgets::l_zax(int z)
{
    if (z != rz1)
    {
        rz1 = z;
        updateGL();
    }
}

void swordwidgets::ang()
{
    rotVal_ += 2.0f;
    updateGL();
}

// Lighting
void swordwidgets::xax(int x)
{
    if (x != x1)
    {
        x1 = x;
        updateGL();
    }
}

void swordwidgets::yax(int y)
{
    if (y != y1)
    {
        y1 = y;
        updateGL();
    }
}

void swordwidgets::zax(int z)
{
    if (z != z1)
    {
        z1 = z;
        updateGL();
    }
}

void swordwidgets::wax(int w)
{
    if (w != w1)
    {
        w1 = w;
        updateGL();
    }
}
