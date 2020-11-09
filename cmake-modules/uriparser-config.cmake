include(ExternalProject)

ExternalProject_Add(URIParser 
    URL https://github.com/uriparser/uriparser/releases/download/uriparser-0.9.4/uriparser-0.9.4.tar.gz
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
        -DCMAKE_BUILD_TYPE:STRING=Release
        -DURIPARSER_BUILD_TESTS:BOOL=OFF
        -DURIPARSER_BUILD_DOCS:BOOL=OFF
        -DBUILD_SHARED_LIBS:BOOL=OFF
)
