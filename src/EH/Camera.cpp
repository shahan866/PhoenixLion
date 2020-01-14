#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Application.h"

namespace EH
{
	void Camera::onInit()
	{
		glm::vec3 _pos = getEntity()->getComponent<Transform>()->getPosition();
		glm::vec3 _front = getEntity()->getComponent<Transform>()->getFront();
		glm::vec3 _up = getEntity()->getComponent<Transform>()->getUp();

	}
}