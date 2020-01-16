//System Includes
#include <iostream>
#include <memory>
#include <string>
//Local Includes
#include <EH/eh.h>


int main()
{
	std::cout << "EH Engine Demo" << std::endl;

	//Initialize Application, Create Window, add glew, and other functionality
	std::shared_ptr<EH::Application> Engine = EH::Application::initialize();
	
	std::cout << "Application Initialised" << std::endl;

	//Add Crate Entity
	std::shared_ptr<EH::Entity> entityCrate = Engine->addEntity();
	
	//Add Components to Crate
	std::shared_ptr<EH::Transform> transformCrate = entityCrate->addComponent<EH::Transform>();
	
	//Transformations
	transformCrate->setPosition(glm::vec3(1.0f, 1.0f, -10.0f));
	transformCrate->setIncrementRotation(glm::vec3(0.01f, 0.0f, 0.0f));
	transformCrate->setScale(glm::vec3(1.0f, 1.0f, -1.0f));
	
	//Shaders/Render/Load Textures
	std::shared_ptr<EH::Shader> shaderCrate = entityCrate->addComponent<EH::Shader>("../resources/simple.vert", "../resources/simple.frag");
	std::shared_ptr<EH::Renderer> renderCrate = entityCrate->addComponent<EH::Renderer>();
	renderCrate->loadTexture("../resources/WoodCrateTexture.jpg");

	std::cout << "Crate Created" << std::endl;

	//Purple Cube
	std::shared_ptr<EH::Entity> entityCube = Engine->addEntity();
	std::shared_ptr<EH::Transform> transformCube = entityCube->addComponent<EH::Transform>();
	transformCube->setPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	transformCube->setIncrementRotation(glm::vec3(0.01f, 0.0f, -0.01f));
	transformCube->setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	std::shared_ptr<EH::Shader> shaderCube = entityCube->addComponent<EH::Shader>("../resources/simple.vert", "../resources/simpleColour.frag");
	std::shared_ptr<EH::Renderer> renderCube = entityCube->addComponent<EH::Renderer>();

	//Elemental Hero Neos
	std::shared_ptr<EH::Entity> entityNeos = Engine->addEntity();
	std::shared_ptr<EH::Transform> transformNeos = entityNeos->addComponent<EH::Transform>();
	transformNeos->setPosition(glm::vec3(-3.0f, 1.0f, -10.0f));
	transformNeos->setIncrementRotation(glm::vec3(0.0f, 0.01f, 0.0f));
	transformNeos->setScale(glm::vec3(2.0f, 4.0f, 0.0f));
	std::shared_ptr<EH::Shader> shaderNeos = entityNeos->addComponent<EH::Shader>("../resources/simple.vert", "../resources/simple.frag");
	std::shared_ptr<EH::Renderer> renderNeos = entityNeos->addComponent<EH::Renderer>();
	renderNeos->loadTexture("../resources/BigNeos.jpg");

	std::cout << "Neos Created" << std::endl;

	//Add Entity (Camera)
	std::shared_ptr<EH::Entity> entityCamera = Engine->addEntity();
	//Add Componenets to Camera
	std::shared_ptr<EH::Transform> transformCamera = entityCamera->addComponent<EH::Transform>();
	std::shared_ptr<EH::Camera> cameraCamera = entityCamera->addComponent<EH::Camera>();

	//Start function loops through each Entity, first through OnTick funtions of the entity's components
	//then OnDisplay functions of the entity's Components
	Engine->start();
	
return 0;
}