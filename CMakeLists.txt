cmake_minimum_required(VERSION 3.13)

INCLUDE_DIRECTORIES(/usr/local/cuda/include include)
link_directories(/usr/local/cuda/lib64/stub)

add_library(cudart SHARED cudart100_stub.cpp)
target_link_libraries(cudart dl)
set_target_properties(cudart PROPERTIES VERSION 10.0)

add_library(cuda SHARED cudadev100_stub.cpp)
target_link_libraries(cuda dl)
set_target_properties(cuda PROPERTIES VERSION 1)

#add_executable(testcudart testcudart.cpp)
#target_link_libraries(testcudart cudart)
add_custom_target(testcudart
        COMMAND nvcc --cudart=shared -o testcudart ../saxpy.cu)

add_executable(testcudadev drivertest.cpp)
target_link_libraries(testcudadev -lcuda)#/usr/local/cuda/lib64/stub/libcuda.so)
ADD_CUSTOM_COMMAND(TARGET testcudadev
        COMMAND nvcc --ptx -o matSumKernel.ptx ../matSumKernel.cu)
#nvcc --ptx -o matSumKernel.ptx ../matSumKernel.cu