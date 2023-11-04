#include <GL/glew.h>
#include <GLFW/glfw3.h>

void DrawPyramid( GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){
    GLfloat halfSideLength = edgeLength * 0.5;

    GLfloat verticesBaseFace[]={
        // base face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom left
    };

    GLfloat colourBaseFace[]={
        // base face
        255,0,0,
        0,255,0,
        0,0,255,
        255,255,255
    };

    GLfloat verticesRightFace[]={
        // right face
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX, centerPosY + halfSideLength, centerPosZ, //top center

    };

    GLfloat colourRightFace[]={
        // right face
        0, 255, 0, 
        0, 0, 255, 
        255, 0, 0,
    };

    GLfloat verticesFrontFace[]={
        // front face
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom left
        centerPosX, centerPosY + halfSideLength, centerPosZ, //top center

    };

    GLfloat colourFrontFace[]={
        // front face
        0, 255, 0, 
        255, 0, 0,
        0, 0, 255, 
    };

    GLfloat verticesLeftFace[]={
        // left face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //bottom left
        centerPosX, centerPosY + halfSideLength, centerPosZ, //top center

    };

    GLfloat colourLeftFace[]={
        // Left face
        0, 0, 255, 
        0, 255, 0, 
        255, 0, 0,
    };

    GLfloat verticesBackFace[]={

        // back face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //top right
        centerPosX, centerPosY + halfSideLength, centerPosZ, //top center

    };

    GLfloat colourBackFace[]={
        // right face
        255, 255, 255, 
        255, 0, 0,
        0, 0, 255, 
    };
    
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//how to see better the third dimension
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    //base face
    glVertexPointer (3,GL_FLOAT,0,verticesBaseFace);
    glDrawArrays(GL_QUADS, 0, 4);
    glColorPointer(3,GL_FLOAT,0,colourBaseFace);

    //right face
    glVertexPointer (3,GL_FLOAT,0,verticesRightFace);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColorPointer(3,GL_FLOAT,0,colourRightFace);

    //front face
    glVertexPointer (3,GL_FLOAT,0,verticesFrontFace);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColorPointer(3,GL_FLOAT,0,colourFrontFace);

    //left
    glVertexPointer (3,GL_FLOAT,0,verticesLeftFace);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColorPointer(3,GL_FLOAT,0,colourLeftFace);

    //back
    glVertexPointer (3,GL_FLOAT,0,verticesBackFace);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColorPointer(3,GL_FLOAT,0,colourBackFace);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    //glEnable(GL_CULL_FACE);
}