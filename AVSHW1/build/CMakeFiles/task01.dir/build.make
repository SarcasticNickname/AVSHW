# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/AVSHW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/AVSHW1/build

# Include any dependencies generated for this target.
include CMakeFiles/task01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task01.dir/flags.make

CMakeFiles/task01.dir/triangular.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/triangular.cpp.o: ../triangular.cpp
CMakeFiles/task01.dir/triangular.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task01.dir/triangular.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/triangular.cpp.o -MF CMakeFiles/task01.dir/triangular.cpp.o.d -o CMakeFiles/task01.dir/triangular.cpp.o -c /root/AVSHW1/triangular.cpp

CMakeFiles/task01.dir/triangular.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/triangular.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/triangular.cpp > CMakeFiles/task01.dir/triangular.cpp.i

CMakeFiles/task01.dir/triangular.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/triangular.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/triangular.cpp -o CMakeFiles/task01.dir/triangular.cpp.s

CMakeFiles/task01.dir/diagonal.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/diagonal.cpp.o: ../diagonal.cpp
CMakeFiles/task01.dir/diagonal.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task01.dir/diagonal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/diagonal.cpp.o -MF CMakeFiles/task01.dir/diagonal.cpp.o.d -o CMakeFiles/task01.dir/diagonal.cpp.o -c /root/AVSHW1/diagonal.cpp

CMakeFiles/task01.dir/diagonal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/diagonal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/diagonal.cpp > CMakeFiles/task01.dir/diagonal.cpp.i

CMakeFiles/task01.dir/diagonal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/diagonal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/diagonal.cpp -o CMakeFiles/task01.dir/diagonal.cpp.s

CMakeFiles/task01.dir/square.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/square.cpp.o: ../square.cpp
CMakeFiles/task01.dir/square.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task01.dir/square.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/square.cpp.o -MF CMakeFiles/task01.dir/square.cpp.o.d -o CMakeFiles/task01.dir/square.cpp.o -c /root/AVSHW1/square.cpp

CMakeFiles/task01.dir/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/square.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/square.cpp > CMakeFiles/task01.dir/square.cpp.i

CMakeFiles/task01.dir/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/square.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/square.cpp -o CMakeFiles/task01.dir/square.cpp.s

CMakeFiles/task01.dir/matrix.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/matrix.cpp.o: ../matrix.cpp
CMakeFiles/task01.dir/matrix.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task01.dir/matrix.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/matrix.cpp.o -MF CMakeFiles/task01.dir/matrix.cpp.o.d -o CMakeFiles/task01.dir/matrix.cpp.o -c /root/AVSHW1/matrix.cpp

CMakeFiles/task01.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/matrix.cpp > CMakeFiles/task01.dir/matrix.cpp.i

CMakeFiles/task01.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/matrix.cpp -o CMakeFiles/task01.dir/matrix.cpp.s

CMakeFiles/task01.dir/container.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/container.cpp.o: ../container.cpp
CMakeFiles/task01.dir/container.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task01.dir/container.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/container.cpp.o -MF CMakeFiles/task01.dir/container.cpp.o.d -o CMakeFiles/task01.dir/container.cpp.o -c /root/AVSHW1/container.cpp

CMakeFiles/task01.dir/container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/container.cpp > CMakeFiles/task01.dir/container.cpp.i

CMakeFiles/task01.dir/container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/container.cpp -o CMakeFiles/task01.dir/container.cpp.s

CMakeFiles/task01.dir/main.cpp.o: CMakeFiles/task01.dir/flags.make
CMakeFiles/task01.dir/main.cpp.o: ../main.cpp
CMakeFiles/task01.dir/main.cpp.o: CMakeFiles/task01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/task01.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task01.dir/main.cpp.o -MF CMakeFiles/task01.dir/main.cpp.o.d -o CMakeFiles/task01.dir/main.cpp.o -c /root/AVSHW1/main.cpp

CMakeFiles/task01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task01.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/AVSHW1/main.cpp > CMakeFiles/task01.dir/main.cpp.i

CMakeFiles/task01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task01.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/AVSHW1/main.cpp -o CMakeFiles/task01.dir/main.cpp.s

# Object files for target task01
task01_OBJECTS = \
"CMakeFiles/task01.dir/triangular.cpp.o" \
"CMakeFiles/task01.dir/diagonal.cpp.o" \
"CMakeFiles/task01.dir/square.cpp.o" \
"CMakeFiles/task01.dir/matrix.cpp.o" \
"CMakeFiles/task01.dir/container.cpp.o" \
"CMakeFiles/task01.dir/main.cpp.o"

# External object files for target task01
task01_EXTERNAL_OBJECTS =

../bin/task01: CMakeFiles/task01.dir/triangular.cpp.o
../bin/task01: CMakeFiles/task01.dir/diagonal.cpp.o
../bin/task01: CMakeFiles/task01.dir/square.cpp.o
../bin/task01: CMakeFiles/task01.dir/matrix.cpp.o
../bin/task01: CMakeFiles/task01.dir/container.cpp.o
../bin/task01: CMakeFiles/task01.dir/main.cpp.o
../bin/task01: CMakeFiles/task01.dir/build.make
../bin/task01: CMakeFiles/task01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/AVSHW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../bin/task01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task01.dir/build: ../bin/task01
.PHONY : CMakeFiles/task01.dir/build

CMakeFiles/task01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task01.dir/clean

CMakeFiles/task01.dir/depend:
	cd /root/AVSHW1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/AVSHW1 /root/AVSHW1 /root/AVSHW1/build /root/AVSHW1/build /root/AVSHW1/build/CMakeFiles/task01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task01.dir/depend

