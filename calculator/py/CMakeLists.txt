cmake_minimum_required(VERSION 3.15)

pybind11_add_module(py_calculator)

set_target_properties(py_calculator PROPERTIES
    OUTPUT_NAME "calculator"
    PDB_NAME    "py_calculator"
    FOLDER "extras"
)

target_sources(py_calculator
    PRIVATE  py_calculator.cpp
)

set_target_properties(py_calculator PROPERTIES
    FOLDER  "extras"  
)

target_link_libraries(py_calculator
    PRIVATE calculator
)


