# 查找当前目录下的所有源文件
aux_source_directory("${PROJECT_SOURCE_DIR}/source" DIR_SOURCE_SRCS)




# 指定生成目标
add_executable( ${PROJECT_NAME} 
                ${DIR_SOURCE_SRCS}
              )
              
#头文件包含
target_include_directories(${PROJECT_NAME} PRIVATE
                           ${SYS_FRAME_H}
                           )
 