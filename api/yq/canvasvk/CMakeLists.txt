################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_canvasvk SHARED
    UICanvas.cpp
)

target_link_libraries(yq_canvasvk 
PUBLIC
    yq_color
    yq_tachyon
)

vulqan_library(yq_canvasvk)
yq_vulkan(yq_canvasvk)
LinkTest(yq_canvasvk)
