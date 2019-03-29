cmake_minimum_required(VERSION 3.13)
project(Filler C)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(mshvets.filler
        ${LIBA}
        src/main.c
        inc/filler.h
        src/find_place_for_frag.c
        src/initialisation.c)

link_libraries(libft/libft.a)