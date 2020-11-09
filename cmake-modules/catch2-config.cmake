include(ExternalProject)

ExternalProject_Add(Catch2 
    URL https://github.com/catchorg/Catch2/releases/download/v2.11.1/catch.hpp
    DOWNLOAD_DIR ${CMAKE_INSTALL_PREFIX}/include/catch2
    DOWNLOAD_NO_EXTRACT 1
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)
