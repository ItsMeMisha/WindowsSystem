cmake_minimum_required(VERSION 3.10)

project(WindowsSystem VERSION 0.1)

add_executable(App main.cpp)

add_subdirectory(Engine)
add_subdirectory(Renderer)
add_subdirectory(SFMLRenderer)
add_subdirectory(Shape)
add_subdirectory(Utility)
add_subdirectory(Window)

find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(App sfml-system sfml-window sfml-graphics 
  Utility Shape Window Engine RendererBridge SFMLRenderer)