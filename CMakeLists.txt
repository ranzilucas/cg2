cmake_minimum_required(VERSION 3.8)
project(ImageClass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ExemploDeManipulacaoDeImagens.cpp
        ExemploTexturas.cpp
        ImageClass.cpp
        ImageClass.h
        Texture.cpp
        Texture.h
        TextureClass.cpp
        TextureClass.h)

include_directories(.)

add_executable(ImageClass ${SOURCE_FILES})