#ifndef TEXTUREDMODEL_H
#define TEXTUREDMODEL_H

#include "./RawModel.h"
#include "../textures/ModelTexture.h"

class TexturedModel {
  public:
    TexturedModel() {
      
    }
    
    void init(RawModel model, ModelTexture texture) {
      this->model = model;
      this->texture = texture;
    }
    
    RawModel getRawModel() { return model; }
    ModelTexture getTexture() { return texture; }
  protected:
    RawModel model;
    ModelTexture  texture;
};

#endif
