#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#define PI 3.1415927

void DrawCylinder(GLfloat centerPosX,
                  GLfloat centerPosY,
                  GLfloat centerPosZ,
                  GLfloat height,
                  GLfloat radius,
                  GLubyte R,
                  GLubyte G,
                  GLubyte B ){

    GLfloat x              = 0;
    GLfloat y              = 0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
    

    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(centerPosX + x, centerPosY + y , centerPosZ+height);
            glVertex3f(centerPosX + x, centerPosY + y , centerPosZ);
            angle = angle + angle_stepsize;
        }
        glVertex3f(centerPosX + radius, centerPosY, centerPosZ+height);
        glVertex3f(centerPosX + radius, centerPosY, centerPosZ);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(centerPosX + x, centerPosY + y , centerPosZ+ height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(centerPosX + radius, centerPosY, centerPosZ+height);
    glEnd();

}