################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_assetphys)

add_library(${PROJECT_NAME} SHARED
     physics/NoPhysics.cpp
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC
    yq_tachyon
    yq_userexpr
    yq_physicsvk
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})


