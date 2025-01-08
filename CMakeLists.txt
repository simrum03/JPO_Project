cmake_minimum_required(VERSION 3.10)

project(JPO_PROJECT)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(main 
    src/main.cpp
    src/CaesarCipher.cpp
    src/Encryptor.cpp
    src/Decryptor.cpp
    src/RailFenceCipher.cpp
    src/Menu.cpp
)
