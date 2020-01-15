#include "Application.h"

#include "Entity.h"

namespace EH
{
	std::shared_ptr<Application> Application::initialize()
	{
    std::shared_ptr<Application> rtn = std::make_shared<Application>();
    rtn->running = false;
    rtn->self = rtn;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::exception();
    }

    rtn->window = SDL_CreateWindow("Elemental Hero Engine Demo",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      800, 600,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if (!SDL_GL_CreateContext(rtn->window))
    {
      throw std::exception();
    }

    if (glewInit() != GLEW_OK)
    {
      throw std::exception();
    }

	glEnable(GL_DEPTH_TEST);

    return rtn;
	}

	void Application::start()
	{
    running = true;

    while (running)
    {
      SDL_Event event = { 0 };

      while (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          running = false;
        }
      }


      for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
        it != entities.end(); it++)
      {
        (*it)->tick();
      }

	  float r = 0.0f;
	  float g = 0.0f;
	  float b = 0.0f;

      glClearColor(0.5f, 0.0f, 0.2f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
        it != entities.end(); it++)
      {
        (*it)->display();
      }

      SDL_GL_SwapWindow(window);
    }
	}

	void Application::stop()
	{
    running = false;
	}

	std::shared_ptr<Entity> Application::addEntity()
	{
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
    entities.push_back(rtn);
    rtn->self = rtn;
    rtn->application = self;

    return rtn;
	}


}
