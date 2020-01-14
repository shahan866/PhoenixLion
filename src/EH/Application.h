#include <memory>
#include <vector>

#include <GL/glew.h>
#include <SDL2\SDL.h>

namespace EH
{

	class Entity;

	class Application
	{
	public: 
		static std::shared_ptr<Application> initialize();

		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

		const float m_WindowWidth = 800;
		const float m_WindowHeight = 600;

	private:
		bool running;
		std::vector<std::shared_ptr<Entity> > entities;
		std::weak_ptr<Application> self;

		SDL_Window *window;

	};

}