#ifndef MATHS_H
#define MATHS_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Maths {
  glm::mat4 createTransformationMatrix(glm::vec3 translation, float scale) {
    glm::mat4 model = glm::mat4(1);
    
    model = glm::translate(model, translation);
    
    model = glm::scale(model, glm::vec3(scale));
    
    return model;
  }
  
  glm::vec3 generateRandomColour() { 
    return glm::vec3(std::rand()%10/10.0, std::rand()%10/10.0, std::rand()%10/10.0);
  }
}

#endif
