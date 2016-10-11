cmake_minimum_required(VERSION 2.8)
project(libeigentlich)

## Compiler Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -O2 -Wall")

## Set the source path
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(SRC ${SRC_DIR}/EigentlichBaseType.cpp
        ${SRC_DIR}/EigentlichInt.cpp
        )

add_library(eigentlich SHARED ${SRC})
add_executable(test-basetype
               src/test-basetype.cpp
               )

target_link_libraries(eigentlich)
target_link_libraries(test-basetype
                      eigentlich
                      )
