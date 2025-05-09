cmake_minimum_required(VERSION 3.10)
project(TextFilterStrategy)
set(CMAKE_CXX_STANDARD 17)
add_executable(TextFilter
  main.cpp
  TextProcessor.cpp
  ReverseStrategy.cpp
  UppercaseStrategy.cpp
  RemoveVowelsStrategy.cpp
  CensorStrategy.cpp
)
