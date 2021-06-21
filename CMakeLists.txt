cmake_minimum_required(VERSION 3.19)
project(dbstorage)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
