################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_xgvk SHARED
    ui/XGView.cpp
)
target_link_libraries(yq_xgvk
    PUBLIC
        yq_xg
        yq_canvasvk
        yq_tachyon
)

vulqan_library(yq_xgvk)
LinkTest(yq_xgvk)
