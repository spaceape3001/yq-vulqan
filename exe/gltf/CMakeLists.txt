################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(gltf 
    GLTFTree.cpp
    GLTFWin.cpp
    main.cpp
)

target_link_libraries(gltf
PUBLIC
    yq_tachyon
    yq_assetvk
PRIVATE
    ImGuiFileDialog
)
