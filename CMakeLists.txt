cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_executable(c++_example1	main.cpp config.cpp)


target_include_directories(c++_example1 PRIVATE ${PROJECT_SOURCE_DIR}/lib)


target_link_libraries(c++_example1 config++)