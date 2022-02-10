#include "Engine.hpp"

RendererBridge* Engine::renderer = nullptr;
Window* Engine::rootWindow = nullptr;

#include <cstdio>
void Engine::start() {
  while(true)
    rootWindow->render(*renderer);
}

void Engine::init(RendererBridge& rend, Window& rootWind) {
  renderer = &rend;
  rootWindow = &rootWind;
}

void Engine::destroy() {

}