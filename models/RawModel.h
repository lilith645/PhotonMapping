#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <GLFW/glfw3.h>

class RawModel {
  public:
    RawModel() {
      
    }
    
    void init(GLuint vaoID, int vertexCount) {
      this->vaoID = vaoID;
      this->vertexCount = vertexCount;
    }
    
    GLuint getVaoID() { return vaoID; }
    int getVertexCount() { return vertexCount; }
  protected:
    GLuint vaoID;
    int vertexCount;
};

#endif
