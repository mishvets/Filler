cmake_minimum_required(VERSION 3.12)
project(Filler C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(Libft LIBA)

add_executable(Filler
        ${LIBA}
        main.c)

link_libraries(./libft/libft.a)