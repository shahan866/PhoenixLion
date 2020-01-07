#include <memory>
#include <vector>

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

	private:
		bool running;
		std::vector<std::shared_ptr<Entity> > entities;
		std::weak_ptr<Application> self;
	};

}