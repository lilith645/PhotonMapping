#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./ShaderProgram.h"

class StaticShader: public ShaderProgram {
  public:
    StaticShader() {
      init(vertex_file, fragment_file);
    }
    
    void loadTransformation(glm::vec3 position, float scale) {
      loadMatrix(location_transformation, createTransformationMatrix(position, scale));
    }
    
    void loadColour(glm::vec3 colour) {
      loadVector(location_colour, colour);
    }
    
    void loadProjection(glm::mat4 projection) {
      loadMatrix(location_projection, projection);
    }
  protected:
    int location_colour;
    int location_transformation;
    int location_projection;
    
    std::string vertex_file = "./shaders/shader.vert";
    std::string fragment_file = "./shaders/shader.frag";
    
    void getAllUniformLocations() {
      location_colour = getUniformLocation("inColour");
      location_transformation = getUniformLocation("transformation");
      location_projection = getUniformLocation("projection");
    }
    
    void bindAttributes() {
      bindAttribute(0, "position");
    }
};

#endif
