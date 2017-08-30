#ifndef DISPLAY_MANAGER
#define DISPLAY_MANAGER

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 800

class DisplayManager {
  public:
    int create() {
      glfwInit();
      
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      
      window = glfwCreateWindow(WIDTH, HEIGHT, "PhotonTracing", NULL, NULL);
      
      if (window == NULL) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
      }
      
      glfwMakeContextCurrent(window); 
      glewExperimental = GL_TRUE;
      if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW\n";
        return -1;
      }
      
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      glViewport(0, 0, width, height);
      return 0;
    }
    
    void update() {
      glfwSwapBuffers(window);
    }
    
    void close() {
      glfwTerminate();
    }
    
    GLFWwindow* getWindow() { return window; }
    
    bool isCloseRequested() {
      return glfwWindowShouldClose(window);
    }
    
    int getWidth() { return WIDTH; }
    int getHeight() { return HEIGHT; }
  protected:
    GLFWwindow* window;
    
    // Delta time is seconds passed since last draw
    GLfloat deltaTime = 0.0f;
    GLfloat lastTime = 0.0f;
};

#endif
