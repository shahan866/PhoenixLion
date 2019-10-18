#include "Application.h"
#include <iostream>

std::shared_ptr <Application> Application::initialize() 
{

}
void Application::start() 
{

}
void Application::stop() 
{

}

std::shared_ptr <Entity> Application::addEntity() 
{

	std::make_shared<Entity> entities = std::make_shared<Entity>();
	this->entities.push_back(entities);

	return entities;
}

