################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    ControlPanelUI.cpp
    InspectorUI.cpp
    MetricsUI.cpp
    RenderedTableUI.cpp
    SceneEditor.cpp
    SceneTableUI.cpp
    
    main.cpp
    
    camera/CameraTableUI.cpp
    camera/CameraSelectEvent.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon 
    PRIVATE
        ImGuiFileDialog
)


