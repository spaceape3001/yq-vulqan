################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_consolevk SHARED
    UIConsole.cpp
)

target_link_libraries(yq_consolevk 
PUBLIC
    yq_color
    yq_tachyon
)

vulqan_library(yq_consolevk)
yq_vklib(yq_consolevk)
LinkTest(yq_consolevk)
