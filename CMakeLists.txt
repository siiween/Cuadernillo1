cmake_minimum_required(VERSION 3.25)
project(Cuadernillo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cuadernillo1 src/main.cpp lib/tcomplejo.cpp include/tcomplejo.h lib/tvectorcom.cpp include/tvectorcom.h lib/tlistacom.cpp include/tlistacom.h)
