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
CMAKE_SOURCE_DIR = /mnt/c/Users/Pichau/Documents/git/smnptest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Pichau/Documents/git/smnptest/build

# Include any dependencies generated for this target.
include CMakeFiles/SNMPClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SNMPClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SNMPClient.dir/flags.make

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o: ../SNMP/SNMP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/SNMP/SNMP.cpp

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/SNMP/SNMP.cpp > CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.i

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/SNMP/SNMP.cpp -o CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.s

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.requires

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.provides: CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.provides

CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o


CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o: ../Socket/ClientSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ClientSocket.cpp

CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ClientSocket.cpp > CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.i

CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ClientSocket.cpp -o CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.s

CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.requires

CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.provides: CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.provides

CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o


CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o: ../Socket/DatagramSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/DatagramSocket.cpp

CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/DatagramSocket.cpp > CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.i

CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/DatagramSocket.cpp -o CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.s

CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.requires

CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.provides: CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.provides

CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o


CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o: ../Socket/ServerSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ServerSocket.cpp

CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ServerSocket.cpp > CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.i

CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/ServerSocket.cpp -o CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.s

CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.requires

CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.provides: CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.provides

CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o


CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o: ../Socket/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/Socket.cpp

CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/Socket.cpp > CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.i

CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Socket/Socket.cpp -o CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.s

CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.requires

CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.provides: CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.provides

CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o


CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o: ../Utils/SNMPMessager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/SNMPMessager.cpp

CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/SNMPMessager.cpp > CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.i

CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/SNMPMessager.cpp -o CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.s

CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.requires

CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.provides: CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.provides

CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o


CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o: ../Utils/StringUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/StringUtils.cpp

CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/StringUtils.cpp > CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.i

CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/Utils/StringUtils.cpp -o CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.s

CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.requires

CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.provides: CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.provides

CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o


CMakeFiles/SNMPClient.dir/main.cpp.o: CMakeFiles/SNMPClient.dir/flags.make
CMakeFiles/SNMPClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SNMPClient.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNMPClient.dir/main.cpp.o -c /mnt/c/Users/Pichau/Documents/git/smnptest/main.cpp

CMakeFiles/SNMPClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNMPClient.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Pichau/Documents/git/smnptest/main.cpp > CMakeFiles/SNMPClient.dir/main.cpp.i

CMakeFiles/SNMPClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNMPClient.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Pichau/Documents/git/smnptest/main.cpp -o CMakeFiles/SNMPClient.dir/main.cpp.s

CMakeFiles/SNMPClient.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SNMPClient.dir/main.cpp.o.requires

CMakeFiles/SNMPClient.dir/main.cpp.o.provides: CMakeFiles/SNMPClient.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNMPClient.dir/build.make CMakeFiles/SNMPClient.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SNMPClient.dir/main.cpp.o.provides

CMakeFiles/SNMPClient.dir/main.cpp.o.provides.build: CMakeFiles/SNMPClient.dir/main.cpp.o


# Object files for target SNMPClient
SNMPClient_OBJECTS = \
"CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o" \
"CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o" \
"CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o" \
"CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o" \
"CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o" \
"CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o" \
"CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o" \
"CMakeFiles/SNMPClient.dir/main.cpp.o"

# External object files for target SNMPClient
SNMPClient_EXTERNAL_OBJECTS =

libSNMPClient.so: CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/main.cpp.o
libSNMPClient.so: CMakeFiles/SNMPClient.dir/build.make
libSNMPClient.so: /usr/lib/jvm/default-java/lib/server/libjvm.so
libSNMPClient.so: CMakeFiles/SNMPClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library libSNMPClient.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SNMPClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SNMPClient.dir/build: libSNMPClient.so

.PHONY : CMakeFiles/SNMPClient.dir/build

CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/SNMP/SNMP.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Socket/ClientSocket.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Socket/DatagramSocket.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Socket/ServerSocket.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Socket/Socket.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Utils/SNMPMessager.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/Utils/StringUtils.cpp.o.requires
CMakeFiles/SNMPClient.dir/requires: CMakeFiles/SNMPClient.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SNMPClient.dir/requires

CMakeFiles/SNMPClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SNMPClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SNMPClient.dir/clean

CMakeFiles/SNMPClient.dir/depend:
	cd /mnt/c/Users/Pichau/Documents/git/smnptest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Pichau/Documents/git/smnptest /mnt/c/Users/Pichau/Documents/git/smnptest /mnt/c/Users/Pichau/Documents/git/smnptest/build /mnt/c/Users/Pichau/Documents/git/smnptest/build /mnt/c/Users/Pichau/Documents/git/smnptest/build/CMakeFiles/SNMPClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SNMPClient.dir/depend
