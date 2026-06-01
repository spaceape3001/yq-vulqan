################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_physicsvk)

add_library(${PROJECT_NAME} SHARED
    api_domain.cpp
    api_kinetic.cpp

    aspect_position.cpp
    
    command_position.cpp
    command_size.cpp
    event_spatial.cpp
    
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

