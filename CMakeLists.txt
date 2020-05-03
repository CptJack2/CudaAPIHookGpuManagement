cmake_minimum_required(VERSION 3.13)

INCLUDE_DIRECTORIES(/usr/local/cuda/include)

add_library(cudart SHARED cudart100_stub.cpp)
target_link_libraries(cudart dl)
set_target_properties(cudart PROPERTIES VERSION 10.0)

add_library(cuda SHARED cudadev100_stub.cpp)
target_link_libraries(cuda dl)

add_executable(main main.cpp)
target_link_libraries(main cudart)