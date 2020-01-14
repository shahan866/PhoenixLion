#ifndef EH_COMPONENT_H
#define EH_COMPONENT_H

#include <memory>

namespace EH
{

  class Entity;
  class Application;

  class Component
  {
    friend class Entity;

  public:
    virtual ~Component();
    std::shared_ptr<Application> getApplication();
    std::shared_ptr<Entity> getEntity();

  private:
    std::weak_ptr<Entity> entity;
    bool began;

    virtual void onInit();
    virtual void onBegin();
    virtual void onTick();
    virtual void onDisplay();
  };

}

#endif