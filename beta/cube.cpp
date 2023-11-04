#include <GL/glew.h>
#include <GLFW/glfw3.h>

void DrawCube( GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){
    GLfloat halfSideLength = edgeLength * 0.5;

    GLfloat vertices[]={
        // front face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //bottom left

        // back face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom left

        // left face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //top right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //bottom left 

        // right face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //bottom left 

        //top face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //bottom left 

        //bottom face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //bottom left 
    };

    GLfloat colour[] = {

        //1st face
        255, 0, 0,
        0, 255, 0,
        0, 0, 255,
        0, 0, 0,

        //2nd face
        0, 0, 255,
        0, 255, 0,
        255, 0, 0,
        0, 0, 0,

        //3rd face
        0, 0, 0,
        255, 0, 0,
        0, 255, 0,
        0, 0, 255,

        //4th face
        255, 0, 0,
        0, 0, 255,
        0, 255, 0,
        0, 0, 0,

        //5th face
        255, 0, 0,
        0, 255, 0,
        0, 0, 0,
        0, 0, 255,

        //6th face
        255, 0, 0,
        0, 0, 0,
        0, 255, 0,
        0, 0, 255,
    };

    
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//how to see better the third dimension
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer (3,GL_FLOAT,0,vertices);
    glColorPointer(3,GL_FLOAT,0,colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}