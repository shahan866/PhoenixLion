#pragma once

#ifndef _CAMERA_
#define _CAMERA_

#include "Component.h"

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace EH
{
	/**
	*Represents the Camera Component
	*Used to render the world space from the perspective of the camera
	*/

  class Camera : public Component
  {
  private:
	  //Matrix Variables
	glm::mat4 m_ProjectionMatrix; ///< Projection Matrix
	glm::mat4 m_ViewMatrix; ///< View Matrix

  public:
	  //Initialize
	  void onInit();

	  //Setters 
	  /**
	  *\brief Sets the View Matrix of the Camera to those passed through the variable
	  */
	  void setViewMatrix(glm::mat4 _viewMatrix) { m_ViewMatrix = _viewMatrix; }
	  
	  /**
	  *\brief Sets the Projection Matrix of the Camera to those passed through the variable
	  */
	  void setProjectionMatrix(glm::mat4 _projectionMatrix) {}

	 //Getters
	 /**
	 *\brief Returns the View Matrix of the Camera
	 */
	  glm::mat4 getViewMatrix() { return m_ViewMatrix; }
	  
	  /**
	  *\brief Returns the Projection Matrix of the Camera
	  */
	  glm::mat4 getProjectionMatrix() { return m_ProjectionMatrix; }
  };
}

#endif // !_CAMERA_