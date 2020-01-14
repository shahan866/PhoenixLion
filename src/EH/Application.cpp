#include "Application.h"
#include "Entity.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace EH
{
	std::shared_ptr<Application> Application::initialize()
	{
		return std::shared_ptr<Application>();
	}

	void Application::start()
	{

	}

	void Application::stop()
	{
	}

	std::shared_ptr<Entity> Application::addEntity()
	{
		return std::shared_ptr<Entity>();
	}


}
