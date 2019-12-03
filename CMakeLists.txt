cmake_minimum_required (VERSION 3.1)

project(compiler)


#
# library with common functions for tests and exe
#
add_library(lib
            src/lib/scan.cpp
            src/lib/scan.h
            src/lib/Helper.h
            src/lib/TypeToken.h
            src/lib/lexer.cpp
            src/lib/lexer.h
            src/lib/listToken.cpp
            src/lib/listToken.h)

set_target_properties(lib PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(compiler src/main.cpp)

set_target_properties(compiler PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(compiler lib)
target_link_libraries(compiler lib)

#
# unit tests
#

# download googletest
configure_file(CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# prevent overriding the parent project's compiler/linker on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add googletest to build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(compiler_unittests
               src/tests/main.cpp
               src/tests/lexer_unittest.cpp
               src/tests/listToken_unittest.cpp)

set_target_properties(compiler_unittests PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

target_include_directories(compiler_unittests PRIVATE
                           "${PROJECT_SOURCE_DIR}/src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(compiler_unittests lib)
target_link_libraries(compiler_unittests lib gtest_main)

