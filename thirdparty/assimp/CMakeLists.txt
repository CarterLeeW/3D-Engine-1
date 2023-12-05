cmake_minimum_required(VERSION 3.13)
project(assimp)

add_library(assimp INTERFACE)

target_include_directories(assimp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
