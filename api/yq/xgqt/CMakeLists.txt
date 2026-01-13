################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_xgqt)

find_package(Qt6 REQUIRED Core Gui Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    XGCanvasQt.hpp
    XGCanvasQt.cpp
    XGProject.hpp
    XGProject.cpp
    XGSceneQt.hpp
    XGSceneQt.cpp
    XGViewQt.hpp
    XGViewQt.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    yq_tachyon
    yq_vkqt
    yq_gluon
    yq_core
    yq_xg
)

LinkTest(${PROJECT_NAME})

