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
include include/CMakeFiles/CSV_UTIL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/CMakeFiles/CSV_UTIL.dir/compiler_depend.make

# Include the progress variables for this target.
include include/CMakeFiles/CSV_UTIL.dir/progress.make

# Include the compile flags for this target's objects.
include include/CMakeFiles/CSV_UTIL.dir/flags.make

include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj: include/CMakeFiles/CSV_UTIL.dir/flags.make
include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj: include/CMakeFiles/CSV_UTIL.dir/includes_CXX.rsp
include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj: include/csv_util.cpp
include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj: include/CMakeFiles/CSV_UTIL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj -MF CMakeFiles\CSV_UTIL.dir\csv_util.cpp.obj.d -o CMakeFiles\CSV_UTIL.dir\csv_util.cpp.obj -c D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\csv_util.cpp

include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSV_UTIL.dir/csv_util.cpp.i"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\csv_util.cpp > CMakeFiles\CSV_UTIL.dir\csv_util.cpp.i

include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSV_UTIL.dir/csv_util.cpp.s"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && D:\Documents\Northeastern\Courses\PRCV-5330\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\csv_util.cpp -o CMakeFiles\CSV_UTIL.dir\csv_util.cpp.s

# Object files for target CSV_UTIL
CSV_UTIL_OBJECTS = \
"CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj"

# External object files for target CSV_UTIL
CSV_UTIL_EXTERNAL_OBJECTS =

include/libCSV_UTIL.a: include/CMakeFiles/CSV_UTIL.dir/csv_util.cpp.obj
include/libCSV_UTIL.a: include/CMakeFiles/CSV_UTIL.dir/build.make
include/libCSV_UTIL.a: include/CMakeFiles/CSV_UTIL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCSV_UTIL.a"
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\CSV_UTIL.dir\cmake_clean_target.cmake
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CSV_UTIL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/CMakeFiles/CSV_UTIL.dir/build: include/libCSV_UTIL.a
.PHONY : include/CMakeFiles/CSV_UTIL.dir/build

include/CMakeFiles/CSV_UTIL.dir/clean:
	cd /d D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include && $(CMAKE_COMMAND) -P CMakeFiles\CSV_UTIL.dir\cmake_clean.cmake
.PHONY : include/CMakeFiles/CSV_UTIL.dir/clean

include/CMakeFiles/CSV_UTIL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2 D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include D:\Documents\Northeastern\Courses\PRCV-5330\Projects\project2\include\CMakeFiles\CSV_UTIL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include/CMakeFiles/CSV_UTIL.dir/depend

