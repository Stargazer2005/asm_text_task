# language: CMake

cmake_minimum_required(VERSION 3.20)

project(TextTask LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17 -Og")

set(ASM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/asm_funcs")
set(C_DIR "${CMAKE_CURRENT_SOURCE_DIR}/c_funcs")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")

file(GLOB_RECURSE ASM_SOURCES "${ASM_DIR}/*.s")
file(GLOB_RECURSE C_SOURCES "${C_DIR}/*.c")

add_executable(test_asm "${TEST_DIR}/test_asm.cpp" ${ASM_SOURCES})
add_executable(test_c "${TEST_DIR}/test_c.cpp" ${C_SOURCES})