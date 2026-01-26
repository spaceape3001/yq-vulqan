################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_editorvk SHARED
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
)

target_link_libraries(yq_editorvk
    PUBLIC
        yq_lua
        yq_assetvk
        yq_tachyon
        yq_consolevk
)

vulqan_library(yq_editorvk)
yq_vklib(yq_editorvk)
LinkTest(yq_editorvk)
