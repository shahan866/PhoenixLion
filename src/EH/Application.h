#include <memory>
#include <vector>

#include <GL/glew.h>
#include <SDL2\SDL.h>

namespace EH
{
	class Entity;

	/**
	*The main system loop of our engine
	*/

	class Application
	{
	public: 
		/**
		\brief Initialize Application
		*/
		static std::shared_ptr<Application> initialize();

		/**
		\Start Application
		*/
		void start();

		/**
		\brief Stop Application
		*/
		void stop();

		/**
		\brief Create a new Entity
		*/
		std::shared_ptr<Entity> addEntity();

		const float m_WindowWidth = 800; ///<Window Width
		const float m_WindowHeight = 600; ///<Window Height

	private:
		bool running; ///<Bool to check if Application is running
		std::vector<std::shared_ptr<Entity> > entities; ///<vector list of entites
		std::weak_ptr<Application> self; ///<Weak Pointer to Application

		SDL_Window *window; ///<Pointer for SDL Window

	};

}