#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

constexpr static int WINDOW_WIDTH = 4000;
constexpr static int WINDOW_HEIGHT = 4000;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


int main(int argc, char const* argv[]) {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

#if defined __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello OpenGL", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create the window " << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Loading openGL's function pointers into memory
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize glad" << std::endl;
        return -1;
    }

    // Informating openGL about the dimentions of our window.
    // The first two parameters set the location of the lower left corner of the window.
    // Behind the scenes OpenGL uses the data specified via glViewport to transform the 2D
    // coordinates it processed to coordinates on your screen. For example, a processed point of
    // location (-0.5,0.5) would (as its final transformation) be mapped to (200,450) in screen
    // coordinates. Note that processed coordinates in OpenGL are between -1 and 1 so we effectively
    // map from the range (-1 to 1) to (0, 800) and (0, 600).
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //informing openGL about window being resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
 
    //Render loop
    while (!glfwWindowShouldClose(window)) { 
        glfwSwapBuffers(window);
        glfwPollEvents(); 
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    int value = 25ul;
    return EXIT_SUCCESS;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    std::clog << "Window resized to ("<<width <<','<<height<<")\n";
    glViewport(0, 0, width, height);
}