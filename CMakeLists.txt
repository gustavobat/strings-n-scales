cmake_minimum_required (VERSION 3.5)
project(strings-n-scales)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_subdirectory(lib)
add_subdirectory(app)
