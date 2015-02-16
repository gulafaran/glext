#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GLFW/glfw3.h>

int main(int argc, char **argv) {
  if(argc < 2)
    exit(EXIT_FAILURE);

  const char *extension = argv[1];
  GLFWwindow* window;

  if(!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
  window = glfwCreateWindow(1, 1, "", NULL, NULL);

  if(!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  if(glfwExtensionSupported(extension))
    printf("EXT: %s, is supported.\n", extension);
  else
    printf("EXT: %s, is NOT supported.\n", extension);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
