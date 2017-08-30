#ifndef LOADER_H
#define LOADER_H

#include <vector>

#include "../models/RawModel.h"
#include "../textures/LoadTexture.h"

class Loader {
  public:
    RawModel loadToVao(std::vector<float> positions, std::vector<float> textureCoords, std::vector<int> indices) {
      GLuint vaoID = createVao();
      bindIndicesBuffer(indices);
      storeDataInAttributeList(0, 3, positions);
      storeDataInAttributeList(1, 2, textureCoords);
      unbindVAO();
      RawModel tempModel;
      tempModel.init(vaoID, indices.size());
      return tempModel;
    }
    
    RawModel loadToVao(std::vector<float> positions, std::vector<int> indices) {
      GLuint vaoID = createVao();
      bindIndicesBuffer(indices);
      storeDataInAttributeList(0, 3, positions);
      unbindVAO();
      RawModel tempModel;
      tempModel.init(vaoID, indices.size());
      return tempModel;
    }
    
    GLuint loadTexture(std::string filename) {
      GLuint textureID = 0;
      textureID = txt::LoadTexture(filename.c_str()).texture;
      textures.push_back(textureID);
      return textureID;
    }
    
    void clean() {
      for(int i = 0; i < vaos.size(); ++i) {
        glDeleteVertexArrays(1, &vaos[i]);
      }
      for(int i = 0; i < vbos.size(); ++i) {
        glDeleteBuffers(1, &vbos[i]);
      }
      for(int i = 0; i < textures.size(); ++i) {
        glDeleteTextures(1, &textures[i]);
      }
    }
  protected:
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;
    std::vector<GLuint> textures;
    
    int createVao() {
      GLuint vaoID;
      glGenVertexArrays(1, &vaoID);
      vaos.push_back(vaoID);
      glBindVertexArray(vaoID);
      return vaoID;
    }
    
    void bindIndicesBuffer(std::vector<int> indices) {
      GLuint vboID;
      glGenBuffers(1, &vboID);
      vbos.push_back(vboID);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(int), &indices[0], GL_STATIC_DRAW);
    }
    
    void storeDataInAttributeList(int attributeNumber, int coordSize, std::vector<float> data) {
      GLuint vboID;
      glGenBuffers(1, &vboID);
      vbos.push_back(vboID);
      glBindBuffer(GL_ARRAY_BUFFER, vboID);
      glBufferData(GL_ARRAY_BUFFER, data.size()*sizeof(float), &data[0], GL_STATIC_DRAW);
      
      glVertexAttribPointer(attributeNumber, coordSize, GL_FLOAT, GL_FALSE, 0, 0);
      
      glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    void unbindVAO() {
      glBindVertexArray(0);
    }
};

#endif
