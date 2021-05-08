cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_compile_options( -Wall -Wextra -Werror -Wconversion -Wno-unused -Wunused-value  -Wunused-variable -Wunused-macros -Wunused-function  -Wunused-label)
add_compile_options(-Wunused-local-typedefs -Wunused-const-variable)

include_directories(/ /Users/mwinter/ft_containers)


add_executable(ft_containers
        main.cpp
        Colors.hpp vector.hpp list_tester.cpp list.hpp queue.hpp stack.hpp)