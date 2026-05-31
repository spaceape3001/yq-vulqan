################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_physicsvk)

add_library(${PROJECT_NAME} SHARED
    api_domain.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_tachyon
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})

