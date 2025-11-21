################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(tachyonlua SHARED 
    command.cpp
    event.cpp
    interface.cpp
    post.cpp
    reply.cpp
    request.cpp
    tachyon.cpp
)
target_link_libraries(tachyonlua PUBLIC yq_lua yq_tachyon)
LinkTest(tachyonlua)
