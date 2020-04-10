# 使用 Python 测试 C++工程

C++由于语言的特点,应用会受到限制.譬如不容易构造原型来验证价值,不方便做工具,实现测试用例对测试人员要求太高.我们可以通过为 C++模块提供 Python 接口,然后借助于 Python 语言及其生态来帮助我们完成一些特定的需求,这里展示如何基于 pybind11 和 pytest 来测试 C++库.

实现路径如下:

1. 提供 C++库
2. 提供 C++库样例辅助开发
3. 利用 pybind11 提供 C++库的 python 模块
4. 提供基于 pytest 的测试用例
5. 整合演示
6. 存在的问题

## 环境要求

样例使用 CMake 3.15,Visual Studio,C++11 开发,因而建议你运行时准备如下环境:

1. CMake 3.15 及以上版本
2. Visual Studio 2019:由于只使用了 C++11,最低版本可以是 Visual Studio 2015,过程中会讲解如何调整配置文件以支持各种 Visual Studio 版本.
3. Python 3.6 及以上版本:请安装 64 位版本,32 位版本也可以,但是后续运行步骤需要调整.

针对 Python,请通过 pip 安装以下包:

1. wheel:用来构建二进制 Python 模块
2. pytest:所采用的测试框架 
3. pytest-xdist:需要并行运行测试用例安装此可选包
4. pytest-cov:需要测试用例覆盖率安装此可选包

## 必备基础知识

1. 基本的 C++知识

2. 基本的 Python 知识

3. 基本的命令行操作

4. 能够读懂 CMakeLists.txt

5. 能够使用 Visual Studio

## 目录结构及用途

| 文件/目录           | 用途                  |
| ------------------- | --------------------- |
| CMakeLists.txt      | 工程主配置            |
| README.md           | 本文档                |
| setup.py            | python 打包配置       |
| .editorconfig       | 编辑器配置            |
| pytest.ini          | pytest 框架需要       |
| external            | 第三方库目录          |
| external\pybind11   | pybind11 库下载及配置 |
| calculator          | 计算器目录            |
| calculator\include  | 头文件目录            |
| calculator\src      | 源文件目录            |
| calculator\examples | 示例目录              |
| calculator\py       | python 接口模块源码   |

## C++工程如何运行

在本目录打开命令行,执行:

```bat
cmake  -S . -B build/x64 -G"Visual Studio 16 2019" -A x64
```

这时在`build/x64`下会生成`testCppProjectByPython.sln`,双击打开按照常规 Visual Studio 工程操作即可.

## Python 包如何构建

在本目录打开命令行,执行:

```bat
python setup.py bdist_wheel
```

这时会在`dist`下生成类似`example-1.0.0.0-cp37-cp37m-win_amd64.whl`的文件,通过以下方式安装:

```bat
pip install dist\example-1.0.0.0-cp37-cp37m-win_amd64.whl
```

然后即可运行`tests`下的测试用例,在本目录打开命令行,执行:

```bat
python -m pytest
```

## 如何使用 Visual Studio 201x

假设你使用的是 Visual Studio 2015,如果需要构建 C++工程,则需要执行:

```bat
cmake  -S . -B build/x64 -G"Visual Studio 14 2015" -A x64
```

而构建 Python 包则需要调整`setup.py`中的代码:

```python
generator = 'Visual Studio 14 2015'
toolset = 'v140'
```

## 存在的问题

由于我们构建的是 Python 接口模式,pytest 测试的覆盖率输出是不正确的,你可以选择将所有的接口都使用 Python 代码包裹一层.
