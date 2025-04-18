cmake_minimum_required(VERSION 3.15)

project(csim2)


# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

# target_link_libraries(${PROJECT_NAME} PUBLIC 
#     "C:/Program Files/libOpenCOR/lib/libOpenCOR.lib"
#     "argparse"
# )
# target_include_directories(${PROJECT_NAME} PRIVATE 
#     "include" 
#     "C:/Program Files/libOpenCOR/include/"
#     "C:/Program Files/libOpenCOR/include/libopencor/module"
# )
target_link_libraries(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}/../alan/libOpenCOR-2025.04.08-Windows-Intel-Static-Release/lib/libOpenCOR.lib"
    "argparse"
)
target_include_directories(${PROJECT_NAME} PRIVATE 
    "include" 
    "${CMAKE_SOURCE_DIR}/../alan/libOpenCOR-2025.04.08-Windows-Intel-Static-Release/include/"
    "${CMAKE_SOURCE_DIR}/../alan/libOpenCOR-2025.04.08-Windows-Intel-Static-Release/include/libopencor/module"
)

# target_link_libraries(${PROJECT_NAME} PUBLIC 
#     "/mnt/c/Users/dnic019/development/libopencor/usr/local/lib/libOpenCORd.a"
#     "argparse"
# )
# target_include_directories(${PROJECT_NAME} PRIVATE 
#     "/mnt/c/Users/dnic019/development/libopencor/usr/local/include"
#     "/mnt/c/Users/dnic019/development/libopencor/usr/local/include/libopencor/module"
#     "include"
# )