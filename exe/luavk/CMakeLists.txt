################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(luavk 
    LuaWin.cpp
    main.cpp
)
target_link_libraries(luavk 
PUBLIC
    yq_tachyon yq_lua yq_luavk
PRIVATE
    ImGuiFileDialog
)
