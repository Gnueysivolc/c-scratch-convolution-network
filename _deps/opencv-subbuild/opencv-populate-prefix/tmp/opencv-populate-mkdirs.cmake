# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-src"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-build"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/tmp"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/src/opencv-populate-stamp"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/src"
  "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/src/opencv-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/src/opencv-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ha/Documents/code/c++/c-scratch-convolution-network/_deps/opencv-subbuild/opencv-populate-prefix/src/opencv-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
