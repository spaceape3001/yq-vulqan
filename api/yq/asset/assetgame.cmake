################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_assetgame)

add_library(${PROJECT_NAME} SHARED
    assetgame.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    yq_gamevk
    yq_tachyon
    yq_core
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})

