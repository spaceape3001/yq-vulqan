################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(textking textking.cpp)
target_link_libraries(textking yq_tachyon  yq_assetvk ImGuiColorTextEdit ImGuiFileDialog)

