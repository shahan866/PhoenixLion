#include <memory>
#include <lists>

class Entity;

class Application {

public:
	Application();
	~Application();

	static std::shared_ptr <Application> initialize();
	void start();
	void stop();
	std::shared_ptr <Entity> addEntity();

private: 
	std::list <std::shared_ptr <Entity>> entities;
	std::shared_ptr <Environment> environment;
	std::shared_ptr <Keyboard> keyboard;
	bool running;

};
