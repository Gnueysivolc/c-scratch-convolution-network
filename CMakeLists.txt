cmake_minimum_required(VERSION 3.0)
project (cpp-scratch-convolution-network)

# Set CMAKE_TOOLCHAIN_FILE to use the vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

# Set CMAKE_PREFIX_PATH to include the vcpkg installation directory
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${VCPKG_ROOT}/installed/${VCPKG_TARGET_TRIPLET})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/arm64-osx")

# Find OpenCV package
find_package (OpenCV REQUIRED)

# Create an executable
add_executable(${PROJECT_NAME} preprocessing.cpp)

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")