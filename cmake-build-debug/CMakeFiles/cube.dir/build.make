# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/anuj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/anuj/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anuj/CLionProjects/cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anuj/CLionProjects/cube/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cube.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cube.dir/flags.make

CMakeFiles/cube.dir/main.c.o: CMakeFiles/cube.dir/flags.make
CMakeFiles/cube.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anuj/CLionProjects/cube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cube.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cube.dir/main.c.o   -c /home/anuj/CLionProjects/cube/main.c

CMakeFiles/cube.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cube.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anuj/CLionProjects/cube/main.c > CMakeFiles/cube.dir/main.c.i

CMakeFiles/cube.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cube.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anuj/CLionProjects/cube/main.c -o CMakeFiles/cube.dir/main.c.s

# Object files for target cube
cube_OBJECTS = \
"CMakeFiles/cube.dir/main.c.o"

# External object files for target cube
cube_EXTERNAL_OBJECTS =

cube: CMakeFiles/cube.dir/main.c.o
cube: CMakeFiles/cube.dir/build.make
cube: CMakeFiles/cube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anuj/CLionProjects/cube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cube.dir/build: cube

.PHONY : CMakeFiles/cube.dir/build

CMakeFiles/cube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cube.dir/clean

CMakeFiles/cube.dir/depend:
	cd /home/anuj/CLionProjects/cube/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anuj/CLionProjects/cube /home/anuj/CLionProjects/cube /home/anuj/CLionProjects/cube/cmake-build-debug /home/anuj/CLionProjects/cube/cmake-build-debug /home/anuj/CLionProjects/cube/cmake-build-debug/CMakeFiles/cube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cube.dir/depend

