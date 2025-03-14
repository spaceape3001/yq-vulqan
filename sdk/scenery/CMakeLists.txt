################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    MainWidget.cpp
    ScenePane.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon 
)


