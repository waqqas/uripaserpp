cmake_minimum_required(VERSION 3.10)

project(tests)

file(GLOB SOURCES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/lib)

find_package(Catch2 REQUIRED)
add_dependencies(${PROJECT_NAME} Catch2)

find_package(URIParser REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC uriparser)
add_dependencies(${PROJECT_NAME} URIParser)
