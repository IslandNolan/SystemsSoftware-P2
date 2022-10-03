cmake_minimum_required(VERSION 3.21)
project(SystemsSoftware_P2)

set(CMAKE_CXX_STANDARD 11)


add_executable(
        SystemsSoftware_P2 main.cpp
        opcodes.cpp
        symbols.cpp
        errors.cpp
        directives.cpp
)
