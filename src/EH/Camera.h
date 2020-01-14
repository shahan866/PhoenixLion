#pragma once

#ifndef _CAMERA_
#define _CAMERA_

#include "Component.h"

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace EH
{
  class Camera : public Component
  {
  private:
	  //Matrix Variables
	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;

  public:
	  //Initialize
	  void onInit();

	  //Setters and Getters
	  void setViewMatrix(glm::mat4 _viewMatrix) { m_ViewMatrix = _viewMatrix; }
	  void setProjectionMatrix(glm::mat4 _projectionMatrix) {}

	  glm::mat4 getViewMatrix() { return m_ViewMatrix; }
	  glm::mat4 getProjectionMatrix() { return m_ProjectionMatrix; }
  };
}

#endif // !_CAMERA_