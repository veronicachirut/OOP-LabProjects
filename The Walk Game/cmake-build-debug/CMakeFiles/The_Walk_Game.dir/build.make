# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Vero\Desktop\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Vero\Desktop\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\The_Walk_Game.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\The_Walk_Game.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\The_Walk_Game.dir\flags.make

CMakeFiles\The_Walk_Game.dir\main.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/The_Walk_Game.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\main.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\main.cpp"
<<

CMakeFiles\The_Walk_Game.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\main.cpp"
<<

CMakeFiles\The_Walk_Game.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\main.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\main.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.obj: ..\robots\Robot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/The_Walk_Game.dir/robots/Robot.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\Robot.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/robots/Robot.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\Robot.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/robots/Robot.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\Robot.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.obj: ..\robots\R2_D2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/The_Walk_Game.dir/robots/R2_D2.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\R2_D2.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/robots/R2_D2.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\R2_D2.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/robots/R2_D2.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\R2_D2.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.obj: ..\robots\C_3PO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/The_Walk_Game.dir/robots/C_3PO.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\C_3PO.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/robots/C_3PO.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\C_3PO.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/robots/C_3PO.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\C_3PO.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.obj: ..\robots\L3_37.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/The_Walk_Game.dir/robots/L3_37.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\L3_37.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/robots/L3_37.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\L3_37.cpp"
<<

CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/robots/L3_37.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\robots\L3_37.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Map.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\Map.cpp.obj: ..\Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/The_Walk_Game.dir/Map.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\Map.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Map.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/Map.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\Map.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Map.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/Map.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\Map.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Map.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Game.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\Game.cpp.obj: ..\Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/The_Walk_Game.dir/Game.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\Game.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Game.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/Game.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\Game.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Game.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/Game.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\Game.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Game.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Round.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\Round.cpp.obj: ..\Round.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/The_Walk_Game.dir/Round.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\Round.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Round.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Round.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/Round.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\Round.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Round.cpp"
<<

CMakeFiles\The_Walk_Game.dir\Round.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/Round.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\Round.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\Round.cpp"
<<

CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.obj: CMakeFiles\The_Walk_Game.dir\flags.make
CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.obj: ..\AlongTheWay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/The_Walk_Game.dir/AlongTheWay.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.obj /FdCMakeFiles\The_Walk_Game.dir\ /FS -c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\AlongTheWay.cpp"
<<

CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Walk_Game.dir/AlongTheWay.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\AlongTheWay.cpp"
<<

CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Walk_Game.dir/AlongTheWay.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.s /c "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\AlongTheWay.cpp"
<<

# Object files for target The_Walk_Game
The_Walk_Game_OBJECTS = \
"CMakeFiles\The_Walk_Game.dir\main.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\Map.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\Game.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\Round.cpp.obj" \
"CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.obj"

# External object files for target The_Walk_Game
The_Walk_Game_EXTERNAL_OBJECTS =

The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\main.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\robots\Robot.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\robots\R2_D2.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\robots\C_3PO.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\robots\L3_37.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\Map.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\Game.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\Round.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\AlongTheWay.cpp.obj
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\build.make
The_Walk_Game.exe: CMakeFiles\The_Walk_Game.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable The_Walk_Game.exe"
	"C:\Users\Vero\Desktop\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\The_Walk_Game.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\The_Walk_Game.dir\objects1.rsp @<<
 /out:The_Walk_Game.exe /implib:The_Walk_Game.lib /pdb:"C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\The_Walk_Game.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\The_Walk_Game.dir\build: The_Walk_Game.exe

.PHONY : CMakeFiles\The_Walk_Game.dir\build

CMakeFiles\The_Walk_Game.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\The_Walk_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles\The_Walk_Game.dir\clean

CMakeFiles\The_Walk_Game.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game" "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game" "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug" "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug" "C:\Users\Vero\Desktop\Fac\An I\POO\Labs\The Walk Game\cmake-build-debug\CMakeFiles\The_Walk_Game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\The_Walk_Game.dir\depend

