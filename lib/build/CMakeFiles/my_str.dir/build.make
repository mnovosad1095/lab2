# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m/Documents/POC/lab2/lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m/Documents/POC/lab2/lib/build

# Include any dependencies generated for this target.
include CMakeFiles/my_str.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_str.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_str.dir/flags.make

CMakeFiles/my_str.dir/string_lib.c.o: CMakeFiles/my_str.dir/flags.make
CMakeFiles/my_str.dir/string_lib.c.o: ../string_lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/Documents/POC/lab2/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_str.dir/string_lib.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_str.dir/string_lib.c.o   -c /home/m/Documents/POC/lab2/lib/string_lib.c

CMakeFiles/my_str.dir/string_lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_str.dir/string_lib.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/m/Documents/POC/lab2/lib/string_lib.c > CMakeFiles/my_str.dir/string_lib.c.i

CMakeFiles/my_str.dir/string_lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_str.dir/string_lib.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/m/Documents/POC/lab2/lib/string_lib.c -o CMakeFiles/my_str.dir/string_lib.c.s

CMakeFiles/my_str.dir/string_modify.c.o: CMakeFiles/my_str.dir/flags.make
CMakeFiles/my_str.dir/string_modify.c.o: ../string_modify.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/Documents/POC/lab2/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_str.dir/string_modify.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_str.dir/string_modify.c.o   -c /home/m/Documents/POC/lab2/lib/string_modify.c

CMakeFiles/my_str.dir/string_modify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_str.dir/string_modify.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/m/Documents/POC/lab2/lib/string_modify.c > CMakeFiles/my_str.dir/string_modify.c.i

CMakeFiles/my_str.dir/string_modify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_str.dir/string_modify.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/m/Documents/POC/lab2/lib/string_modify.c -o CMakeFiles/my_str.dir/string_modify.c.s

CMakeFiles/my_str.dir/string_info.c.o: CMakeFiles/my_str.dir/flags.make
CMakeFiles/my_str.dir/string_info.c.o: ../string_info.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/Documents/POC/lab2/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/my_str.dir/string_info.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_str.dir/string_info.c.o   -c /home/m/Documents/POC/lab2/lib/string_info.c

CMakeFiles/my_str.dir/string_info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_str.dir/string_info.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/m/Documents/POC/lab2/lib/string_info.c > CMakeFiles/my_str.dir/string_info.c.i

CMakeFiles/my_str.dir/string_info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_str.dir/string_info.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/m/Documents/POC/lab2/lib/string_info.c -o CMakeFiles/my_str.dir/string_info.c.s

CMakeFiles/my_str.dir/read_write.c.o: CMakeFiles/my_str.dir/flags.make
CMakeFiles/my_str.dir/read_write.c.o: ../read_write.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/Documents/POC/lab2/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/my_str.dir/read_write.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_str.dir/read_write.c.o   -c /home/m/Documents/POC/lab2/lib/read_write.c

CMakeFiles/my_str.dir/read_write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_str.dir/read_write.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/m/Documents/POC/lab2/lib/read_write.c > CMakeFiles/my_str.dir/read_write.c.i

CMakeFiles/my_str.dir/read_write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_str.dir/read_write.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/m/Documents/POC/lab2/lib/read_write.c -o CMakeFiles/my_str.dir/read_write.c.s

# Object files for target my_str
my_str_OBJECTS = \
"CMakeFiles/my_str.dir/string_lib.c.o" \
"CMakeFiles/my_str.dir/string_modify.c.o" \
"CMakeFiles/my_str.dir/string_info.c.o" \
"CMakeFiles/my_str.dir/read_write.c.o"

# External object files for target my_str
my_str_EXTERNAL_OBJECTS =

../bin/libmy_str.so: CMakeFiles/my_str.dir/string_lib.c.o
../bin/libmy_str.so: CMakeFiles/my_str.dir/string_modify.c.o
../bin/libmy_str.so: CMakeFiles/my_str.dir/string_info.c.o
../bin/libmy_str.so: CMakeFiles/my_str.dir/read_write.c.o
../bin/libmy_str.so: CMakeFiles/my_str.dir/build.make
../bin/libmy_str.so: CMakeFiles/my_str.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m/Documents/POC/lab2/lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C shared library ../bin/libmy_str.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_str.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_str.dir/build: ../bin/libmy_str.so

.PHONY : CMakeFiles/my_str.dir/build

CMakeFiles/my_str.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_str.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_str.dir/clean

CMakeFiles/my_str.dir/depend:
	cd /home/m/Documents/POC/lab2/lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m/Documents/POC/lab2/lib /home/m/Documents/POC/lab2/lib /home/m/Documents/POC/lab2/lib/build /home/m/Documents/POC/lab2/lib/build /home/m/Documents/POC/lab2/lib/build/CMakeFiles/my_str.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_str.dir/depend

