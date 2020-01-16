#include "Component.h"

#include <glm\glm.hpp>

namespace EH
{
  class Transform : public Component
  {
  private:
    //Variables
	//Initialize to Identity Matrix
    glm::mat4 m_Transform = glm::mat4(1.0f); 
    glm::vec3 m_Position;
	glm::vec3 m_Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_IncrementRotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_Scale = glm::vec3(1.0f);

  public:

    //Getters
    glm::mat4 getModel();
    glm::mat4 getTransform() { return m_Transform; }
    glm::vec3 getPosition() { return m_Position; }
    glm::vec3 getRotation() { return m_Rotation; }
	glm::vec3 getIncrementRotation() { return m_IncrementRotation; }
    glm::vec3 getScale() { return m_Scale; }

	void onTick();


    //Setters
    void setTransform(glm::mat4 _transform) { m_Transform = _transform; }
    void setPosition(glm::vec3 _position) { m_Position = _position; }
    void setRotation(glm::vec3 _rotation) { m_Rotation = _rotation; }
	void setIncrementRotation(glm::vec3 _incrementRotation) { m_IncrementRotation = _incrementRotation; }
    void setScale(glm::vec3 _scale) { m_Scale = _scale; }
  };
}