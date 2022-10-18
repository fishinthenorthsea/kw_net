aux_source_directory(utils DIR_SOURCE_SRCS)
aux_source_directory(utils/component DIR_SOURCE_SRCS)
aux_source_directory(utils/object DIR_SOURCE_SRCS)
aux_source_directory(utils/sql DIR_SOURCE_SRCS)
aux_source_directory(utils/kvTable DIR_SOURCE_SRCS)

aux_source_directory(game DIR_SOURCE_SRCS)

aux_source_directory(component/ComponentHome DIR_SOURCE_SRCS)
 # 指定生成目标
add_executable(${PROJECT_NAME} main.cc  ${DIR_SOURCE_SRCS})