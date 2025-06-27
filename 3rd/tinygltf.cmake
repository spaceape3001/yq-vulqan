################################################################################
##
##  YOUR QUILL
##
################################################################################

if(NOT TARGET TinyGLTF)
    add_library(TinyGLTF SHARED
        ${CMAKE_CURRENT_LIST_DIR}/tiny_gltf.cpp
    )
    target_include_directories(TinyGLTF PUBLIC ${CMAKE_CURRENT_LIST_DIR}/tinygltf ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(TinyGLTF PUBLIC STBImage)
endif()

