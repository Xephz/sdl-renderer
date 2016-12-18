project (renderer)
cmake_minimum_required(VERSION 3.3)

#tell cmake to use c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#list the source and header files
file(GLOB_RECURSE SOURCEFILES "src/*.cpp")
file(GLOB_RECURSE HEADERFILES "src/*.hpp")

#isolate unique include directories
set(INCLUDEDIRS "")
foreach (_header ${HEADERFILES})
    get_filename_component(_dir ${_header} PATH)
    list (APPEND INCLUDEDIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDEDIRS)

#set sources and include dirs
include_directories(${INCLUDEDIRS})
add_executable(renderer ${SOURCEFILES})

target_link_libraries(renderer m GL GLEW SDL2 assimp)

file(COPY assets DESTINATION ./)
