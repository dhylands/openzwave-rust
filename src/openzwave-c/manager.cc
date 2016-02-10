#include <string>
#include "manager.h"

extern "C" {

typedef OpenZWave::Manager Manager;

Manager * manager_create() {
  return Manager::Create();
}

Manager * manager_get() {
  return Manager::Get();
}

void manager_destroy() {
  Manager::Destroy();
}

bool manager_add_watcher(Manager * manager, Manager::pfnOnNotification_t _watcher, void* _context) {
  return manager->AddWatcher(_watcher, _context);
}

bool manager_remove_watcher(Manager * manager, Manager::pfnOnNotification_t _watcher, void* _context) {
  return manager->RemoveWatcher(_watcher, _context);
}

bool manager_add_driver(Manager * manager, const char * _controllerPath, const Driver::ControllerInterface * _interface) {
  const std::string controllerPath(_controllerPath);
  return manager->AddDriver(controllerPath, *_interface);
}

bool manager_remove_driver(Manager * manager, const char * _controllerPath) {
  const std::string controllerPath(_controllerPath);
  return manager->RemoveDriver(controllerPath);
}

}
