################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(ImGuiFileDialog SHARED
    ImGuiFileDialog/ImGuiFileDialog.cpp
)

target_include_directories(ImGuiFileDialog
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/ImGuiFileDialog
)

target_link_libraries(ImGuiFileDialog PUBLIC ImGui)
target_compile_options(ImGuiFileDialog  PRIVATE 
    -w
)

LinkTest(ImGuiFileDialog)

