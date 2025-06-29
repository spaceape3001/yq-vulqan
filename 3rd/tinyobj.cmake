################################################################################
##
##  YOUR QUILL
##
################################################################################

if(NOT TARGET TinyOBJ)
    add_library(TinyOBJ SHARED
        ${CMAKE_CURRENT_LIST_DIR}/tinyobj/tiny_obj_loader.cc
    )
    target_include_directories(TinyOBJ PUBLIC ${CMAKE_CURRENT_LIST_DIR}/tinyobj)
endif()

