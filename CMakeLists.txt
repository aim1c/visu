cmake_minimum_required(VERSION 3.13)
project(visu C)      # project name

set(CMAKE_C_STANDARD 99)
#flags
  #  add_compile_options(-Wall -Wextra)
#apple frameworks
    find_library(OPEN_GL OpenGl)
    find_library(APP_KIT AppKit)
#directory with libft_project
    include_directories(./libft/libft)
#ADD LIBFT as sources
    FILE(GLOB LIBFT_SRCS ./libft/libft/*.c)
#ADD visualizer *.c as sources
    FILE(GLOB VISU_SRCS source/*.c)
#find SDL2 && SDL2TTF
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${visu_SOURCE_DIR}/cmake")
    find_package(SDL2 REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    include_directories(${SDL2_TTF_INCLUDE_DIR})
#create binary
    add_executable(visu ${LIBFT_SRCS} ${VISU_SRCS} source/strt.c source/text.c) # all project-c-files here
#mkdir run and move ./visu
    set_target_properties(visu PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../run")
#links
    target_link_libraries(visu ${OPEN_GL} ${APP_KIT})
    target_link_libraries(visu ${SDL2_LIBRARIES})
    target_link_libraries(visu ${SDL2_TTF_LIBRARIES})

#${LIBFT}