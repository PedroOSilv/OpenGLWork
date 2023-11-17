#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
using namespace std;

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include<random>

#include"Error.cpp"
#include"Shader.cpp"
#include"Primitives.cpp"
#include"Camera.cpp"
#include"Terrain.cpp"
#include"Cube.cpp"
#include"Pyramid.cpp"
#include"Octagon.cpp"
#include"Light.cpp"

GLFWwindow* window;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const unsigned int TOTAL_CUBES = 1;
const unsigned int TOTAL_PYRAMIDS = 0;
const unsigned int TOTAL_OCTAGONS = 0;

Camera camera;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


void initOpenGL()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        fatalError("GLFW could not be initialized");
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Formulas", NULL, NULL);
    if (!window)
    {
        fatalError("GLFW Window could not be created!");
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fatalError("Error loading GLEW extensions!");
    }

    glEnable(GL_DEPTH_TEST);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
}

float genRandom(float a, float b)
{
    std::random_device rd;
    int seed = rd();
    std::mt19937 rd_gen(seed);
    std::uniform_real_distribution<float> u_dist(a, b);

    //cout << "valor entre 0 e 20: "<< static_cast<int>(u_dist(rd_gen)) % 20 << "\n";

    return fmod(static_cast<int>(u_dist(rd_gen)), 5);
}

int main()
{
    initOpenGL();

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(-3.0f, 3.0f, 0.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

    //light Shader
    Shader lightShader("../Shaders/Light.vs", "../Shaders/Light.fs");
    lightShader.CreateShaders();

    //Model Matrix  with Frequent Changes
    Shader mainShader("../Shaders/Main.vs", "../Shaders/Main.fs");
    mainShader.CreateShaders();

    //model Matrix  with Minor Changes
    Shader minorShader("../Shaders/Minor.vs", "../Shaders/Main.fs");
    minorShader.CreateShaders();

    Cube cube(TOTAL_CUBES);
    cube.Create();

    Pyramid pyramid(TOTAL_PYRAMIDS);
    pyramid.Create();

    Octagon octagon(TOTAL_PYRAMIDS);
    octagon.Create();

    Terrain terrain(250.f);
    terrain.Create();

    float aspectRatio = static_cast<float>(WINDOW_WIDTH) / WINDOW_HEIGHT;
    glm::mat4 projection = glm::perspective(glm::radians(45.f), aspectRatio, 0.1f, 500.f);
   
    mainShader.Bind();
    mainShader.SendUniformData("projection", projection);
    mainShader.SendUniformLight("lightColor",lightColor);
    mainShader.SendUniformLightPos("lightPos",lightPos);
    mainShader.Unbind();

    lightShader.Bind();
    lightShader.SendUniformData("model", lightModel);
    lightShader.SendUniformLight("lightColor",lightColor);
    lightShader.Unbind();

    minorShader.Bind();
    minorShader.SendUniformData("projection", projection);
    minorShader.SendUniformData("model", glm::mat4(1.f));
    minorShader.Unbind();


    // Initialize Position Matrix
    glm::mat4* cubesPosMatrix = new glm::mat4[TOTAL_CUBES];
    glm::mat4* pyramidsPosMatrix = new glm::mat4[TOTAL_PYRAMIDS];
    glm::mat4* octagonsPosMatrix = new glm::mat4[TOTAL_OCTAGONS];

    // Generate Objects Positions
    {
        // Cubes Positions
        for (int i = 0; i < (int)TOTAL_CUBES; i++)
        {
            // float x = genRandom(-200.f, 200.f);
            // float y = genRandom(3.f, 10.f);
            // float z = genRandom(-200.f, 200.f);

            //actually not randonly generated
            cubesPosMatrix[i] = glm::translate(glm::vec3(0, 0, -2));
        }

        //Pyramids Positions
        for (int i = 0; i < (int)TOTAL_PYRAMIDS; i++)
        {
            float x = genRandom(-200.f, 200.f);
            float y = genRandom(3.f, 15.f);
            float z = genRandom(-200.f, 200.f);
            pyramidsPosMatrix[i] = glm::translate(glm::vec3(x, y, z));
        }

        //Octagons Positions
        for (int i = 0; i < (int)TOTAL_OCTAGONS; i++)
        {
            float x = genRandom(-200.f, 200.f);
            float y = genRandom(3.f, 15.f);
            float z = genRandom(-200.f, 200.f);
            octagonsPosMatrix[i] = glm::translate(glm::vec3(x, y, z));
        }
    }

    // Initialize Angular Speed - Axis X, Y and Z
    glm::vec3* cubeAngSpeed = new glm::vec3[TOTAL_CUBES];
    glm::vec3* pyramidAngSpeed = new glm::vec3[TOTAL_PYRAMIDS];
    glm::vec3* octagonAngSpeed = new glm::vec3[TOTAL_OCTAGONS];

    // Angular Speed
    {
        //Cube
        for (int i = 0; i < (int)TOTAL_CUBES; i++)
        {
            // float x = genRandom(-2.75f, -1.75f);
            // float y = genRandom(1.f, 3.f);
            // float z = genRandom(+1.f, 2.75f);
            //not rotating
            cubeAngSpeed[i] = glm::vec3(0, 1, 0);
        }

        //Pyramid
        for (int i = 0; i < (int)TOTAL_PYRAMIDS; i++)
        {
            float x = genRandom(+1.f, 2.75f);
            float y = genRandom(1.5f, 3.25f);
            float z = genRandom(-2.5f, -1.5f);

            pyramidAngSpeed[i] = glm::vec3(x, y, z);
        }

        //Octagons
        for (int i = 0; i < (int)TOTAL_OCTAGONS; i++)
        {
            float x = genRandom(+1.f, 2.75f);
            float y = genRandom(1.5f, 3.25f);
            float z = genRandom(-2.5f, -1.5f);

            octagonAngSpeed[i] = glm::vec3(x, y, z);
        }
    }


    // Initialize Model Matrix
    glm::mat4* cubeModels = new glm::mat4[TOTAL_CUBES];
    glm::mat4* pyramidModels = new glm::mat4[TOTAL_PYRAMIDS];
    glm::mat4* octagonModels = new glm::mat4[TOTAL_OCTAGONS];


    unsigned int cubeModelVBO = cube.GetModelVBO();
    unsigned int pyramidModelVBO = pyramid.GetModelVBO();
    unsigned int octagonModelVBO = octagon.GetModelVBO();

    float startTime = (float)glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {

        float currentTime = (float)glfwGetTime();
        float dt = (currentTime - startTime)/2;

        glm::mat4 viewMatrix = camera.ativar();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Light Render
        {

            lightShader.Bind();
            lightShader.SendUniformData("camMatrix", viewMatrix);
            lightShader.Unbind();
        }

        //Terrain Render
        {

            minorShader.Bind();
            minorShader.SendUniformData("view", viewMatrix);
            terrain.Draw();
            minorShader.Unbind();
        }
        

        mainShader.Bind();
        {
            mainShader.SendUniformData("view", viewMatrix);
            mainShader.SendUniformLightPos("camPos", camera._position);
            //Cube 
            {
                for (unsigned int i = 0; i < (int)TOTAL_CUBES; i++)
                {
                    cubeModels[i] = glm::rotate(cubeAngSpeed[i].x * dt, glm::vec3(1.f, 0.f, 0.f));
                    cubeModels[i] = glm::rotate(cubeModels[i], cubeAngSpeed[i].y * dt, glm::vec3(0.f, 1.f, 0.f));
                    cubeModels[i] = cubesPosMatrix[i] * glm::rotate(cubeModels[i], cubeAngSpeed[i].z * dt, glm::vec3(0.f, 0.f, 1.f));
                }

                // Update Matrix Buffer
                glBindBuffer(GL_ARRAY_BUFFER, cubeModelVBO);
                glBufferSubData(GL_ARRAY_BUFFER, 0, TOTAL_CUBES * sizeof(glm::mat4), cubeModels);

                cube.Draw();

            }

            //Pyramid 
            {
                for (unsigned int i = 0; i < (int)TOTAL_PYRAMIDS; i++)
                {
                    pyramidModels[i] = glm::rotate(pyramidAngSpeed[i].x * dt, glm::vec3(1.f, 0.f, 0.f));
                    pyramidModels[i] = glm::rotate(pyramidModels[i], pyramidAngSpeed[i].y * dt, glm::vec3(0.f, 1.f, 0.f));
                    pyramidModels[i] = pyramidsPosMatrix[i] * glm::rotate(pyramidModels[i], pyramidAngSpeed[i].z * dt, glm::vec3(0.f, 0.f, 1.f));
                }

                // Update Matrix Buffer
                glBindBuffer(GL_ARRAY_BUFFER, pyramidModelVBO);
                glBufferSubData(GL_ARRAY_BUFFER, 0, TOTAL_PYRAMIDS * sizeof(glm::mat4), pyramidModels);

                pyramid.Draw();
            }

            //Pyramid 
            {
                for (unsigned int i = 0; i < (int)TOTAL_OCTAGONS; i++)
                {
                    octagonModels[i] = glm::rotate(octagonAngSpeed[i].x * dt, glm::vec3(1.f, 0.f, 0.f));
                    octagonModels[i] = glm::rotate(octagonModels[i], octagonAngSpeed[i].y * dt, glm::vec3(0.f, 1.f, 0.f));
                    octagonModels[i] = octagonsPosMatrix[i] * glm::rotate(octagonModels[i], pyramidAngSpeed[i].z * dt, glm::vec3(0.f, 0.f, 1.f));
                }

                // Update Matrix Buffer
                glBindBuffer(GL_ARRAY_BUFFER, octagonModelVBO);
                glBufferSubData(GL_ARRAY_BUFFER, 0, TOTAL_OCTAGONS * sizeof(glm::mat4), octagonModels);

                octagon.Draw();
            }



        }

        mainShader.Unbind();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete[] cubeModels;
    delete[] cubesPosMatrix;
    delete[] cubeAngSpeed;

    delete[] pyramidModels;
    delete[] pyramidsPosMatrix;
    delete[] pyramidAngSpeed;

    glfwTerminate();
    return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        // Forward
        camera.moveForward();
    }
    else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        // Back
        camera.moveBack();

    }
    else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        // Left
        camera.moveLeft();

    }
    else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        // Right
        camera.moveRight();
    }

}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    camera.mouseUpdate(glm::vec2(xpos, ypos));
}