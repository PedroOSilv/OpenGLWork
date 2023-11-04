#include <GL/glew.h>
#include <GLFW/glfw3.h>

void DrawCube( GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){
    GLfloat halfSideLength = edgeLength * 0.5;

    //Multi-colored side - FRONT
    glBegin(GL_POLYGON);

    glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);      // P1 is red
    glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);      // P2 is green
    glColor3f( 0.0, 0.0, 1.0 );     glVertex3f(centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);      // P3 is blue
    glColor3f( 1.0, 0.0, 1.0 );     glVertex3f(centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);      // P4 is purple

    glEnd();

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glEnd();

    // Purple side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);
    glVertex3f(centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);
    glVertex3f(centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glEnd();

    // Green side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength);
    glVertex3f(centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);
    glVertex3f(centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength);
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f( centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glVertex3f( centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength);
    glVertex3f( centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);
    glVertex3f( centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength);
    glEnd();
    

}