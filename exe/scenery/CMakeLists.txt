################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    CameraSelectEvent.cpp
    CameraTableUI.cpp
    ControlPanelUI.cpp
    InspectorUI.cpp
    LightSelectEvent.cpp
    LightTableUI.cpp
    MetricsUI.cpp
    ModelSelectEvent.cpp
    ModelTableUI.cpp
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


