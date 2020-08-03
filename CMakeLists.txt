cmake_minimum_required(VERSION 3.16)
project(printf)

set(CMAKE_CXX_STANDARD 14)

add_executable(ft_printf
        ft_printf.c ft_printf.h parser.c)
