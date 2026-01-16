################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_xgvk SHARED
    command/XGVkCommand.cpp
    command/OpenXGFileCommand.cpp
    command/SaveXGFileCommand.cpp
    gesture/OpenXGFileGesture.cpp
    gesture/SaveXGFileGesture.cpp
    ui/XGViewUI.cpp
)
target_link_libraries(yq_xgvk
    PUBLIC
        yq_xg
        yq_xgxml
        #yq_canvasvk
        yq_tachyon
)

vulqan_library(yq_xgvk)
LinkTest(yq_xgvk)
