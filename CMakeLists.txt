cmake_minimum_required(VERSION 3.20)
project(IsaacGame)

set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_NAME IsaacGame)
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp Menu.cpp Floor.cpp Room.cpp Character.cpp Isaac.cpp Bullet.cpp Door.cpp Rock.cpp Bomb.cpp Enemy.cpp EnemyBasic.cpp Item.cpp Observer.cpp AchievementsDisplay.cpp)


#SFML
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(IsaacGame sfml-system sfml-window sfml-graphics sfml-audio)

#UNIT TEST
add_subdirectory(test)