# init
cmake_minimum_required(VERSION 3.16)
project(GtkUIMaker LANGUAGES CXX)


# standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# replace with dynamic argparse finder?
add_subdirectory(lib/argparse-3.2)


# gtk4
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# gtk4 windows specific stuff?

add_executable(GtkUIMaker src/main.cpp)
#argparse
target_link_libraries(GtkUIMaker PRIVATE argparse)

target_include_directories(GtkUIMaker PRIVATE ${GTK4_INCLUDE_DIRS})
target_compile_options(GtkUIMaker PRIVATE ${GTK4_CFLAGS_OTHER})

# link gtk4 libraries
target_link_libraries(GtkUIMaker PRIVATE ${GTK4_LIBRARIES})