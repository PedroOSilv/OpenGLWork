#include<GL/glew.h>
#include<glm/gtc/matrix_transform.hpp>

#include "../HeaderFiles/Primitives.h"

Light::Light(unsigned int totalLights)
{
    _total = totalLights;
}

void Light::FillBuffers()
{
    GLfloat vertices[] =
        { //     COORDINATES     //
            -0.1f, -0.1f,  0.1f,
            -0.1f, -0.1f, -0.1f,
            0.1f, -0.1f, -0.1f,
            0.1f, -0.1f,  0.1f,
            -0.1f,  0.1f,  0.1f,
            -0.1f,  0.1f, -0.1f,
            0.1f,  0.1f, -0.1f,
            0.1f,  0.1f,  0.1f
        };

    GLuint indices[] =
        {
            0, 1, 2,
            0, 2, 3,
            0, 4, 7,
            0, 7, 3,
            3, 7, 6,
            3, 6, 2,
            2, 6, 5,
            2, 5, 1,
            1, 5, 4,
            1, 4, 0,
            4, 5, 6,
            4, 6, 7
        };

    GLubyte colors[] =
    {
        //Front Red
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,

       //Back Green
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,

       //Right Blue
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,

        //Left Yellow
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,

        //Top Magenta
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,

        //Bottom Cyan
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255
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
    glBufferData(GL_ARRAY_BUFFER, _total*sizeof(glm::mat4), 0, GL_DYNAMIC_DRAW);

}

void Light::LinkBuffers()
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

            glVertexAttribDivisor(2, 1);
            glVertexAttribDivisor(3, 1);
            glVertexAttribDivisor(4, 1);
            glVertexAttribDivisor(5, 1);

        }
    }
    glBindVertexArray(0);
}

void Light::Draw()
{
    glBindVertexArray(_VAO);
    {
        // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, _total);
    }
    glBindVertexArray(0);

}

