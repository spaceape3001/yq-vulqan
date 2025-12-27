################################################################################
##
##  YOUR QUILL
##
################################################################################

project(scenery)

add_executable(${PROJECT_NAME}
    #ControlPanelUI.cpp
    #LuaPanelUI.cpp
    SceneEditor.cpp
    
    event/CameraSelectEvent.cpp
    event/ControllerSelectEvent.cpp
    event/LightSelectEvent.cpp
    event/ModelSelectEvent.cpp
    event/RenderedSelectEvent.cpp
    event/SceneAddEvent.cpp
    event/SceneRemoveEvent.cpp
    event/SceneRenderModeEvent.cpp
    event/SceneSelectEvent.cpp
    event/SceneVisibilityEvent.cpp

    table/CameraTableUI.cpp
    table/ControllerTableUI.cpp
    table/LightTableUI.cpp
    table/ModelTableUI.cpp
    table/RenderedTableUI.cpp
    table/SceneTableUI.cpp

    data.cpp
    main.cpp
    
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon 
        yq_assetvk
        yq_luavk
        yq_date
    #PRIVATE
        #ImGuiFileDialog
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

