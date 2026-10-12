cmake_minimum_required(VERSION 3.10)
project(scratch-neural-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(neural_net
    main.cpp
    matrix.cpp
    network.cpp
    layer.cpp
    math_utils.cpp
    gradient_descent.cpp
    )