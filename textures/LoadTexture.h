#ifndef LOADTEXTURE
#define LOADTEXTURE

#include <string>
#include <stdio.h>
#include <stdexcept>
#include <iostream>

// GLFW
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#define TEXTURE_LOAD_ERROR 0

struct Texture {
  glm::vec2 Size;
  GLuint texture;
};

namespace txt {
  Texture LoadTexture( const char * filename ) {
    stbi_set_flip_vertically_on_load(true);
    int w;
    int h;
    int comp;
    unsigned char* image = stbi_load(filename, &w, &h, &comp, STBI_rgb_alpha);

    if(image == nullptr)
      throw std::runtime_error("Failed to load texture");
      
    GLuint m_texture;
    glGenTextures(1, &m_texture);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if(comp == 3)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    else if(comp == 4)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(image);

    Texture new_texture;
    new_texture.texture = m_texture;
    new_texture.Size.x = w;
    new_texture.Size.y = h;
    
    std::cout << "TEXTURE: " << filename << " loaded!\n";

    return new_texture;
  }
}

#endif
