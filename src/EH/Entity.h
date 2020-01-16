#include "Component.h"

#include <memory>
#include <vector>

#define ADDCOMPONENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->entity = self; \
  rtn->began = false; \
  components.push_back(rtn);

namespace EH
{
	
	class Application;

	/**
	*Represents our Entities in CES
	*/
	class Entity
	{
		friend class Application; ///<Allows the Entity class to access the Application class' private and protected members

	public:

		/**
		*\brief gets Components from vector list
		*/
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

				if (tst)
				{
					return tst;
				}
			}

			throw std::exception();
		}

		/**
		*\brief Sets Components to vector list on initialization 
		*/
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			ADDCOMPONENT
				rtn->onInit();

			return rtn;
		}

		/**
		*\brief adds Components to vector list on initialization
		*/
		template <typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
		{
			ADDCOMPONENT
				rtn->onInit(a);

			return rtn;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> addComponent(A a, B b)
		{
			ADDCOMPONENT
				rtn->onInit(a, b);

			return rtn;
		}

		std::shared_ptr<Application> getApplication();

	private:
		std::weak_ptr<Entity> self;
		std::weak_ptr<Application> application;
		std::vector<std::shared_ptr<Component> > components;

		void tick();
		void display();

	};

}