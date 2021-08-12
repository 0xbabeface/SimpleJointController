# Simple Joint Controller

This project creates a simple controller for joint.

1. simple_joint_controller: read data from sensor and calculate a desired joint position
2. average_filter: smooth data with noise using the average value of last pieces
3. cubic_bezier: generate a spline with start and end values

The enrty of the project is `main.cc`

## Compiling 

Make sure you have cmake and g++ installed.

1. mkdir build && cd build 
2. cmake ..
3. make -j

## Attention

This is just a toy project for interview. DO NOT coding like it in real porjects.