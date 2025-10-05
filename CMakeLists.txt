cmake_minimum_required(VERSION 3.10..3.16)

project(YaCAD VERSION 0.1.0)

option(USE_HARDWARE_ACCELERATION "Enables hardware acceleration of Viewport" OFF)

add_subdirectory(src)
