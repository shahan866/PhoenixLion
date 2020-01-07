#include "Component.h"
#include "Entity.h"

namespace EH
{
	Component::~Component() { }
	void Component::onInit() { }
	void Component::onBegin() { }
	void Component::onTick() { }
	void Component::onDisplay() { }

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Application> Component::getApplication()
	{
		return getEntity()->getApplication();
	}

}