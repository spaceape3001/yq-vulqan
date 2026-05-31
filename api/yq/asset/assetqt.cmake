################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_assetqt)

find_package(Qt6 REQUIRED Core Gui Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    assetqt.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    yq_tachyon
    yq_vkqt
    yq_gluon
    yq_core
)

LinkTest(${PROJECT_NAME})

