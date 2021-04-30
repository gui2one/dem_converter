cmake_minimum_required(VERSION 2.8)

project(dem_converter)


file(GLOB_RECURSE src_files "src/*.rc" "src/*.cpp" "src/*.c" "src/*.h")
add_executable(${CMAKE_PROJECT_NAME}
    ${src_files}
)

target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC

    vendor/
)
