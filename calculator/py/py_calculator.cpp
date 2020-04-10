#include <pybind11/pybind11.h>
#include "calculator.hpp"

namespace py = pybind11;


PYBIND11_MODULE(calculator, m) {
    m.doc() = u8"testCppProjectByPython";

    m.def("add", ns::add, py::arg("a"), py::arg("b"));
    m.def("subtract", ns::subtract, py::arg("a"), py::arg("b"));
    m.def("multiply", ns::multiply, py::arg("a"), py::arg("b"));
    m.def("divide", ns::divide, py::arg("a"), py::arg("b"));
    m.def("minimum", ns::min, py::arg("a"), py::arg("b"));
    m.def("maximum", ns::max, py::arg("a"), py::arg("b"));
}


