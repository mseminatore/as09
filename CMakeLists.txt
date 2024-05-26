cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(as09 VERSION 1.0 LANGUAGES C)

# testing
enable_testing()
set(test_file ${CMAKE_CURRENT_SOURCE_DIR}/test.asm)
add_test(NAME assemble COMMAND as09 -x ${test_file})
add_test(NAME compare COMMAND ${CMAKE_COMMAND} -E compare_files a.out ${CMAKE_CURRENT_SOURCE_DIR}/test.hex)

# add the includes
include_directories(${PROJECT_SOURCE_DIR})

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2")    
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2")    
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2")
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:AVX2 /std:c11")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:0x800000")
endif()

message("CFLAGS = ${CMAKE_C_FLAGS}")

#
# add the executables
#
add_executable(as09 as09.tab.c)
