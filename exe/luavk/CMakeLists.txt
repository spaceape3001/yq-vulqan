################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(luavk 
    LuaPanel.cpp
    LuaWin.cpp
    main.cpp
)
target_link_libraries(luavk 
PUBLIC
    yq_tachyon yq_lua yq_luavk yq_date
PRIVATE
    ImGuiFileDialog
)
