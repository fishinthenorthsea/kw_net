cmake_minimum_required(VERSION 3.15)

# project's  name
project(my_project VERSION 1.1.0 LANGUAGES C CXX)

# set the project name
set(PROJECT_NAME "kw_server")

# 设置编译参数
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread -std=gnu99 -g -o0") #
# -w 表示取消所有 warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11  -await -Wall  -g2 -ggdb -o0 -lpthread -w")
set(CMAKE_BUILD_TYPE "Release") # Release 如果是发行版本就更换Debug为Release

set(CMAKE_CXX_STANDARD 17)

set(ROOT_BIN_OUT_DIR ${PROJECT_SOURCE_DIR}/bin) # 设置输出到项目源文件夹的bin目录下
set(ROOT_ARC_OUT_DIR ${ROOT_BIN_OUT_DIR}) # 同上
set(ROOT_LIB_OUT_DIR ${ROOT_BIN_OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_ARC_OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_LIB_OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_BIN_OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${ROOT_ARC_OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${ROOT_LIB_OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_BIN_OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ROOT_ARC_OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${ROOT_LIB_OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOT_BIN_OUT_DIR})

# 让vs 也可以调试      就是简单的让lib放到vs可以检测到的位置
# file(COPY lib DESTINATION build/source)

add_subdirectory(${PROJECT_SOURCE_DIR}/source)
add_subdirectory(${PROJECT_SOURCE_DIR}/dependents)

# 头文件目录
target_include_directories(
    ${PROJECT_NAME} PUBLIC source
)



# 库文件目录
target_link_directories(${PROJECT_NAME} PUBLIC bin)

# mysql
target_link_libraries(${PROJECT_NAME} PUBLIC libmysql)
