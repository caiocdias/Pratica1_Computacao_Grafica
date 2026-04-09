cmake_minimum_required(VERSION 4.1)
project(Pratica1_Computacao_Grafica C)

set(CMAKE_C_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(Pratica1_Computacao_Grafica main.c)

target_link_libraries(Pratica1_Computacao_Grafica PRIVATE
        OpenGL::GL
        OpenGL::GLU
        GLUT::GLUT
)