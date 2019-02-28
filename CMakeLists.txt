cmake_minimum_required(VERSION 3.13)
project(Filler C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(Libft LIBA)

add_executable(Filler
        ${LIBA}
        srcs/main.c
        includes/filler.h)

link_libraries(./libft/libft.a)