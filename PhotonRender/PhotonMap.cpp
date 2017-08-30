#include "./PhotonMap.h"

void PhotonMap::init(int resolution) {
  this->resolution = resolution;
}

void PhotonMap::draw(std::vector<Pixel*> pixels) {
  for(int i = 0; i < pixels.size(); ++i) {
    pixels[i]->setColour(math.generateRandomColour());
  }
}

void PhotonMap::render() {
  
}

void PhotonMap::resetRender() {
  
}

void PhotonMap::keyPressed(int key, int scancode, int action, int mode) {
  //if (action == GLFW_PRESS && button >= 0 && button < 3)
}

void PhotonMap::mouse(double xpos, double ypos) {
  
}

void PhotonMap::mousePressed(int button, int action, int mods) {
  
}
