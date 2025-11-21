################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(xgvk 
    PalettePanel.cpp
    ViewPanel.cpp
    XGWin.cpp
    main.cpp
)

target_link_libraries(xgvk 
PUBLIC
    yq_tachyon yq_xg yq_xgvk
PRIVATE
    ImGuiFileDialog
)
