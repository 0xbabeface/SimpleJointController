cmake_minimum_required(VERSION 3.10)
project(SimpleJointController CXX)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

add_library(control_tools
    average_filter.h
    average_filter.cc
    cubic_bezier.h
    cubic_bezier.cpp
)

link_libraries(
  control_tools
)
add_executable(main_controller
  main.cc
  simple_joint_controller.h
  simple_joint_controller.cc
)
