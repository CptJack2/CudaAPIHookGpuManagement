cmake_minimum_required(VERSION 3.13)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#change to your own location hosting the libs
SET(CUDART_LIB_DIR "/usr/local/cuda/lib64")
SET(CUDA_LIB_DIR "/usr/lib/x86_64-linux-gnu")

INCLUDE_DIRECTORIES(/usr/local/cuda/include include)
link_directories(/usr/local/cuda/lib64/stub)

add_library(cudart SHARED cudart100_stub.cpp)
target_link_libraries(cudart dl)
set_target_properties(cudart PROPERTIES VERSION 10.0)

add_library(cuda SHARED cudadev100_stub.cpp)
target_link_libraries(cuda dl)
set_target_properties(cuda PROPERTIES VERSION 1)

add_custom_target(testcudart
        COMMAND nvcc -g --cudart=shared -o testcudart ../saxpy.cu)

add_executable(testcudadev drivertest.cpp)
target_link_libraries(testcudadev -lcuda)#/usr/local/cuda/lib64/stub/libcuda.so)
ADD_CUSTOM_COMMAND(TARGET testcudadev
        COMMAND nvcc -g --ptx -o matSumKernel.ptx ../matSumKernel.cu)

add_custom_target(backup_libs
        COMMAND cp -d ${CUDART_LIB_DIR}/libcudart.so.10.0 ${CUDART_LIB_DIR}/libcudart.so.10.0.orig
        COMMAND cp -d ${CUDA_LIB_DIR}/libcuda.so.1 ${CUDA_LIB_DIR}/libcuda.so.1.orig
)
add_custom_target(install_hook
        COMMAND rm ${CUDART_LIB_DIR}/libcudart.so.10.0
        COMMAND rm ${CUDA_LIB_DIR}/libcuda.so.1
        COMMAND cp libcudart.so.10.0 ${CUDART_LIB_DIR}
        COMMAND cp libcuda.so.1 ${CUDA_LIB_DIR}
)
add_custom_target(uninstall_hook
        COMMAND rm ${CUDART_LIB_DIR}/libcudart.so.10.0
        COMMAND cp -d ${CUDART_LIB_DIR}/libcudart.so.10.0.orig ${CUDART_LIB_DIR}/libcudart.so.10.0
        COMMAND rm ${CUDA_LIB_DIR}/libcuda.so.1
        COMMAND cp -d ${CUDA_LIB_DIR}/libcuda.so.1.orig ${CUDA_LIB_DIR}/libcuda.so.1
)