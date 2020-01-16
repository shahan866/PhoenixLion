#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "stb_image.h"
#include "Component.h"

#include <iostream>
#include <vector>

namespace EH
{
	/**
	*Represents Renderer Component
	*/

  class Renderer : public Component
  {
  public:

    unsigned int VAO; ///<Vertex Array Object

	/**
	*\breif Loads Texture using file paths given
	*/
    void loadTexture(char const * path);

    void onInit();
    void onDisplay();

  private:
    unsigned int VBO; ///<Vertex Buffer Object
    unsigned int texture; ///<Texture Varirable
  };
}
#endif