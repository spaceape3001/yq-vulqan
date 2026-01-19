################################################################################
##
##  YOUR QUILL
##
################################################################################

project(xgqt)

find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    MainWindow.hpp
    MainWindow.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
    yq_assetqt
    yq_xgqt
    yq_xgxml
    Qt6::PrintSupport
)
