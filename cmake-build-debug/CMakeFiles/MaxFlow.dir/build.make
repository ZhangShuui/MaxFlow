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
CMAKE_COMMAND = "D:\somethin\newClion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\somethin\newClion\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zsr\CLionProjects\MaxFlow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MaxFlow.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MaxFlow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaxFlow.dir/flags.make

CMakeFiles/MaxFlow.dir/main.cpp.obj: CMakeFiles/MaxFlow.dir/flags.make
CMakeFiles/MaxFlow.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MaxFlow.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MaxFlow.dir\main.cpp.obj -c C:\Users\zsr\CLionProjects\MaxFlow\main.cpp

CMakeFiles/MaxFlow.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MaxFlow.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zsr\CLionProjects\MaxFlow\main.cpp > CMakeFiles\MaxFlow.dir\main.cpp.i

CMakeFiles/MaxFlow.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MaxFlow.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zsr\CLionProjects\MaxFlow\main.cpp -o CMakeFiles\MaxFlow.dir\main.cpp.s

# Object files for target MaxFlow
MaxFlow_OBJECTS = \
"CMakeFiles/MaxFlow.dir/main.cpp.obj"

# External object files for target MaxFlow
MaxFlow_EXTERNAL_OBJECTS =

MaxFlow.exe: CMakeFiles/MaxFlow.dir/main.cpp.obj
MaxFlow.exe: CMakeFiles/MaxFlow.dir/build.make
MaxFlow.exe: CMakeFiles/MaxFlow.dir/linklibs.rsp
MaxFlow.exe: CMakeFiles/MaxFlow.dir/objects1.rsp
MaxFlow.exe: CMakeFiles/MaxFlow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MaxFlow.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MaxFlow.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaxFlow.dir/build: MaxFlow.exe
.PHONY : CMakeFiles/MaxFlow.dir/build

CMakeFiles/MaxFlow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MaxFlow.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MaxFlow.dir/clean

CMakeFiles/MaxFlow.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zsr\CLionProjects\MaxFlow C:\Users\zsr\CLionProjects\MaxFlow C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug C:\Users\zsr\CLionProjects\MaxFlow\cmake-build-debug\CMakeFiles\MaxFlow.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MaxFlow.dir/depend

