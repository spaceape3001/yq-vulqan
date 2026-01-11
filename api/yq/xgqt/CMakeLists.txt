################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_xgqt)

find_package(Qt6 REQUIRED Core Gui Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    xgqt.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    yq_tachyon
    yq_vkqt
    yq_gluon
    yq_core
)

LinkTest(${PROJECT_NAME})

