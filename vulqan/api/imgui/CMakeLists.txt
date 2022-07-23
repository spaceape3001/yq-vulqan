################################################################################
##
##  YOUR QUILL
##
################################################################################

#   Library for any/all IMGUI widgets

find_package(GLFW3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(Freetype REQUIRED)

add_library(imgui SHARED 
    imgui.h
    imgui.cpp
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_user.cpp
    imgui_widgets.cpp
    backends/imgui_impl_vulkan.cpp
    backends/imgui_impl_glfw.cpp
    misc/cpp/imgui_stdlib.cpp
    misc/freetype/imgui_freetype.cpp
)

target_compile_definitions(imgui PRIVATE -DIMGUI_USE_WCHAR32=1 -DGLFW_INCLUDE_VULKAN=1)

target_include_directories(imgui 
    PUBLIC 
        . 
    PRIVATE 
        ${FREETYPE_INCLUDE_DIRS}
)

target_link_libraries(imgui PUBLIC 
    ${FREETYPE_LIBRARIES}
    ${GLFW3_LIBRARY} 
    ${Vulkan_LIBRARIES} 
    yqcore
)
    
LinkTest(imgui)

