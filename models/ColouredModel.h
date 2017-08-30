#ifndef COLOUREDMODEL_H
#define COLOUREDMODEL_H

#include "./RawModel.h"

class ColouredModel {
  public:
    ColouredModel() {
      
    }
    
    void init(RawModel model, glm::vec3 colour) {
      this->model = model;
      this->colour = colour;
    }
    
    void setColour(glm::vec3 newColour) {
      colour = newColour;
    }
    
    RawModel getRawModel() { return model; }
    glm::vec3 getColour() { return colour; }
  protected:
    RawModel model;
    glm::vec3 colour;
};

#endif
