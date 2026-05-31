################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_physicsvk)

add_library(${PROJECT_NAME} SHARED
    physicsvk.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_tachyon
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})

