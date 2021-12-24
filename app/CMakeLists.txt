find_package(docopt COMPONENTS CXX REQUIRED)

add_executable(strings-n-scales main.cpp)
target_include_directories(strings-n-scales PRIVATE ${DOCOPT_INCLUDE_DIRS})
target_link_libraries(strings-n-scales PRIVATE sns-lib docopt)
