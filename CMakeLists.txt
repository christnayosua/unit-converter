cmake_minimum_required(VERSION 3.10)
project(UnitConverter VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tambahkan include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Kumpulkan semua source files
file(GLOB SOURCES "src/*.cpp")

# Buat executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Opsi: Tambahkan testing (jika ada test)
enable_testing()