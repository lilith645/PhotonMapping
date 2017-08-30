// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>

#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "./renderEngine/DisplayManager.h"
#include "./renderEngine/Loader.h"
#include "./renderEngine/Renderer.h"
#include "./models/RawModel.h"
#include "./models/ColouredModel.h"
#include "./shaders/StaticShader.h"

float mouseX;
float mouseY;
bool mousePressed[3];

bool w, a, d;

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {

  mouseX = xpos;
  mouseY = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
  
  if (action == GLFW_PRESS && button >= 0 && button < 3)
    mousePressed[button] = true;
}

void key_callback(GLFWwindow* window,
                  int key,
                  int scancode,
                  int action,
                  int mode) {
  
}

std::vector<Pixel> generatePixels(Loader* loader, int resolution) {
  std::vector<float> vertices = {
     0.0f, 1.0f,0,   //V0
     0.0f, 0.0f,0,  //V1
     1.0f, 0.0f,0,   //V2
     1.0f, 1.0f,0     //V3
  };
  
  std::vector<int> indices = {
    0,1,3,  //Top left triangle (V0,V1,V3)
    3,1,2   //Bottom right triangle (V3,V1,V2)
  };
  
  RawModel rawModel = loader->loadToVao(vertices, indices);
  
  float halfRes = resolution/2.0f;
  
  std::vector<Pixel> pixels;
  for(int i = -halfRes; i < halfRes; ++i) {
    for(int j = -halfRes; j < halfRes; ++j) {
      ColouredModel model;
      model.init(rawModel, Maths::generateRandomColour()); 
      pixels.push_back(Pixel(model, glm::vec3(i/halfRes, j/halfRes,0), 1.0f/halfRes));
    }
  }
  
  return pixels;
}

int main(int argc, char **argv) {
  
  DisplayManager display;
  
  if(display.create() == -1) {
    return -1;
  }
  
  glfwSetKeyCallback(display.getWindow(), key_callback);
  glfwSetCursorPosCallback(display.getWindow(), cursor_pos_callback);
  
  Loader loader;
  StaticShader shader;
  Renderer renderer(display.getWidth(), display.getHeight());
  
  std::vector<Pixel> pixels = generatePixels(&loader, 1024);
  
  GLfloat lastTime = 0.0f;
  
  while(!display.isCloseRequested()) {
    GLfloat current_time = glfwGetTime();
    GLfloat deltaTime = current_time - lastTime;
    lastTime = current_time;
      
    glfwPollEvents();
    
    
    
    renderer.prepare();
    shader.start();
    renderer.render(pixels, shader);
    shader.stop();
    
    display.update();
  }
  
  // Clean up after myself
  shader.clean();
  loader.clean();
  display.close();
  return 0;
}

