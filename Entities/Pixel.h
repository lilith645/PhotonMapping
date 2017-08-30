#ifndef PIXEL_H
#define PIXEL_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../models/ColouredModel.h"

class Pixel {
  public:
    Pixel(ColouredModel model, glm::vec3 position, float scale) {
      this->model = model;
      this->position = position;
      this->scale = scale;
    }
    
    void setColour(glm::vec3 newColour) {
      model.setColour(newColour);
    }
    
    void setScale(float scale) {
      this->scale = scale;
    }
    
    void setPosition(glm::vec3 dxyz) {
      position += dxyz;
    }
    
    ColouredModel getModel() { return model; }
    RawModel getRawModel() { return model.getRawModel(); }
    
    glm::vec3 getColour() { return model.getColour(); }
    glm::vec3 getPosition() { return position; }
    float getScale() { return scale; }
  protected:
    ColouredModel model;
    glm::vec3 position;
    float scale;
};

#endif
