cmake_minimum_required(VERSION 3.13)
project(visu C)      # project name

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra) # flags
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
include_directories(./libft/libft)  #directory with headers
add_library(libmlx STATIC IMPORTED)
set_property(TARGET libmlx PROPERTY
        IMPORTED_LOCATION /Users/fsnow-be/CLionProjects/visu/mlx/libmlx.a)
FILE(GLOB LIBFT_SRCS ./libft/libft/*.c)  # ADD LIBFT as sources

#FILE(GLOB LIBFT_SRCS ./libftT/*.c)  # ADD LIBFT as sources

add_executable(visu ${LIBFT_SRCS} main.c visu.h) # all project-c-files here
set_target_properties(visu PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../run")
target_link_libraries(visu ${OPEN_GL} ${APP_KIT})  # LINK libraries
target_link_libraries(visu libmlx)

#${LIBFT}