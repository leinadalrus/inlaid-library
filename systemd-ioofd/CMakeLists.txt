cmake_minimum_required(VERSION 3.13)    # CMake version check
project(systemd_ioofd)                  # Create project
set(CMAKE_C_STANDARD 99)                # Enable c99 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.c)

# Add executable target with source files listed in SOURCE_FILES variable
find_package(ZLIB REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
