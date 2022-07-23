################################################################################
##
##  YOUR QUILL
##
################################################################################

# project(yqvulqan)

include(${YOUR_QUILL_EXTERNAL}/stb.cmake)


find_package(GLFW3 REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

find_package(Freetype REQUIRED)

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(test_source ./test.cpp)
endif()


add_library(yqvulqan SHARED 
    ${test_source}
    
    ./YqEngineConfig.cpp
    
    ./vma.cpp
    
    ./asset/asset.cpp
    ./engine/engine.cpp
    ./engine/Viewer.cpp

    ./engine/Asset.cpp
    ./engine/Shader.cpp
    ./engine/Texture.cpp
    
    ./engine/render/Pipeline.cpp
    ./engine/render/Rendered.cpp
    ./engine/render/Render3D.cpp

#    ./engine/vulqan/VqCommandFrame.cpp
       
#    ./engine/vulqan/VqObject.cpp
#    ./engine/vulqan/VqObjectFrame.cpp
    ./engine/vulqan/VqPipeline.cpp

    ./imgui/imgui.h
    ./imgui/imgui.cpp
    ./imgui/imgui_demo.cpp
    ./imgui/imgui_draw.cpp
    ./imgui/imgui_tables.cpp
    ./imgui/imgui_user.cpp
    ./imgui/imgui_widgets.cpp
    ./imgui/backends/imgui_impl_vulkan.cpp
    ./imgui/backends/imgui_impl_glfw.cpp
    ./imgui/misc/cpp/imgui_stdlib.cpp
    ./imgui/misc/freetype/imgui_freetype.cpp

)
target_compile_definitions(yqvulqan 
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
    PRIVATE 
        "-DYQ_DATA_DIR=\"${CMAKE_CURRENT_LIST_DIR}/data\"" 
        VK_ENABLE_BETA_EXTENSIONS=1
        IMGUI_USE_WCHAR32=1 
)
target_link_libraries(yqvulqan 
    PUBLIC  
        yqtoolbox
        vma 
        ${FREETYPE_LIBRARIES}
        ${Vulkan_LIBRARIES} 
        ${GLFW3_LIBRARY}
)
target_include_directories(yqvulqan 
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/imgui        
    PRIVATE 
        ${FREETYPE_INCLUDE_DIRS}
)

LinkTest(yqvulqan)


