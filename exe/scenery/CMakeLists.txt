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
    

    data.cpp
    main.cpp
    
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        yq_tachyon
        yq_editorvk 
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

