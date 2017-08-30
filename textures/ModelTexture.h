#ifndef MODELTEXTURE_H
#define MODELTEXTURE_H

class ModelTexture {
  public:
    ModelTexture() {
      textureID = 0;
    }
    
    void init(GLuint id) {
      textureID = id;
    }
    
    GLuint getID() {
      return textureID;
    }
  protected:
    GLuint textureID;
};

#endif
