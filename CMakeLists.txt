cmake_minimum_required(VERSION 3.10)
project(SimpleDrawer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 3.0 COMPONENTS Window Graphics System REQUIRED)
find_package(Eigen3 3.3 REQUIRED)

add_executable(SimpleDrawer
    main.cpp
    SimpleDrawer.cpp
)

target_link_libraries(SimpleDrawer 
    PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    Eigen3::Eigen
)