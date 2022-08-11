if(NOT TARGET imgui)
    find_package(GLFW3 REQUIRED)
    set(VULKAN_DIR $ENV{VULKAN_SDK})
    find_package(Vulkan REQUIRED)

    find_package(Freetype REQUIRED)
    set(widgets_dir ${CMAKE_CURRENT_LIST_DIR}/DearWidgets/src/api)
    set(imgui_dir ${CMAKE_CURRENT_LIST_DIR}/imgui)
    set(editor_dir ${CMAKE_CURRENT_LIST_DIR}/ImGuiColorTextEdit)
    set(filedlg_dir ${CMAKE_CURRENT_LIST_DIR}/ImGuiFileDialog)
    add_library(imgui SHARED
        ${imgui_dir}/imgui.cpp
        ${imgui_dir}/imgui.h
        ${imgui_dir}/imgui_demo.cpp
        ${imgui_dir}/imgui_draw.cpp
        ${imgui_dir}/imgui_tables.cpp
        ${imgui_dir}/imgui_widgets.cpp
        ${imgui_dir}/backends/imgui_impl_vulkan.cpp
        ${imgui_dir}/backends/imgui_impl_glfw.cpp
        ${imgui_dir}/misc/cpp/imgui_stdlib.cpp
        ${imgui_dir}/misc/freetype/imgui_freetype.cpp
#        ${widgets_dir}/dear_widgets.cpp
        ${editor_dir}/TextEditor.cpp
        ${filedlg_dir}/ImGuiFileDialog.cpp
    )
    target_include_directories(imgui 
        PUBLIC 
            ${imgui_dir}
            ${widgets_dir}
            ${editor_dir}
            ${filedlg_dir}
        PRIVATE 
            ${FREETYPE_INCLUDE_DIRS}
    )
    target_compile_definitions(imgui 
        PUBLIC 
            IMGUI_USE_WCHAR32=1 
            IMGUI_ENABLE_FREETYPE=1
        PRIVATE
            GLFW_INCLUDE_VULKAN=1
            DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
            DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
    )
    target_compile_options(imgui PRIVATE 
        -w
    )
    target_link_libraries(imgui 
        PUBLIC 
            ${Vulkan_LIBRARIES} 
            ${GLFW3_LIBRARY}
            ${FREETYPE_LIBRARIES}
    )
    LinkTest(imgui)
endif()

