# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/asem/ProgramData/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/asem/ProgramData/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/giftWrappingAlgo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/giftWrappingAlgo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/giftWrappingAlgo.dir/flags.make

CMakeFiles/giftWrappingAlgo.dir/main.cpp.o: CMakeFiles/giftWrappingAlgo.dir/flags.make
CMakeFiles/giftWrappingAlgo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/giftWrappingAlgo.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/giftWrappingAlgo.dir/main.cpp.o -c /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/main.cpp

CMakeFiles/giftWrappingAlgo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/giftWrappingAlgo.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/main.cpp > CMakeFiles/giftWrappingAlgo.dir/main.cpp.i

CMakeFiles/giftWrappingAlgo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/giftWrappingAlgo.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/main.cpp -o CMakeFiles/giftWrappingAlgo.dir/main.cpp.s

CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.requires

CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.provides: CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/giftWrappingAlgo.dir/build.make CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.provides

CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.provides.build: CMakeFiles/giftWrappingAlgo.dir/main.cpp.o


# Object files for target giftWrappingAlgo
giftWrappingAlgo_OBJECTS = \
"CMakeFiles/giftWrappingAlgo.dir/main.cpp.o"

# External object files for target giftWrappingAlgo
giftWrappingAlgo_EXTERNAL_OBJECTS =

giftWrappingAlgo: CMakeFiles/giftWrappingAlgo.dir/main.cpp.o
giftWrappingAlgo: CMakeFiles/giftWrappingAlgo.dir/build.make
giftWrappingAlgo: CMakeFiles/giftWrappingAlgo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable giftWrappingAlgo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/giftWrappingAlgo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/giftWrappingAlgo.dir/build: giftWrappingAlgo

.PHONY : CMakeFiles/giftWrappingAlgo.dir/build

CMakeFiles/giftWrappingAlgo.dir/requires: CMakeFiles/giftWrappingAlgo.dir/main.cpp.o.requires

.PHONY : CMakeFiles/giftWrappingAlgo.dir/requires

CMakeFiles/giftWrappingAlgo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/giftWrappingAlgo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/giftWrappingAlgo.dir/clean

CMakeFiles/giftWrappingAlgo.dir/depend:
	cd /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug /home/asem/CLionProjects/сppAlgorithms/giftWrappingAlgo/cmake-build-debug/CMakeFiles/giftWrappingAlgo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/giftWrappingAlgo.dir/depend

