cmake_minimum_required(VERSION 3.10)

project(tests)

include(ExternalProject)
ExternalProject_Add(catch2 
    URL https://github.com/catchorg/Catch2/releases/download/v2.11.1/catch.hpp
    DOWNLOAD_DIR ${CMAKE_INSTALL_PREFIX}/include/catch2
    DOWNLOAD_NO_EXTRACT 1
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)
file(GLOB SOURCES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_SOURC_DIR}/include)
include_directories(${CMAKE_INSTALL_PREFIX}/include)

add_dependencies(${PROJECT_NAME} catch2)

