cmake_minimum_required(VERSION 3.15)

project(csim2)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC "C:/Program Files/libOpenCOR/lib/libOpenCOR.lib")
target_include_directories(${PROJECT_NAME} PRIVATE "C:/Program Files/libOpenCOR/include/" "C:/Program Files/libOpenCOR/include/libopencor/module" )


#target_link_libraries(${PROJECT_NAME} PUBLIC /mnt/c/Users/dnic019/development/libopencor/usr/local/lib/libOpenCORd.a)
#target_include_directories(${PROJECT_NAME} PRIVATE /mnt/c/Users/dnic019/development/libopencor/usr/local/include /mnt/c/Users/dnic019/development/libopencor/usr/local/include/libopencor/module)