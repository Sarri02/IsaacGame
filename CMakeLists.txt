cmake_minimum_required(VERSION 3.20)
project(Isaac)

        set(CMAKE_CXX_STANDARD 14)

        add_executable(HelloSFML main.cpp Game.cpp Menu.cpp Floor.cpp Room.cpp Door.cpp Character.cpp Isaac.cpp Bullet.cpp)

        set (SFML_STATIC_LIBRARIES TRUE)
        set (SFML_DIR C:/SFML/lib/cmake/SFML)
        find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
        include_directories(C:/SFML/include)
        target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio)