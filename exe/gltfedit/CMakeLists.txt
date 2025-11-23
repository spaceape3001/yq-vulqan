################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(gltfedit 
    GLTFTree.cpp
    GLTFWin.cpp
    main.cpp
)

target_link_libraries(gltfedit
PUBLIC
    yq_tachyon
    yq_assetvk
PRIVATE
    ImGuiFileDialog
)
