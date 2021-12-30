#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(int argc, char const *argv[]){

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* windows = glfwCreateWindow(800, 600, "Hello OpenGL", NULL, NULL);

    if (!windows) {
        std::cout << "Failed to create the window " << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(windows);

    while (!glfwWindowShouldClose(windows)) { glfwPollEvents(); }

    glfwDestroyWindow(windows);
    glfwTerminate();

    int value = 25ul;
    return EXIT_SUCCESS;
}