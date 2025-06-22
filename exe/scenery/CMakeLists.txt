################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    CameraTableUI.cpp
    CameraSelectEvent.cpp
    ControlPanelUI.cpp
    InspectorUI.cpp
    MetricsUI.cpp
    RenderedSelectEvent.cpp
    RenderedTableUI.cpp
    SceneEditor.cpp
    SceneTableUI.cpp
    
    main.cpp
    
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon 
    PRIVATE
        ImGuiFileDialog
)


