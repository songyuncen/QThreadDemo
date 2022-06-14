cmake_minimum_required(VERSION 3.21)
project(BaijiuDemo)

set_property(GLOBAL PROPERTY USE_FOLDERS 1)
set_property(GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "Generated Files")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(distilling WIN32
  main.cc
  main_widget.h
  main_widget.cc
  monitor.h
  monitor.cc
  executor.h
  executor.cc)

target_link_libraries(distilling PRIVATE Qt6::Widgets)


