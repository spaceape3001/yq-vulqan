################################################################################
##
##  ROCKS!
##
################################################################################

project(rocks)

add_executable(${PROJECT_NAME} 
    rocks.cpp
    MainWidget.cpp
    RockApp.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        yq_tachyon 
)

