cmake_minimum_required(VERSION 3.10)
project(scratch-neural-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(neural_net
    src/main.cpp
    src/matrix.cpp
    src/network.cpp
    src/layer.cpp
    src/math_utils.cpp
    src/gradient_descent.cpp
)

target_include_directories(neural_net PRIVATE include)