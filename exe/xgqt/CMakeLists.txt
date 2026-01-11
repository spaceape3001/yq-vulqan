################################################################################
##
##  YOUR QUILL
##
################################################################################

project(xgqt)

find_package(Qt6 REQUIRED Core Gui Widgets )

SET(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    MainWindow.hpp
    MainWindow.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
)
