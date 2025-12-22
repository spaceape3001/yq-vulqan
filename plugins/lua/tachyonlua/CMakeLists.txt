################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(tachyonlua SHARED 
    camera.cpp
    command.cpp
    event.cpp
    interface.cpp
    light.cpp
    post.cpp
    rendered.cpp
    reply.cpp
    request.cpp
    scene.cpp
    sys.cpp
    tachyon.cpp
    thread.cpp
    viewer.cpp
    vulkan.cpp
    widget.cpp
)
target_link_libraries(tachyonlua PUBLIC yq_lua yq_tachyon)
LinkTest(tachyonlua)
