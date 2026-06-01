################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_physicsvk)

add_library(${PROJECT_NAME} SHARED
    api_domain.cpp
    api_kinetic.cpp
    
    command_position.cpp
    command_size.cpp
    
    interface.cpp
    proxy_position.cpp
    
    api/Collision.cpp
    api/Physics.cpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_tachyon
)

yq_vklib(${PROJECT_NAME})
LinkTest(${PROJECT_NAME})

