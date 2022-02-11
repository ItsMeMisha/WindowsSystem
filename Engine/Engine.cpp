#include "Engine.hpp"

RendererBridge* Engine::renderer = nullptr;
Window* Engine::rootWindow = nullptr;

void Engine::start() {
  while(rootWindow->isOpen()) {
    renderer->clear();
    rootWindow->render(*renderer);
    renderer->renderResult();
  }
}

void Engine::init(RendererBridge& rend, Window& rootWind) {
  renderer = &rend;
  rootWindow = &rootWind;
}

void Engine::destroy() {

}