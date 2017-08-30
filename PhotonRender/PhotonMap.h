#ifndef PHOTONMAP_H
#define PHOTONMAP_H

#include <vector>

#include "./Maths.h"
#include "../Entities/Pixel.h"

class PhotonMap {
  public:
    void init(int resolution);
    
    void draw(std::vector<Pixel*> pixels);
    
    void keyPressed(int key, int scancode, int action, int mode);
    void mouse(double xpos, double ypos);
    void mousePressed(int button, int action, int mods);
  protected:
    Maths math;
    
    int resolution;
    
    void render();
    void resetRender();
};

#endif
