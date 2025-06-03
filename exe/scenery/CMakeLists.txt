################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    CameraTableUI.cpp
    ControlPanelUI.cpp
    InspectorUI.cpp
    RenderedTableUI.cpp
    SceneEditor.cpp
    SceneTableUI.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon 
    PRIVATE
        ImGuiFileDialog
)


