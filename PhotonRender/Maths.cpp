#include "./Maths.h"

glm::vec3 Maths::generateRandomColour() { 
  return glm::vec3(std::rand()%10/10.0, std::rand()%10/10.0, std::rand()%10/10.0);
}
