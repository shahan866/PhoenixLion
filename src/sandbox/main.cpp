#include <iostream>
#include <memory>
#include <string>
#include <EH/eh.h>
class TestScreen : public EH::Component
{
public:
	void onInit(std::string color,int n)
	{
		std::cout << "onInit " << color << std::endl;
		std::cout << n << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		std::cout << "onDisplay" << std::endl;
	}
};



int main()
{
	//Initialize application, create window, add glew, and other functionality eg. sound
	std::shared_ptr<EH::Application> Engine = EH::Application::initialize();
	//add entity
	std::shared_ptr<EH::Entity> Entity = Engine->addEntity();
	//add component to entity
	std::shared_ptr<TestScreen> Test = Entity->addComponent<TestScreen>("Blue", 5);

	//start function loops through each entity, first through tick funtions of the entity's components
	//then display functions of the entity's components
	Engine->start();
	
	return 0;


return 0;
}