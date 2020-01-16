#ifndef EH_COMPONENT_H
#define EH_COMPONENT_H

#include <memory>

namespace EH
{

	class Entity;
	class Application;

	/**
	*Represents Components in the CES,
	*All components inherit from this class
	*/
	class Component
	{
		friend class Entity; ///Allows the Component class to access the Entity class' private and protected members

	public:

		/**
		* \brief Destructor for a Component Object
		*/
		virtual ~Component();

		/**
		* \brief Returns a shared pointer of type Application
		*/
		std::shared_ptr<Application> getApplication();

		/**
		* \brief Returns a shared pointer of type Entity
		*/
		std::shared_ptr<Entity> getEntity();

	private:
		std::weak_ptr<Entity> entity; ///< Weak pointer of Entity
		bool began; ///< Boolean to control ticks for Components with Entity

		/**
		* \brief Virtual onInit function
		* This function can be overidden by a derived class.
		*/
		virtual void onInit();
		/**
		* \brief Virtual onBegin function
		* This function can be overidden by a derived class.
		*/
		virtual void onBegin();
		/**
		* \brief Virtual onTick function
		* This function can be overidden by a derived class.
		*/
		virtual void onTick();
		/**
		* \brief Virtual onDisplay function
		* This function can be overidden by a derived class.
		*/
		virtual void onDisplay();
	};

}

#endif