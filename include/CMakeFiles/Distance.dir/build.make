# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = D:\Documents\Northeastern\Courses\PRCV-5330\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\Documents\Northeastern\Courses\PRCV-5330\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2

# Include any dependencies generated for this target.
include include/CMakeFiles/Distance.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/Distance.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/Distance.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/Distance.dir/flags.make

include/CMakeFiles/Distance.dir/distance.cpp.obj: include/CMakeFiles/Distance.dir/flags.make
include/CMakeFiles/Distance.dir/distance.cpp.obj: include/CMakeFiles/Distance.dir/includes_CXX.rsp
include/CMakeFiles/Distance.dir/distance.cpp.obj: include/distance.cpp
include/CMakeFiles/Distance.dir/distance.cpp.obj: include/CMakeFiles/Distance.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/Distance.dir/distance.cpp.obj"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/Distance.dir/distance.cpp.obj -MF CMakeFiles\Distance.dir\distance.cpp.obj.d -o CMakeFiles\Distance.dir\distance.cpp.obj -c D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\distance.cpp

include/CMakeFiles/Distance.dir/distance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Distance.dir/distance.cpp.i"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\distance.cpp > CMakeFiles\Distance.dir\distance.cpp.i

include/CMakeFiles/Distance.dir/distance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Distance.dir/distance.cpp.s"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\distance.cpp -o CMakeFiles\Distance.dir\distance.cpp.s

# Object files for target Distance
Distance_OBJECTS = \
"CMakeFiles/Distance.dir/distance.cpp.obj"

# External object files for target Distance
Distance_EXTERNAL_OBJECTS =

include/libDistance.a: include/CMakeFiles/Distance.dir/distance.cpp.obj
include/libDistance.a: include/CMakeFiles/Distance.dir/build.make
include/libDistance.a: include/CMakeFiles/Distance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDistance.a"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\Distance.dir\cmake_clean_target.cmake
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Distance.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/Distance.dir/build: include/libDistance.a
.PHONY : include/CMakeFiles/Distance.dir/build

include/CMakeFiles/Distance.dir/clean:
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\Distance.dir\cmake_clean.cmake
.PHONY : include/CMakeFiles/Distance.dir/clean

include/CMakeFiles/Distance.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\CMakeFiles\Distance.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/Distance.dir/depend

