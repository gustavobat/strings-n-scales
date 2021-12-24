find_package(docopt COMPONENTS CXX REQUIRED)

add_executable(app main.cpp)
target_include_directories(app PRIVATE ${DOCOPT_INCLUDE_DIRS})
target_link_libraries(app PRIVATE strings-n-scales docopt)
