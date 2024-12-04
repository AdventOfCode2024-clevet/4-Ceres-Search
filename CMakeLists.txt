cmake_minimum_required(VERSION 3.10)
project(CeresSearch)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
    src/ArgumentParser.cpp
    src/FileReader.cpp
)

set(HEADERS
    src/ArgumentParser.hpp
    src/FileReader.hpp
    src/XMASCounter.hpp
)

add_executable(CeresSearch ${SOURCES} ${HEADERS})
