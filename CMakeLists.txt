cmake_minimum_required(VERSION 3.13)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

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
        COMMAND nvcc -g --cudart=shared -o testcudart ../saxpy.cu)

add_executable(testcudadev drivertest.cpp)
target_link_libraries(testcudadev -lcuda)#/usr/local/cuda/lib64/stub/libcuda.so)
ADD_CUSTOM_COMMAND(TARGET testcudadev
        COMMAND nvcc -g --ptx -o matSumKernel.ptx ../matSumKernel.cu)
#nvcc --ptx -o matSumKernel.ptx ../matSumKernel.cu

add_custom_target(install_hook
        COMMAND rm /usr/local/cuda/lib64/libcudart.so.10.0
        COMMAND rm /usr/lib/x86_64-linux-gnu/libcuda.so.1
        COMMAND cp libcudart.so.10.0 /usr/local/cuda/lib64
        COMMAND cp libcuda.so.1 /usr/lib/x86_64-linux-gnu)

add_custom_target(uninstall_hook
        COMMAND rm /usr/local/cuda/lib64/libcudart.so.10.0
        COMMAND ln -s /usr/local/cuda/lib64/libcudart.so.10.0.130 /usr/local/cuda/lib64/libcudart.so.10.0
        COMMAND rm /usr/lib/x86_64-linux-gnu/libcuda.so.1
        COMMAND ln -s /usr/lib/x86_64-linux-gnu/libcuda.so.440.44 /usr/lib/x86_64-linux-gnu/libcuda.so.1)