add_library(sns-lib strings-n-scales.cpp)
target_include_directories(sns-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS sns-lib DESTINATION lib)
install(FILES strings-n-scales.h DESTINATION include)