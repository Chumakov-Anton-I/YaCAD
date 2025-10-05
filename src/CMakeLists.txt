cmake_minimum_required(VERSION 3.16)

project(yacad VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
    if (USE_HARDWARE_ACCELERATION)
        find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
        add_definitions(-DUSE_HARDWARE_ACCELERATION)
    endif()

    qt_add_executable(yacad MANUAL_FINALIZATION
        main.cpp
        CustomScene.h CustomScene.cpp
        CustomView.h CustomView.cpp
        BasePropertyDialog.h
        DialogPanel.h DialogPanel.cpp
        dialogTrackMouse.h dialogTrackMouse.cpp
        DotGraphicsItem.h DotGraphicsItem.cpp
        dialogDrawPoint.h dialogDrawPoint.cpp
        dialogDrawLineSegment.h dialogDrawLineSegment.cpp
        LineSegmentItem.h LineSegmentItem.cpp
        DrawingWidget.h DrawingWidget.cpp
        MouseGizmo.h MouseGizmo.cpp
    )
endif()

target_link_libraries(yacad PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(yacad PRIVATE Qt6::Core Qt6::Widgets)
target_link_libraries(yacad PRIVATE Qt6::Widgets)
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
