#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Method prototype
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

int main(){

int width, height;

//Initial setup for GLFW
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

//Creates a window and makes sure GLFW initializes
GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
if(window == nullptr){
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
    }


//Makes GLFW the current context of the thread.
glfwMakeContextCurrent(window);

//Set the required callback function(s)
glfwSetKeyCallback(window, key_callback);

//Initializes GLEW
glewExperimental = GL_TRUE;
if(glewInit() != GLEW_OK){
    std::cout << "Failed to initialize GLEW" << std::endl;
    return -1;
}

//Not entirely sure but seems important
glfwGetFramebufferSize(window, &width, &height);

glViewport(0,0, width, height);

//The game loop. Huzzah!
while(!glfwWindowShouldClose(window)){
    //Check and call events
    glfwPollEvents();

    //Rendering commands
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Swap the buffers
    glfwSwapBuffers(window);

}

//Cleanup/Housekeeping
glfwTerminate();
return 0;

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){


    //Pressing the escape key closes the window
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    }



