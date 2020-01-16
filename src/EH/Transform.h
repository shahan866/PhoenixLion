#include "Component.h"

#include <glm\glm.hpp>

namespace EH
{

	/**
	*Represents Transform Components
	*Handles all Transformations on Entities
	*/
	class Transform : public Component
	{
	private:
		//Variables
		glm::mat4 m_Transform = glm::mat4(1.0f); ///<Initialize to Identity Matrix
		glm::vec3 m_Position; ///<Translations
		glm::vec3 m_Rotation = glm::vec3(0.0f, 0.0f, 0.0f);///<Rotations
		glm::vec3 m_IncrementRotation = glm::vec3(0.0f, 0.0f, 0.0f);///<Constant Rotations during runtime by incrementing values
		glm::vec3 m_Scale = glm::vec3(1.0f);///<Scale
		glm::vec3 m_IncrementScale = glm::vec3(0.0f, 0.0f, 0.0f);///<Scale during runtime by incremeting vlaues

	public:

		//Getters
		/**
		*\brief returns Model
		*/
		glm::mat4 getModel();
		/**
		*\brief returns Transformation
		*/
		glm::mat4 getTransform() { return m_Transform; }
		/**
		*\brief returns Position
		*/
		glm::vec3 getPosition() { return m_Position; }
		/**
		*\brief returns Rotation
		*/
		glm::vec3 getRotation() { return m_Rotation; }
		/**
		*\brief returns Rotation Increment
		*/
		glm::vec3 getIncrementRotation() { return m_IncrementRotation; }
		glm::vec3 getScale() { return m_Scale; }
		/**
		*\brief returns Increment Scale
		*/
		glm::vec3 getIncrementScale() { return m_IncrementScale; }

		void onTick();


		//Setters
		/**
		*\brief Sets the Transform to those passed through the variable
		*/
		void setTransform(glm::mat4 _transform) { m_Transform = _transform; }
		/**
		*\brief Sets the Position to those passed through the variable
		*/
		void setPosition(glm::vec3 _position) { m_Position = _position; }
		/**
		*\brief Sets the Rotation to those passed through the variable
		*/
		void setRotation(glm::vec3 _rotation) { m_Rotation = _rotation; }
		/**
		*\brief Sets the Increment Rotation to those passed through the variable
		*/
		void setIncrementRotation(glm::vec3 _incrementRotation) { m_IncrementRotation = _incrementRotation; }
		/**
		*\brief Sets the Scale to those passed through the variable
		*/
		void setScale(glm::vec3 _scale) { m_Scale = _scale; }
		/**
		*\brief Sets the IncrementScale to those passed through the variable
		*/
		void setIncrementScale(glm::vec3 _incrementScale) { m_IncrementScale = _incrementScale; }
	};
}