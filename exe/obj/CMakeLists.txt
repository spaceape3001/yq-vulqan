################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(obj 
    ObjTree.cpp
    ObjWin.cpp
    main.cpp
)

target_link_libraries(obj
PUBLIC
    yq_tachyon
    yq_assetvk
PRIVATE
    ImGuiFileDialog
    TinyOBJ
)
