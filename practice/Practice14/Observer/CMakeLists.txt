cmake_minimum_required(VERSION 3.10)
project(GradeBookObserver)
set(CMAKE_CXX_STANDARD 17)
add_executable(GradeSystem
  main.cpp
  GradeBook.cpp
  AverageObserver.cpp
  NotifierObserver.cpp
)
