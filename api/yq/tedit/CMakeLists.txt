################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tedit)


find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    TEApp.cpp
    TEAppThread.cpp
    TEAppThread.hpp
    TEDoc.cpp
    TEDoc.hpp
    TEEditor.cpp
    TEEditor.hpp
    TEViewer.cpp
    TEViewer.hpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
    yq_assetvk
)
