cmake_minimum_required(VERSION 3.20)
project(Isaac)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_NAME Isaac)
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp Menu.cpp Floor.cpp Room.cpp Door.cpp Character.cpp Isaac.cpp Bullet.cpp)

#UNIT TEST
add_subdirectory(test)

set(SOURCE_FILES Game.cpp Menu.cpp Floor.cpp Room.cpp Door.cpp Character.cpp Isaac.cpp Bullet.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Isaac core)

#SFML
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(Isaac sfml-system sfml-window sfml-graphics sfml-audio)