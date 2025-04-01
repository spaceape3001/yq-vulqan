################################################################################
##
##  YOUR QUILL
##
################################################################################

find_package(GLFW3 REQUIRED)
find_package(Freetype REQUIRED)
set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(ImGui SHARED
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/misc/cpp/imgui_stdlib.cpp
    imgui/misc/freetype/imgui_freetype.cpp
)

target_include_directories(ImGui
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/imgui
    PRIVATE
        ${FREETYPE_INCLUDE_DIRS}
)

target_compile_definitions(ImGui
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        IMGUI_USE_WCHAR32=1 
        IMGUI_ENABLE_FREETYPE=1
    PRIVATE 
        VK_ENABLE_BETA_EXTENSIONS=1
        DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
        DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
)

target_link_libraries(ImGui
    PUBLIC  
        STBImage
        ${FREETYPE_LIBRARIES}
    PRIVATE
        ${GLFW3_LIBRARY}
)

target_compile_options(ImGui  PRIVATE 
    -w
)


LinkTest(ImGui)
