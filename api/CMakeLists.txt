################################################################################
##
##  YOUR QUILL
##
################################################################################

project(tachyon)

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)


if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(test_source ./test.cpp)
endif()


add_library(${PROJECT_NAME} SHARED 
    ${test_source}
    
    ./tachyon/tachyon.cpp
    
    ./MyImGui.cpp
    
    ./YqEngineConfig.cpp
    
    ./asset/asset.cpp
    ./engine/engine.cpp
    ./engine/Viewer.cpp

    ./engine/render/Pipeline.cpp
    ./engine/render/Rendered.cpp
    ./engine/render/Render3D.cpp

#    ./engine/vulqan/VqCommandFrame.cpp
       
#    ./engine/vulqan/VqObject.cpp
#    ./engine/vulqan/VqObjectFrame.cpp
     ./engine/vulqan/VqPipeline.cpp
    
     ./widget/TextArea.cpp


)
target_compile_definitions(${PROJECT_NAME} 
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        YQ_USE_GLM=1
    PRIVATE 
        "-DYQ_DATA_DIR=\"${YQ_TACHYON_DATA_DIR}\"" 
        VK_ENABLE_BETA_EXTENSIONS=1
        IMGUI_USE_WCHAR32=1 
)
target_link_libraries(${PROJECT_NAME} 
    PUBLIC  
        yqtoolbox
        vma 
        stb
        imgui
        ${Vulkan_LIBRARIES} 
        ${GLFW3_LIBRARY}
)
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}
        ${glm_INCLUDE_DIR}
)

LinkTest(${PROJECT_NAME})


