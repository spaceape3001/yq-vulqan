################################################################################
##
##  YOUR QUILL
##
################################################################################

project(tachyon)

add_subdirectory(3rd)

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)


if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
    set(test_source ./test.cpp)
endif()


add_library(${PROJECT_NAME} SHARED 
    ${test_source}

    ./YqEngineConfig.cpp

    ./tachyon/tachyon.cpp
    ./tachyon/asset/asset.cpp
    ./tachyon/asset/render/render.cpp
    ./tachyon/enum/enum.cpp
    ./tachyon/gpu/gpu.cpp
    ./tachyon/host/host.cpp
    ./tachyon/MyImGui.cpp
    ./tachyon/gpu/Visualizer.cpp
    ./tachyon/scene/scene.cpp
    ./tachyon/task/task.cpp
    ./tachyon/ui/ui.cpp
    ./tachyon/viz/viz.cpp
    ./tachyon/widget/widget.cpp
    
    ./widget/TextArea.cpp
)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        YQ_USE_GLM=1
    PRIVATE 
        "-DYQ_DATA_DIR=\"${YQ_TACHYON_DATA_DIR}\"" 
        VK_ENABLE_BETA_EXTENSIONS=1
        DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
        DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
)
target_link_libraries(${PROJECT_NAME} 
    PUBLIC  
        yqtoolbox
        vma 
        stb
        ${Vulkan_LIBRARIES} 
        ${GLFW3_LIBRARY}
        gui3rd
        imgui
)
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}
        ${glm_INCLUDE_DIR}

)

LinkTest(${PROJECT_NAME})



