# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Dropbox\Code\RPGTextCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Dropbox\Code\RPGTextCPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RPGTextCPP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RPGTextCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RPGTextCPP.dir/flags.make

CMakeFiles/RPGTextCPP.dir/main.cpp.obj: CMakeFiles/RPGTextCPP.dir/flags.make
CMakeFiles/RPGTextCPP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Dropbox\Code\RPGTextCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RPGTextCPP.dir/main.cpp.obj"
	E:\PROGRA~1\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RPGTextCPP.dir\main.cpp.obj -c E:\Dropbox\Code\RPGTextCPP\main.cpp

CMakeFiles/RPGTextCPP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPGTextCPP.dir/main.cpp.i"
	E:\PROGRA~1\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Dropbox\Code\RPGTextCPP\main.cpp > CMakeFiles\RPGTextCPP.dir\main.cpp.i

CMakeFiles/RPGTextCPP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPGTextCPP.dir/main.cpp.s"
	E:\PROGRA~1\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Dropbox\Code\RPGTextCPP\main.cpp -o CMakeFiles\RPGTextCPP.dir\main.cpp.s

# Object files for target RPGTextCPP
RPGTextCPP_OBJECTS = \
"CMakeFiles/RPGTextCPP.dir/main.cpp.obj"

# External object files for target RPGTextCPP
RPGTextCPP_EXTERNAL_OBJECTS =

RPGTextCPP.exe: CMakeFiles/RPGTextCPP.dir/main.cpp.obj
RPGTextCPP.exe: CMakeFiles/RPGTextCPP.dir/build.make
RPGTextCPP.exe: CMakeFiles/RPGTextCPP.dir/linklibs.rsp
RPGTextCPP.exe: CMakeFiles/RPGTextCPP.dir/objects1.rsp
RPGTextCPP.exe: CMakeFiles/RPGTextCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Dropbox\Code\RPGTextCPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RPGTextCPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RPGTextCPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RPGTextCPP.dir/build: RPGTextCPP.exe

.PHONY : CMakeFiles/RPGTextCPP.dir/build

CMakeFiles/RPGTextCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RPGTextCPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RPGTextCPP.dir/clean

CMakeFiles/RPGTextCPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Dropbox\Code\RPGTextCPP E:\Dropbox\Code\RPGTextCPP E:\Dropbox\Code\RPGTextCPP\cmake-build-debug E:\Dropbox\Code\RPGTextCPP\cmake-build-debug E:\Dropbox\Code\RPGTextCPP\cmake-build-debug\CMakeFiles\RPGTextCPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RPGTextCPP.dir/depend

