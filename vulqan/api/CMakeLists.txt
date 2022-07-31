################################################################################
##
##  YOUR QUILL
##
################################################################################

# project(yqvulqan)

include(${YOUR_QUILL_EXTERNAL}/stb.cmake)
include(${YOUR_QUILL_EXTERNAL}/vma.cmake)
include(${YOUR_QUILL_EXTERNAL}/imgui.cmake)


find_package(GLFW3 REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)


if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(test_source ./test.cpp)
endif()


add_library(yqvulqan SHARED 
    ${test_source}
    
    ./MyImGui.cpp
    
    ./YqEngineConfig.cpp
    
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
    
    ./widget/TextArea.cpp


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
        stb
        imgui
        ${Vulkan_LIBRARIES} 
        ${GLFW3_LIBRARY}
)
target_include_directories(yqvulqan 
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}
)

LinkTest(yqvulqan)


