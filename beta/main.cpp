#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include "cubeRefactor.cpp"
#include "pyramid.cpp"
#include "cylinder.cpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallBack( GLFWwindow *window, int key, int scancode, int action, int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

int main(void){
    GLFWwindow *window;

    //initialize the library
    if( !glfwInit()){
        return -1;
    }

    //Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH,SCREEN_HEIGHT, "Hello World",NULL,NULL);

    glfwSetKeyCallback(window, keyCallBack);
    glfwSetInputMode(window, GLFW_STICKY_KEYS,1);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight);

    if (!window){
        glfwTerminate( );
        return -1;
    }
    //disable face culling to render both sides of polygons
    glDisable(GL_CULL_FACE); 

    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    //Make the window's context current
    glfwMakeContextCurrent( window);

    //specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glViewport(0.0f, 0.0f, screenWidth, screenHeight);

    //projection matrix defines the properties of the camera that views the objects in the world coordinate frame.
    //here you typcally set the zoom factior, aspect ratio and the near and far clipping planes
    glMatrixMode( GL_PROJECTION);

    //replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0,0,0)
    glLoadIdentity();

    //essentially set coordinate system
    glOrtho(0,SCREEN_WIDTH,0,SCREEN_HEIGHT,-1000,1000);

    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation), rotation and scalling in your world
    glMatrixMode( GL_MODELVIEW);

    //same as above comment
    glLoadIdentity();

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT /2;

    //Loop until the user closes the window
    while ( !glfwWindowShouldClose(window)){
        glClear (GL_COLOR_BUFFER_BIT);

        //render openGL here

        glPushMatrix( );
        glTranslatef(halfScreenWidth, halfScreenHeight, -500);
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY,0,1,0);
        glTranslatef(-halfScreenWidth,-halfScreenHeight,500);

        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//how to see better the third dimension

        DrawCube (halfScreenWidth, halfScreenHeight+150, -500, 100); 

        DrawPyramid(halfScreenWidth, halfScreenHeight-150, -500, 100);

        DrawCylinder(halfScreenWidth,halfScreenHeight,-550,100,50,0,255,0);

        glPopMatrix();

        //Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
    }
    
    glfwTerminate( );
    return 0;
}

void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods){
    //std::cout <<key << std::endl;

    const GLfloat rotationSpeed = 10;

    //actions are GLFW_PRESS, GLFW_RELEASE of GLFW_REPEAT
    if( action == GLFW_PRESS || action == GLFW_REPEAT){
        switch (key)
        {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;
        }
    }
       
}

