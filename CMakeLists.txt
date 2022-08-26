# CMakeList.txt : CMake project for Zoo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project ("Zoo")

if (MSVC AND CMAKE_VERSION VERSION_GREATER_EQUAL 3.21)
    set(CMAKE_CXX_ST"src/Zoo.cpp")
else ()
    set(CMAKE_CXX_STANDARD 20)
endif ()

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()


# Add source to this project's executable.
add_executable (Zoo "")

add_subdirectory (include)
add_subdirectory (src)
# TODO: Add tests and install targets if needed.
