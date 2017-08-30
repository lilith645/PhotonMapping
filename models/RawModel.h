#ifndef RAWMODEL_H
#define RAWMODEL_H

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
