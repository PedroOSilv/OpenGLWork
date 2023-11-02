#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "world/window.h"
#include "world/shader.h"

int main() {

  createWindow();

  struct Shader shader = createShader("res/shaders/main.vs", "res/shaders/main.fs");

  float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
  };

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  useShader(shader);

  while (!glfwWindowShouldClose(window.self)) {
    updateWindow();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window.self);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  terminateWindow();
   
  return 0;
}