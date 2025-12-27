cmake_minimum_required(VERSION 3.10..3.16)
project(YaCAD VERSION 0.1.0 LANGUAGES CXX)

# GENERAL OPTION
option(USE_HARDWARE_ACCELERATION "Enables hardware acceleration of Viewport" OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
    if (USE_HARDWARE_ACCELERATION)
        find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
        add_definitions(-DUSE_HARDWARE_ACCELERATION)
    endif()

    qt_add_executable(yacad MANUAL_FINALIZATION
        src/main.cpp
        src/CustomScene.h src/CustomScene.cpp
        src/CustomView.h src/CustomView.cpp
        src/BasePropertyDialog.h
        src/DialogPanel.h src/DialogPanel.cpp
        src/dialogTrackMouse.h src/dialogTrackMouse.cpp
        src/DotGraphicsItem.h src/DotGraphicsItem.cpp
        src/dialogDrawPoint.h src/dialogDrawPoint.cpp
        src/dialogDrawLineSegment.h src/dialogDrawLineSegment.cpp
        src/LineSegmentItem.h src/LineSegmentItem.cpp
        src/DrawingWidget.h src/DrawingWidget.cpp
        src/MouseGizmo.h src/MouseGizmo.cpp
    )
endif()

target_link_libraries(yacad PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(yacad PRIVATE Qt6::Core Qt6::Widgets)
if (USE_HARDWARE_ACCELERATION)
    target_link_libraries(yacad PRIVATE Qt6::OpenGLWidgets)
endif()

include(GNUInstallDirs)
install(TARGETS yacad
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(yacad PROPERTIES MACOSX_BUNDLE TRUE)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(yacad)
endif()
