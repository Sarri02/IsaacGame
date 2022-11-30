cmake_minimum_required(VERSION 3.5)

add_subdirectory(./Lib/googletest)
set(gtest_SOURCE_DIR, ./Lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp IsaacTest.cpp  ../Game.cpp ../Menu.cpp ../Floor.cpp ../Room.cpp ../Character.cpp ../Isaac.cpp ../Bullet.cpp ../Door.cpp ../Rock.cpp ../Bomb.cpp ../Enemy.cpp ../EnemyBasic.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main)

# Detect and add SFML - to read FindSFML.cmake file
set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)

target_link_libraries(runAllTests sfml-system sfml-window sfml-graphics sfml-audio sfml-network)