################################################################################
##
##  YOUR QUILL
##
################################################################################

project(sce)

find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    SCEDoc.cpp
    SCEDoc.hpp
    SCEMain.cpp
    SCEMain.hpp
    SCEApp.cpp
    SCEApp.hpp
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
