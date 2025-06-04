################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    CameraAddMenuUI.cpp
    CameraTableUI.cpp
    ControlPanelUI.cpp
    InspectorUI.cpp
    RenderedAddMenuUI.cpp
    RenderedTableUI.cpp
    SceneAddMenuUI.cpp
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


