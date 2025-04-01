################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_gui3rd)

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)
find_package(Freetype REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)


if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(test_source ./test.cpp)
endif()

add_library(${PROJECT_NAME} SHARED
    #imgui/imgui.cpp
    #imgui/imgui.h
    #imgui/imgui_demo.cpp
    #imgui/imgui_draw.cpp
    #imgui/imgui_tables.cpp
    #imgui/imgui_widgets.cpp
    #imgui/cpp/imgui_stdlib.cpp
    #imgui/freetype/imgui_freetype.cpp
#        ${widgets_dir}/dear_widgets.cpp
    ImGuiColorTextEdit/TextEditor.cpp
    #ImGuiFileDialog/ImGuiFileDialog.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        #${CMAKE_CURRENT_LIST_DIR}/imgui
        ${CMAKE_CURRENT_LIST_DIR}/ImGuiColorTextEdit
        ${CMAKE_CURRENT_LIST_DIR}/ImGuiFileDialog
    PRIVATE
        ${FREETYPE_INCLUDE_DIRS}

)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        IMGUI_USE_WCHAR32=1 
        IMGUI_ENABLE_FREETYPE=1
    PRIVATE 
        VK_ENABLE_BETA_EXTENSIONS=1
        IMGUI_USE_WCHAR32=1 
        DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
        DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC  
        yq_imgui
        yq_stb
        ${FREETYPE_LIBRARIES}
)
target_compile_options(${PROJECT_NAME}  PRIVATE 
    -w
)



LinkTest(${PROJECT_NAME})

