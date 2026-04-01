cmake_minimum_required(VERSION 3.20)
project(test1 LANGUAGES CXX)

# Standard C++ (ajuste selon tes besoins)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajoute l'exécutable
add_executable(test1 main.cpp)

#target_include_directories(test1 PUBLIC ${CMAKE_SOURCE_DIR}/Include)