#ifndef RENDERER_H
#define RENDERER_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../models/ColouredModel.h"
#include "../Entities/Pixel.h"
#include "../shaders/StaticShader.h"
#include "../toolbox/Maths.h"

#define FOV 70.0f
#define NEAR_PLANE 0.1f
#define FAR_PLANE 10000.0f

class Renderer {
  public:
    Renderer(int windowWidth, int windowHeight) {
      this->width = windowWidth;
      this->height = windowHeight;
    }
    
    void prepare() {
      glEnable(GL_DEPTH_TEST);
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
    }
    
    void render(std::vector<Pixel> pixels, StaticShader shader) {
      for(int i = 0; i < pixels.size(); ++i) {
        RawModel rawModel = pixels[i].getRawModel();

        glBindVertexArray(rawModel.getVaoID());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        
        shader.loadColour(pixels[i].getColour());
        shader.loadTransformation(pixels[i].getPosition(), pixels[i].getScale());
        glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0);
        
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
      }
    }
  protected:
    int width;
    int height;
};

#endif
