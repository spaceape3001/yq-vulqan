################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_gamevk)

add_library(${PROJECT_NAME} SHARED
    gamevk.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_tachyon
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})

