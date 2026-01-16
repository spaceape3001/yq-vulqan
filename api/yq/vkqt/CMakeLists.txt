################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_vkqt)

find_package(Qt6 REQUIRED Core Gui Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    utility.cpp
    app/YApp.hpp
    app/YApp.cpp
    app/YAppThread.hpp
    app/YAppThread.cpp
    app/YMain.hpp
    app/YMain.cpp
    app/YTachyon.hpp
    app/YTachyon.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    yq_tachyon
    yq_gluon
    yq_core
)

LinkTest(${PROJECT_NAME})
