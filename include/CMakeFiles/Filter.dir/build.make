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
include include/CMakeFiles/Filter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/Filter.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/Filter.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/Filter.dir/flags.make

include/CMakeFiles/Filter.dir/filter.cpp.obj: include/CMakeFiles/Filter.dir/flags.make
include/CMakeFiles/Filter.dir/filter.cpp.obj: include/CMakeFiles/Filter.dir/includes_CXX.rsp
include/CMakeFiles/Filter.dir/filter.cpp.obj: include/filter.cpp
include/CMakeFiles/Filter.dir/filter.cpp.obj: include/CMakeFiles/Filter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/Filter.dir/filter.cpp.obj"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/Filter.dir/filter.cpp.obj -MF CMakeFiles\Filter.dir\filter.cpp.obj.d -o CMakeFiles\Filter.dir\filter.cpp.obj -c D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\filter.cpp

include/CMakeFiles/Filter.dir/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Filter.dir/filter.cpp.i"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\filter.cpp > CMakeFiles\Filter.dir\filter.cpp.i

include/CMakeFiles/Filter.dir/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Filter.dir/filter.cpp.s"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\filter.cpp -o CMakeFiles\Filter.dir\filter.cpp.s

# Object files for target Filter
Filter_OBJECTS = \
"CMakeFiles/Filter.dir/filter.cpp.obj"

# External object files for target Filter
Filter_EXTERNAL_OBJECTS =

include/libFilter.a: include/CMakeFiles/Filter.dir/filter.cpp.obj
include/libFilter.a: include/CMakeFiles/Filter.dir/build.make
include/libFilter.a: include/CMakeFiles/Filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libFilter.a"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\Filter.dir\cmake_clean_target.cmake
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Filter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/Filter.dir/build: include/libFilter.a
.PHONY : include/CMakeFiles/Filter.dir/build

include/CMakeFiles/Filter.dir/clean:
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\Filter.dir\cmake_clean.cmake
.PHONY : include/CMakeFiles/Filter.dir/clean

include/CMakeFiles/Filter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\CMakeFiles\Filter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/Filter.dir/depend

