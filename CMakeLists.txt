# language: CMake

cmake_minimum_required(VERSION 3.20)

project(TextTask LANGUAGES C CXX ASM)

# ----------------------        Main Dir        ----------------------
cmake_path(SET MAIN_DIR "${CMAKE_SOURCE_DIR}/main")

file(GLOB_RECURSE MAIN_SOURCES "${MAIN_DIR}/*.cpp" "${MAIN_DIR}/*.c")

add_executable(main ${MAIN_SOURCES})