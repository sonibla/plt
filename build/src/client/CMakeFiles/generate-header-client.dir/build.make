# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ensea/Desktop/plt_new_dev/plt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ensea/Desktop/plt_new_dev/plt/build

# Utility rule file for generate-header-client.

# Include the progress variables for this target.
include src/client/CMakeFiles/generate-header-client.dir/progress.make

src/client/CMakeFiles/generate-header-client: generate_header_client.stamp


generate_header_client.stamp: ../src/client.dia
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ensea/Desktop/plt_new_dev/plt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../generate_header_client.stamp"
	cd /home/ensea/Desktop/plt_new_dev/plt/build/src/client && rm -vf /home/ensea/Desktop/plt_new_dev/plt/src/*/client.h
	cd /home/ensea/Desktop/plt_new_dev/plt/build/src/client && rm -vf /home/ensea/Desktop/plt_new_dev/plt/src/*/client/*.h
	cd /home/ensea/Desktop/plt_new_dev/plt/build/src/client && ../../../bin/dia2code -ns client -d /home/ensea/Desktop/plt_new_dev/plt/src/client -t cpp /home/ensea/Desktop/plt_new_dev/plt/src/client/../client.dia
	cd /home/ensea/Desktop/plt_new_dev/plt/build/src/client && /usr/bin/cmake -E touch /home/ensea/Desktop/plt_new_dev/plt/build/generate_header_client.stamp

generate-header-client: src/client/CMakeFiles/generate-header-client
generate-header-client: generate_header_client.stamp
generate-header-client: src/client/CMakeFiles/generate-header-client.dir/build.make

.PHONY : generate-header-client

# Rule to build all files generated by this target.
src/client/CMakeFiles/generate-header-client.dir/build: generate-header-client

.PHONY : src/client/CMakeFiles/generate-header-client.dir/build

src/client/CMakeFiles/generate-header-client.dir/clean:
	cd /home/ensea/Desktop/plt_new_dev/plt/build/src/client && $(CMAKE_COMMAND) -P CMakeFiles/generate-header-client.dir/cmake_clean.cmake
.PHONY : src/client/CMakeFiles/generate-header-client.dir/clean

src/client/CMakeFiles/generate-header-client.dir/depend:
	cd /home/ensea/Desktop/plt_new_dev/plt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ensea/Desktop/plt_new_dev/plt /home/ensea/Desktop/plt_new_dev/plt/src/client /home/ensea/Desktop/plt_new_dev/plt/build /home/ensea/Desktop/plt_new_dev/plt/build/src/client /home/ensea/Desktop/plt_new_dev/plt/build/src/client/CMakeFiles/generate-header-client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/client/CMakeFiles/generate-header-client.dir/depend

