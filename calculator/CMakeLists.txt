cmake_minimum_required(VERSION 3.15)

set(TARGET_NAME calculator)

set(${TARGET_NAME}_SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE  ${TARGET_NAME}_HEADER_FILES
    LIST_DIRECTORIES  False  CONFIGURE_DEPENDS
    "${${TARGET_NAME}_SOURCE_DIR}/include/*.h*"
)

file(GLOB_RECURSE  ${TARGET_NAME}_SRC_FILES
    LIST_DIRECTORIES  False  CONFIGURE_DEPENDS
    "${${TARGET_NAME}_SOURCE_DIR}/src/*.h*"
    "${${TARGET_NAME}_SOURCE_DIR}/src/*.c*"
    "${${TARGET_NAME}_SOURCE_DIR}/src/*.rc"
    "${${TARGET_NAME}_SOURCE_DIR}/src/*.qrc"
)
source_group(
    TREE  "${${TARGET_NAME}_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${${TARGET_NAME}_HEADER_FILES}
)
source_group(
    TREE  "${${TARGET_NAME}_SOURCE_DIR}/src/"
    PREFIX "Source Files"
    FILES ${${TARGET_NAME}_SRC_FILES}
)

add_library(${TARGET_NAME} SHARED)

target_sources(${TARGET_NAME}
    PRIVATE  ${${TARGET_NAME}_HEADER_FILES}
    PRIVATE  ${${TARGET_NAME}_SRC_FILES}
)
set_target_properties(${TARGET_NAME}  PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS  True
    FOLDER  "libs"
)
target_include_directories(${TARGET_NAME}
    PUBLIC
        "$<BUILD_INTERFACE:${${TARGET_NAME}_SOURCE_DIR}/include>"
    PRIVATE
        "$<BUILD_INTERFACE:${${TARGET_NAME}_SOURCE_DIR}/src>"
)

add_subdirectory(examples)
add_subdirectory(py)
