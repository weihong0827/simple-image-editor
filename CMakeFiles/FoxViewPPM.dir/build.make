# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM"

# Include any dependencies generated for this target.
include CMakeFiles/FoxViewPPM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FoxViewPPM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FoxViewPPM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FoxViewPPM.dir/flags.make

FoxViewPPM.app/Contents/Resources/FoxViewPPM.icns: build/macosx/FoxViewPPM.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Copying OS X content FoxViewPPM.app/Contents/Resources/FoxViewPPM.icns"
	$(CMAKE_COMMAND) -E copy "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/build/macosx/FoxViewPPM.icns" FoxViewPPM.app/Contents/Resources/FoxViewPPM.icns

CMakeFiles/FoxViewPPM.dir/src/main.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/main.c.o: src/main.c
CMakeFiles/FoxViewPPM.dir/src/main.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FoxViewPPM.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/main.c.o -MF CMakeFiles/FoxViewPPM.dir/src/main.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/main.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/main.c"

CMakeFiles/FoxViewPPM.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/main.c" > CMakeFiles/FoxViewPPM.dir/src/main.c.i

CMakeFiles/FoxViewPPM.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/main.c" -o CMakeFiles/FoxViewPPM.dir/src/main.c.s

CMakeFiles/FoxViewPPM.dir/src/ppm.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/ppm.c.o: src/ppm.c
CMakeFiles/FoxViewPPM.dir/src/ppm.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/FoxViewPPM.dir/src/ppm.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/ppm.c.o -MF CMakeFiles/FoxViewPPM.dir/src/ppm.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/ppm.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/ppm.c"

CMakeFiles/FoxViewPPM.dir/src/ppm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/ppm.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/ppm.c" > CMakeFiles/FoxViewPPM.dir/src/ppm.c.i

CMakeFiles/FoxViewPPM.dir/src/ppm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/ppm.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/ppm.c" -o CMakeFiles/FoxViewPPM.dir/src/ppm.c.s

CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o: src/sdl_engine.c
CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o -MF CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_engine.c"

CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_engine.c" > CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.i

CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_engine.c" -o CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.s

CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o: src/sdl_renderer.c
CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o -MF CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_renderer.c"

CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_renderer.c" > CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.i

CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/sdl_renderer.c" -o CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.s

CMakeFiles/FoxViewPPM.dir/src/image.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/image.c.o: src/image.c
CMakeFiles/FoxViewPPM.dir/src/image.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/FoxViewPPM.dir/src/image.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/image.c.o -MF CMakeFiles/FoxViewPPM.dir/src/image.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/image.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/image.c"

CMakeFiles/FoxViewPPM.dir/src/image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/image.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/image.c" > CMakeFiles/FoxViewPPM.dir/src/image.c.i

CMakeFiles/FoxViewPPM.dir/src/image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/image.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/image.c" -o CMakeFiles/FoxViewPPM.dir/src/image.c.s

CMakeFiles/FoxViewPPM.dir/src/preset.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/preset.c.o: src/preset.c
CMakeFiles/FoxViewPPM.dir/src/preset.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/FoxViewPPM.dir/src/preset.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/preset.c.o -MF CMakeFiles/FoxViewPPM.dir/src/preset.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/preset.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/preset.c"

CMakeFiles/FoxViewPPM.dir/src/preset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/preset.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/preset.c" > CMakeFiles/FoxViewPPM.dir/src/preset.c.i

CMakeFiles/FoxViewPPM.dir/src/preset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/preset.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/preset.c" -o CMakeFiles/FoxViewPPM.dir/src/preset.c.s

CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o: CMakeFiles/FoxViewPPM.dir/flags.make
CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o: src/adjustment_func.c
CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o: CMakeFiles/FoxViewPPM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o -MF CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o.d -o CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o -c "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/adjustment_func.c"

CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/adjustment_func.c" > CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.i

CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/src/adjustment_func.c" -o CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.s

# Object files for target FoxViewPPM
FoxViewPPM_OBJECTS = \
"CMakeFiles/FoxViewPPM.dir/src/main.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/ppm.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/image.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/preset.c.o" \
"CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o"

# External object files for target FoxViewPPM
FoxViewPPM_EXTERNAL_OBJECTS =

FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/main.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/ppm.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/sdl_engine.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/sdl_renderer.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/image.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/preset.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/src/adjustment_func.c.o
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/build.make
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: vendors/sdl/libSDL3.a
FoxViewPPM.app/Contents/MacOS/FoxViewPPM: CMakeFiles/FoxViewPPM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable FoxViewPPM.app/Contents/MacOS/FoxViewPPM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FoxViewPPM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FoxViewPPM.dir/build: FoxViewPPM.app/Contents/MacOS/FoxViewPPM
CMakeFiles/FoxViewPPM.dir/build: FoxViewPPM.app/Contents/Resources/FoxViewPPM.icns
.PHONY : CMakeFiles/FoxViewPPM.dir/build

CMakeFiles/FoxViewPPM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FoxViewPPM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FoxViewPPM.dir/clean

CMakeFiles/FoxViewPPM.dir/depend:
	cd "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM" "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM" "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM" "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM" "/Users/victoriachong/Documents/SUTD/TERM 8/50.051 PLC/FoxViewPPM/CMakeFiles/FoxViewPPM.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/FoxViewPPM.dir/depend

