# 查找当前目录下的所有源文件

aux_source_directory(utils DIR_SOURCE_SRCS)


 # 指定生成目标
 add_executable( ${PROJECT_NAME}  ${DIR_SOURCE_SRCS} main.cpp)



 target_include_directories(${PROJECT_NAME} PRIVATE .)