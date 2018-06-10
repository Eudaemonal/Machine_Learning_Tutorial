# CUDA Intro

https://devblogs.nvidia.com/even-easier-introduction-cuda/

## Getting Started

This project is a simple useage of CUDA in C++, as we are going to use GPU for acceleration in machine learning. This tutorial will show you the advantage of using GPU over CPU. 

The examples are implementations of large vector addition.
```test01.cu``` CUDA Implemention.

Compile:   nvcc test01.cu -o test01
Run:       ./test01
Benchmark: nvprof ./test01


```test01.cpp```  Sequential execution in CPU. 

Compile:   g++ --std=c++14 test01.cpp -o test01 
Run:       ./test01

