# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4

# Include any dependencies generated for this target.
include CMakeFiles/test_correct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_correct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_correct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_correct.dir/flags.make

CMakeFiles/test_correct.dir/test_correct.o: CMakeFiles/test_correct.dir/flags.make
CMakeFiles/test_correct.dir/test_correct.o: test_correct.c
CMakeFiles/test_correct.dir/test_correct.o: CMakeFiles/test_correct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_correct.dir/test_correct.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_correct.dir/test_correct.o -MF CMakeFiles/test_correct.dir/test_correct.o.d -o CMakeFiles/test_correct.dir/test_correct.o -c /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/test_correct.c

CMakeFiles/test_correct.dir/test_correct.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_correct.dir/test_correct.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/test_correct.c > CMakeFiles/test_correct.dir/test_correct.i

CMakeFiles/test_correct.dir/test_correct.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_correct.dir/test_correct.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/test_correct.c -o CMakeFiles/test_correct.dir/test_correct.s

CMakeFiles/test_correct.dir/matrix.o: CMakeFiles/test_correct.dir/flags.make
CMakeFiles/test_correct.dir/matrix.o: matrix.c
CMakeFiles/test_correct.dir/matrix.o: CMakeFiles/test_correct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_correct.dir/matrix.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_correct.dir/matrix.o -MF CMakeFiles/test_correct.dir/matrix.o.d -o CMakeFiles/test_correct.dir/matrix.o -c /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/matrix.c

CMakeFiles/test_correct.dir/matrix.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_correct.dir/matrix.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/matrix.c > CMakeFiles/test_correct.dir/matrix.i

CMakeFiles/test_correct.dir/matrix.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_correct.dir/matrix.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/matrix.c -o CMakeFiles/test_correct.dir/matrix.s

CMakeFiles/test_correct.dir/multiply.o: CMakeFiles/test_correct.dir/flags.make
CMakeFiles/test_correct.dir/multiply.o: multiply.c
CMakeFiles/test_correct.dir/multiply.o: CMakeFiles/test_correct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_correct.dir/multiply.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_correct.dir/multiply.o -MF CMakeFiles/test_correct.dir/multiply.o.d -o CMakeFiles/test_correct.dir/multiply.o -c /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/multiply.c

CMakeFiles/test_correct.dir/multiply.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_correct.dir/multiply.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/multiply.c > CMakeFiles/test_correct.dir/multiply.i

CMakeFiles/test_correct.dir/multiply.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_correct.dir/multiply.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/multiply.c -o CMakeFiles/test_correct.dir/multiply.s

# Object files for target test_correct
test_correct_OBJECTS = \
"CMakeFiles/test_correct.dir/test_correct.o" \
"CMakeFiles/test_correct.dir/matrix.o" \
"CMakeFiles/test_correct.dir/multiply.o"

# External object files for target test_correct
test_correct_EXTERNAL_OBJECTS =

test_correct: CMakeFiles/test_correct.dir/test_correct.o
test_correct: CMakeFiles/test_correct.dir/matrix.o
test_correct: CMakeFiles/test_correct.dir/multiply.o
test_correct: CMakeFiles/test_correct.dir/build.make
test_correct: CMakeFiles/test_correct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_correct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_correct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_correct.dir/build: test_correct
.PHONY : CMakeFiles/test_correct.dir/build

CMakeFiles/test_correct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_correct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_correct.dir/clean

CMakeFiles/test_correct.dir/depend:
	cd /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4 /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4 /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4 /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4 /mnt/c/Users/84781/Desktop/课程/大四上/cs205/projects/project4/CMakeFiles/test_correct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_correct.dir/depend

