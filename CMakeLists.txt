cmake_minimum_required(VERSION 3.18)
include(FetchContent)

project(cpp-scratch-convolution-network)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Try to find OpenCV first
find_package(OpenCV QUIET)
if(NOT OpenCV_FOUND)
    message(STATUS "OpenCV not found, fetching with FetchContent...")
    FetchContent_Declare(
        opencv
        GIT_REPOSITORY https://github.com/opencv/opencv.git
        GIT_TAG        4.9.0 # You can change this to your preferred version
    )
    FetchContent_MakeAvailable(opencv)
    set(OpenCV_DIR ${opencv_SOURCE_DIR}/build)
    find_package(OpenCV REQUIRED)
endif()

add_executable(${PROJECT_NAME}
    main.cpp
    preprocessing.cpp
    matrix.cpp
    run.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")