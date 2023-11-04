#include<GL/glew.h>

#include "../HeaderFiles/Primitives.h"

Octagon::Octagon(unsigned int totalOctagons)
{
    _total = totalOctagons;
}


void Octagon::FillBuffers()
{
    glm::vec3 points[] = 
    {
        glm::vec3(+0.0f, +1.f, +0.0f),//0
        glm::vec3(-0.5f, +0.f, +0.5f),//1
        glm::vec3(+0.5f, +0.f, +0.5f),//2
        glm::vec3(+0.5f, +0.f, -0.5f),//3
        glm::vec3(-0.5f, +0.f, -0.5f),//4
        glm::vec3(+0.0f, -1.f, +0.0f),//5
    };

    glm::vec3 vertices[] = 
    {
        //Front
        points[0], //Red 0
        points[1], //Red 1
        points[2], //Red 2

        //Right
        points[0],//Green 3
        points[2],//Grenn 4
        points[3],//Green 5

        //Left
        points[0],//Blue 6
        points[4],//Blue 7
        points[1],//Blue 8

        //Back
        points[0],//Yellow 9
        points[3],//Yellow 10
        points[4],//Yellow 11

        //FrontDown
        points[5], //Red 0
        points[1], //Red 1
        points[2], //Red 2

        //RightDown
        points[5],//Green 3
        points[2],//Grenn 4
        points[3],//Green 5

        //LeftDown
        points[5],//Blue 6
        points[4],//Blue 7
        points[1],//Blue 8

        //BackDown
        points[5],//Yellow 9
        points[3],//Yellow 10
        points[4],//Yellow 11

    };
    GLubyte colors[] =
    {
        //Front Red
       255, 0, 0,
       0, 150, 150,
       50, 50, 255,
       
       //Right Green
       0, 255, 0,
       100, 100, 100,
       255, 0, 100,
       
       //Left Blue
       0, 0, 255,
       125, 0, 0,
       0, 120, 255,

       //Back Yellow
       255, 255, 0,
       255, 0, 0,
       255, 100, 100,

       //FrontDown
       255, 0, 0,
       0, 0, 0,
       0, 0, 255,
       
       //RightDown
       0, 255, 0,
       255, 0, 0,
       0, 0, 255,
       
       //LeftDown
       0, 0, 255,
       0, 255, 255,
       255, 0, 0,

       //BackDown
       255, 0, 0,
       0, 255, 0,
       0, 0, 255,
    };

    unsigned int indices[] =
    {
        // Front 
         0,1,2,

         //Right  
         3,4,5,

         //Left
         6,7,8,

         //Back  
         9,10,11,

         // FrontDown
         12,13,14,

         //RightDown
         15,16,17,

         //LeftDown
         18,19,20,

         //BackDown
         21,22,23
    };

    //Fill with indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Fill with vertices
    glBindBuffer(GL_ARRAY_BUFFER, _positionVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Fill with colors
    glBindBuffer(GL_ARRAY_BUFFER, _colorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Create empty model Buffer
    glBindBuffer(GL_ARRAY_BUFFER, _modelVBO);
    glBufferData(GL_ARRAY_BUFFER, _total * sizeof(glm::mat4), 0, GL_DYNAMIC_DRAW);

}

void Octagon::LinkBuffers()
{
    glBindVertexArray(_VAO);
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

        glBindBuffer(GL_ARRAY_BUFFER, _positionVBO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

        glBindBuffer(GL_ARRAY_BUFFER, _colorVBO);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_TRUE, 3 * sizeof(GLubyte), 0);


        glBindBuffer(GL_ARRAY_BUFFER, _modelVBO);
        {
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 0));

            glEnableVertexAttribArray(3);
            glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 1));

            glEnableVertexAttribArray(4);
            glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 2));

            glEnableVertexAttribArray(5);
            glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 3));

            glEnableVertexAttribArray(6);
            glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 4));

            glEnableVertexAttribArray(7);
            glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 5));

            glEnableVertexAttribArray(8);
            glVertexAttribPointer(8, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 6));

            glVertexAttribDivisor(2, 1);
            glVertexAttribDivisor(3, 1);
            glVertexAttribDivisor(4, 1);
            glVertexAttribDivisor(5, 1);
            glVertexAttribDivisor(6, 1);
            glVertexAttribDivisor(7, 1);
            glVertexAttribDivisor(8, 1);

        }
    }
    glBindVertexArray(0);
}

void Octagon::Draw()
{
    glBindVertexArray(_VAO);
    {
        glDrawElementsInstanced(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0, _total);
    }
    glBindVertexArray(0);
}