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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\development\code\Data Structure Dev\Data Structure I_Final Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/untitled3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled3.dir/flags.make

CMakeFiles/untitled3.dir/main.cpp.obj: CMakeFiles/untitled3.dir/flags.make
CMakeFiles/untitled3.dir/main.cpp.obj: ../main.cpp
CMakeFiles/untitled3.dir/main.cpp.obj: CMakeFiles/untitled3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled3.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled3.dir/main.cpp.obj -MF CMakeFiles\untitled3.dir\main.cpp.obj.d -o CMakeFiles\untitled3.dir\main.cpp.obj -c "C:\development\code\Data Structure Dev\Data Structure I_Final Project\main.cpp"

CMakeFiles/untitled3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled3.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\development\code\Data Structure Dev\Data Structure I_Final Project\main.cpp" > CMakeFiles\untitled3.dir\main.cpp.i

CMakeFiles/untitled3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled3.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\development\code\Data Structure Dev\Data Structure I_Final Project\main.cpp" -o CMakeFiles\untitled3.dir\main.cpp.s

# Object files for target untitled3
untitled3_OBJECTS = \
"CMakeFiles/untitled3.dir/main.cpp.obj"

# External object files for target untitled3
untitled3_EXTERNAL_OBJECTS =

untitled3.exe: CMakeFiles/untitled3.dir/main.cpp.obj
untitled3.exe: CMakeFiles/untitled3.dir/build.make
untitled3.exe: CMakeFiles/untitled3.dir/linklibs.rsp
untitled3.exe: CMakeFiles/untitled3.dir/objects1.rsp
untitled3.exe: CMakeFiles/untitled3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled3.dir/build: untitled3.exe
.PHONY : CMakeFiles/untitled3.dir/build

CMakeFiles/untitled3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled3.dir/clean

CMakeFiles/untitled3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\development\code\Data Structure Dev\Data Structure I_Final Project" "C:\development\code\Data Structure Dev\Data Structure I_Final Project" "C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug" "C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug" "C:\development\code\Data Structure Dev\Data Structure I_Final Project\cmake-build-debug\CMakeFiles\untitled3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/untitled3.dir/depend

