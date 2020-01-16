#include <iostream>
#include <memory>
#include <string>
#include <EH/eh.h>

/*class TestScreen : public EH::Component
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
};*/



int main()
{
	std::cout << "EH Engine Demo" << std::endl;

	//Initialize application, create window, add glew, and other functionality eg. sound
	std::shared_ptr<EH::Application> Engine = EH::Application::initialize();
	
	std::cout << "Application Initialised" << std::endl;

	//Add Entity (Cube 1, Crate)
	std::shared_ptr<EH::Entity> entityCube = Engine->addEntity();
	//Add Components to Cube 1
	std::shared_ptr<EH::Transform> transformCube = entityCube->addComponent<EH::Transform>();
	//Transformations
	//entityCube->getComponent<EH::Transform>()-> setPosition(glm::vec3(1.0f, 1.0f, -8.0f));
	transformCube->setPosition(glm::vec3(1.0f, 1.0f, -20.0f));
	entityCube->getComponent<EH::Transform>()->setRotation(glm::vec3(2.0f, 0.0f, 0.0f));
	entityCube->getComponent<EH::Transform>()->setIncrementRotation(glm::vec3(0.01f, 0.0f, 0.0f));
	entityCube->getComponent<EH::Transform>()->setScale(glm::vec3(1.0f, 1.0f, -1.0f));
	//Shaders/Render/Load Textures
	std::shared_ptr<EH::Shader> shaderCube = entityCube->addComponent<EH::Shader>("../resources/simple.vert", "../resources/simple.frag");
	std::shared_ptr<EH::Renderer> renderCube = entityCube->addComponent<EH::Renderer>();
	renderCube->loadTexture("../resources/WoodCrateTexture.jpg");

	//Add Entity (Camera)
	std::shared_ptr<EH::Entity> entityCamera = Engine->addEntity();
	//Add Componenets to Camera
	std::shared_ptr<EH::Transform> transformCamera = entityCamera->addComponent<EH::Transform>();
	std::shared_ptr<EH::Camera> cameraCamera = entityCamera->addComponent<EH::Camera>();

	//start function loops through each entity, first through tick funtions of the entity's components
	//then display functions of the entity's components
	Engine->start();
	
return 0;
}