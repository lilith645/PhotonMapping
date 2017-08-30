#ifndef MODELCOLOUR_H
#define MODELCOLOUR_H

class ModelColour {
  public:
    ModelColour() {
      colour = glm::vec3(0);
    }
    
    void init(glm::vec3 id) {
      colour = id;
    }
    
    glm::colour getColour() {
      return colour;
    }
  protected:
    glm::vec3 colour;
};

#endif
