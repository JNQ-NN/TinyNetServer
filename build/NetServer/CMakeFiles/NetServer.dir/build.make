# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /root/cpp_project/TinyNetServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cpp_project/TinyNetServer/build

# Include any dependencies generated for this target.
include NetServer/CMakeFiles/NetServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include NetServer/CMakeFiles/NetServer.dir/compiler_depend.make

# Include the progress variables for this target.
include NetServer/CMakeFiles/NetServer.dir/progress.make

# Include the compile flags for this target's objects.
include NetServer/CMakeFiles/NetServer.dir/flags.make

NetServer/CMakeFiles/NetServer.dir/main.cpp.o: NetServer/CMakeFiles/NetServer.dir/flags.make
NetServer/CMakeFiles/NetServer.dir/main.cpp.o: ../NetServer/main.cpp
NetServer/CMakeFiles/NetServer.dir/main.cpp.o: NetServer/CMakeFiles/NetServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/TinyNetServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object NetServer/CMakeFiles/NetServer.dir/main.cpp.o"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT NetServer/CMakeFiles/NetServer.dir/main.cpp.o -MF CMakeFiles/NetServer.dir/main.cpp.o.d -o CMakeFiles/NetServer.dir/main.cpp.o -c /root/cpp_project/TinyNetServer/NetServer/main.cpp

NetServer/CMakeFiles/NetServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetServer.dir/main.cpp.i"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/TinyNetServer/NetServer/main.cpp > CMakeFiles/NetServer.dir/main.cpp.i

NetServer/CMakeFiles/NetServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetServer.dir/main.cpp.s"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/TinyNetServer/NetServer/main.cpp -o CMakeFiles/NetServer.dir/main.cpp.s

NetServer/CMakeFiles/NetServer.dir/server.cpp.o: NetServer/CMakeFiles/NetServer.dir/flags.make
NetServer/CMakeFiles/NetServer.dir/server.cpp.o: ../NetServer/server.cpp
NetServer/CMakeFiles/NetServer.dir/server.cpp.o: NetServer/CMakeFiles/NetServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/TinyNetServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object NetServer/CMakeFiles/NetServer.dir/server.cpp.o"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT NetServer/CMakeFiles/NetServer.dir/server.cpp.o -MF CMakeFiles/NetServer.dir/server.cpp.o.d -o CMakeFiles/NetServer.dir/server.cpp.o -c /root/cpp_project/TinyNetServer/NetServer/server.cpp

NetServer/CMakeFiles/NetServer.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetServer.dir/server.cpp.i"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/TinyNetServer/NetServer/server.cpp > CMakeFiles/NetServer.dir/server.cpp.i

NetServer/CMakeFiles/NetServer.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetServer.dir/server.cpp.s"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/TinyNetServer/NetServer/server.cpp -o CMakeFiles/NetServer.dir/server.cpp.s

NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o: NetServer/CMakeFiles/NetServer.dir/flags.make
NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o: ../NetServer/server_session.cpp
NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o: NetServer/CMakeFiles/NetServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp_project/TinyNetServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o -MF CMakeFiles/NetServer.dir/server_session.cpp.o.d -o CMakeFiles/NetServer.dir/server_session.cpp.o -c /root/cpp_project/TinyNetServer/NetServer/server_session.cpp

NetServer/CMakeFiles/NetServer.dir/server_session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetServer.dir/server_session.cpp.i"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp_project/TinyNetServer/NetServer/server_session.cpp > CMakeFiles/NetServer.dir/server_session.cpp.i

NetServer/CMakeFiles/NetServer.dir/server_session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetServer.dir/server_session.cpp.s"
	cd /root/cpp_project/TinyNetServer/build/NetServer && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp_project/TinyNetServer/NetServer/server_session.cpp -o CMakeFiles/NetServer.dir/server_session.cpp.s

# Object files for target NetServer
NetServer_OBJECTS = \
"CMakeFiles/NetServer.dir/main.cpp.o" \
"CMakeFiles/NetServer.dir/server.cpp.o" \
"CMakeFiles/NetServer.dir/server_session.cpp.o"

# External object files for target NetServer
NetServer_EXTERNAL_OBJECTS =

NetServer/NetServer: NetServer/CMakeFiles/NetServer.dir/main.cpp.o
NetServer/NetServer: NetServer/CMakeFiles/NetServer.dir/server.cpp.o
NetServer/NetServer: NetServer/CMakeFiles/NetServer.dir/server_session.cpp.o
NetServer/NetServer: NetServer/CMakeFiles/NetServer.dir/build.make
NetServer/NetServer: NetServer/CMakeFiles/NetServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/cpp_project/TinyNetServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable NetServer"
	cd /root/cpp_project/TinyNetServer/build/NetServer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NetServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
NetServer/CMakeFiles/NetServer.dir/build: NetServer/NetServer
.PHONY : NetServer/CMakeFiles/NetServer.dir/build

NetServer/CMakeFiles/NetServer.dir/clean:
	cd /root/cpp_project/TinyNetServer/build/NetServer && $(CMAKE_COMMAND) -P CMakeFiles/NetServer.dir/cmake_clean.cmake
.PHONY : NetServer/CMakeFiles/NetServer.dir/clean

NetServer/CMakeFiles/NetServer.dir/depend:
	cd /root/cpp_project/TinyNetServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/cpp_project/TinyNetServer /root/cpp_project/TinyNetServer/NetServer /root/cpp_project/TinyNetServer/build /root/cpp_project/TinyNetServer/build/NetServer /root/cpp_project/TinyNetServer/build/NetServer/CMakeFiles/NetServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : NetServer/CMakeFiles/NetServer.dir/depend

