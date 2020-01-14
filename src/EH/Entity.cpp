#include "Entity.h"

namespace EH
{

	std::shared_ptr<Application> Entity::getApplication()
	{
		return application.lock();
	}

	void Entity::tick()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			if (!(*it)->began)
			{
				(*it)->onBegin();
				(*it)->began = true;
			}

			(*it)->onTick();
		}
	}

	void Entity::display()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

}