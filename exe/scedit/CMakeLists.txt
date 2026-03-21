################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scedit)

find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME}
    SceneApp.cpp
    SceneApp.hpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
    yq_assetqt
    yq_assetvk
    yq_graph
    yq_graphQt
    yq_symbolQt
    yq_xg
    Qt6::PrintSupport
)
