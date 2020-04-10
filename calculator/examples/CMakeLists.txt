cmake_minimum_required(VERSION 3.15)

add_executable(example)

set_target_properties(example PROPERTIES
    FOLDER  "examples"  
)

target_sources(example
    PRIVATE example.cpp
)

target_link_libraries(example
    PRIVATE calculator
)
