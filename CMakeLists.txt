cmake_minimum_required(VERSION 3.2)

project(dem_converter "CXX")


set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "/MP /arch:AVX2 /EHsc")
  
file(GLOB_RECURSE src_files "src/*.rc" "src/*.cpp" "src/*.c" "src/*.h")
add_executable(${CMAKE_PROJECT_NAME}
    ${src_files}
)

target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC

    vendor/
)


