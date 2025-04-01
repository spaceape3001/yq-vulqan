################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(ImGuiColorTextEdit SHARED
    ImGuiColorTextEdit/TextEditor.cpp
)

target_include_directories(ImGuiColorTextEdit
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/ImGuiColorTextEdit
)

target_link_libraries(ImGuiColorTextEdit PUBLIC ImGui)
target_compile_options(ImGuiColorTextEdit  PRIVATE 
    -w
)

LinkTest(ImGuiColorTextEdit)

