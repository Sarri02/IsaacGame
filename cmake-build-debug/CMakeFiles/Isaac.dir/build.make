# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\marks\Desktop\Isaac\IsaacGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Isaac.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Isaac.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Isaac.dir/flags.make

CMakeFiles/Isaac.dir/main.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/main.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Isaac.dir/main.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\main.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\main.cpp

CMakeFiles/Isaac.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/main.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\main.cpp > CMakeFiles\Isaac.dir\main.cpp.i

CMakeFiles/Isaac.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/main.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\main.cpp -o CMakeFiles\Isaac.dir\main.cpp.s

CMakeFiles/Isaac.dir/Game.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Game.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Game.cpp.obj: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Isaac.dir/Game.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Game.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Game.cpp

CMakeFiles/Isaac.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Game.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Game.cpp > CMakeFiles\Isaac.dir\Game.cpp.i

CMakeFiles/Isaac.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Game.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Game.cpp -o CMakeFiles\Isaac.dir\Game.cpp.s

CMakeFiles/Isaac.dir/Menu.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Menu.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Menu.cpp.obj: ../Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Isaac.dir/Menu.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Menu.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Menu.cpp

CMakeFiles/Isaac.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Menu.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Menu.cpp > CMakeFiles\Isaac.dir\Menu.cpp.i

CMakeFiles/Isaac.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Menu.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Menu.cpp -o CMakeFiles\Isaac.dir\Menu.cpp.s

CMakeFiles/Isaac.dir/Floor.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Floor.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Floor.cpp.obj: ../Floor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Isaac.dir/Floor.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Floor.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Floor.cpp

CMakeFiles/Isaac.dir/Floor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Floor.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Floor.cpp > CMakeFiles\Isaac.dir\Floor.cpp.i

CMakeFiles/Isaac.dir/Floor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Floor.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Floor.cpp -o CMakeFiles\Isaac.dir\Floor.cpp.s

CMakeFiles/Isaac.dir/Room.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Room.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Room.cpp.obj: ../Room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Isaac.dir/Room.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Room.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Room.cpp

CMakeFiles/Isaac.dir/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Room.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Room.cpp > CMakeFiles\Isaac.dir\Room.cpp.i

CMakeFiles/Isaac.dir/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Room.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Room.cpp -o CMakeFiles\Isaac.dir\Room.cpp.s

CMakeFiles/Isaac.dir/Character.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Character.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Character.cpp.obj: ../Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Isaac.dir/Character.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Character.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Character.cpp

CMakeFiles/Isaac.dir/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Character.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Character.cpp > CMakeFiles\Isaac.dir\Character.cpp.i

CMakeFiles/Isaac.dir/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Character.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Character.cpp -o CMakeFiles\Isaac.dir\Character.cpp.s

CMakeFiles/Isaac.dir/Isaac.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Isaac.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Isaac.cpp.obj: ../Isaac.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Isaac.dir/Isaac.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Isaac.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Isaac.cpp

CMakeFiles/Isaac.dir/Isaac.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Isaac.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Isaac.cpp > CMakeFiles\Isaac.dir\Isaac.cpp.i

CMakeFiles/Isaac.dir/Isaac.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Isaac.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Isaac.cpp -o CMakeFiles\Isaac.dir\Isaac.cpp.s

CMakeFiles/Isaac.dir/Bullet.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Bullet.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Bullet.cpp.obj: ../Bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Isaac.dir/Bullet.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Bullet.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Bullet.cpp

CMakeFiles/Isaac.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Bullet.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Bullet.cpp > CMakeFiles\Isaac.dir\Bullet.cpp.i

CMakeFiles/Isaac.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Bullet.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Bullet.cpp -o CMakeFiles\Isaac.dir\Bullet.cpp.s

CMakeFiles/Isaac.dir/Door.cpp.obj: CMakeFiles/Isaac.dir/flags.make
CMakeFiles/Isaac.dir/Door.cpp.obj: CMakeFiles/Isaac.dir/includes_CXX.rsp
CMakeFiles/Isaac.dir/Door.cpp.obj: ../Door.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Isaac.dir/Door.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Isaac.dir\Door.cpp.obj -c C:\Users\marks\Desktop\Isaac\IsaacGame\Door.cpp

CMakeFiles/Isaac.dir/Door.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Isaac.dir/Door.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marks\Desktop\Isaac\IsaacGame\Door.cpp > CMakeFiles\Isaac.dir\Door.cpp.i

CMakeFiles/Isaac.dir/Door.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Isaac.dir/Door.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marks\Desktop\Isaac\IsaacGame\Door.cpp -o CMakeFiles\Isaac.dir\Door.cpp.s

# Object files for target Isaac
Isaac_OBJECTS = \
"CMakeFiles/Isaac.dir/main.cpp.obj" \
"CMakeFiles/Isaac.dir/Game.cpp.obj" \
"CMakeFiles/Isaac.dir/Menu.cpp.obj" \
"CMakeFiles/Isaac.dir/Floor.cpp.obj" \
"CMakeFiles/Isaac.dir/Room.cpp.obj" \
"CMakeFiles/Isaac.dir/Character.cpp.obj" \
"CMakeFiles/Isaac.dir/Isaac.cpp.obj" \
"CMakeFiles/Isaac.dir/Bullet.cpp.obj" \
"CMakeFiles/Isaac.dir/Door.cpp.obj"

# External object files for target Isaac
Isaac_EXTERNAL_OBJECTS =

Isaac.exe: CMakeFiles/Isaac.dir/main.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Game.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Menu.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Floor.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Room.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Character.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Isaac.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Bullet.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/Door.cpp.obj
Isaac.exe: CMakeFiles/Isaac.dir/build.make
Isaac.exe: libcore.a
Isaac.exe: C:/SFML/lib/libsfml-system-s-d.a
Isaac.exe: C:/SFML/lib/libsfml-window-s-d.a
Isaac.exe: C:/SFML/lib/libsfml-graphics-s-d.a
Isaac.exe: C:/SFML/lib/libsfml-audio-s-d.a
Isaac.exe: C:/SFML/lib/libsfml-window-s-d.a
Isaac.exe: C:/SFML/lib/libfreetype.a
Isaac.exe: C:/SFML/lib/libsfml-system-s-d.a
Isaac.exe: C:/SFML/lib/libopenal32.a
Isaac.exe: C:/SFML/lib/libvorbisfile.a
Isaac.exe: C:/SFML/lib/libvorbisenc.a
Isaac.exe: C:/SFML/lib/libvorbis.a
Isaac.exe: C:/SFML/lib/libogg.a
Isaac.exe: C:/SFML/lib/libFLAC.a
Isaac.exe: CMakeFiles/Isaac.dir/linklibs.rsp
Isaac.exe: CMakeFiles/Isaac.dir/objects1.rsp
Isaac.exe: CMakeFiles/Isaac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Isaac.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Isaac.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Isaac.dir/build: Isaac.exe
.PHONY : CMakeFiles/Isaac.dir/build

CMakeFiles/Isaac.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Isaac.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Isaac.dir/clean

CMakeFiles/Isaac.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\marks\Desktop\Isaac\IsaacGame C:\Users\marks\Desktop\Isaac\IsaacGame C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug C:\Users\marks\Desktop\Isaac\IsaacGame\cmake-build-debug\CMakeFiles\Isaac.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Isaac.dir/depend

