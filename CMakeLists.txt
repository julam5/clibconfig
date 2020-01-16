cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_executable(configtest	main.cpp config.cpp configobject.cpp)
#configobject.cpp

target_include_directories(configtest PRIVATE ${PROJECT_SOURCE_DIR}/lib)


target_link_libraries(configtest config++)