################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon2) # temporary until switched

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    
    #######################################################
    #   Core First
    
    source/yt/enums.cpp
    source/yt/strings.cpp

    source/yt/api/Action.cpp
    source/yt/api/Delegate.cpp

    source/yt/config/build.cpp

    source/yt/gfx/Buffer.cpp
    source/yt/gfx/Pipeline.cpp
    source/yt/gfx/PipelineUtils.cpp
    source/yt/gfx/Raster.cpp
    source/yt/gfx/RenderPass.cpp
    source/yt/gfx/Sampler.cpp
    source/yt/gfx/Shader.cpp
    source/yt/gfx/Texture.cpp

    source/yt/io/GLSLShader.cpp
    source/yt/io/SamplerInfoFile.cpp
    source/yt/io/STBImage.cpp

    source/yt/msg/Command.cpp
    source/yt/msg/Event.cpp
    source/yt/msg/Message.cpp
    source/yt/msg/Post.cpp
    source/yt/msg/Reply.cpp
    source/yt/msg/Request.cpp
    source/yt/msg/Trigger.cpp
    
    source/yt/os/Cursor.cpp
    source/yt/os/Desktop.cpp
    source/yt/os/Joystick.cpp
    source/yt/os/Keyboard.cpp
    source/yt/os/KeyCode.cpp
    source/yt/os/ModifierKey.cpp
    source/yt/os/Monitor.cpp
    source/yt/os/Mouse.cpp
    source/yt/os/VideoMode.cpp
    source/yt/os/Window.cpp

    #source/yt/ui/Editor.cpp
    source/yt/ui/MyImGui.cpp
    #source/yt/ui/Tool.cpp
    source/yt/ui/Undo.cpp
    source/yt/ui/Widget.cpp

    #######################################################
    #   Vulqan
    
    source/yv/vulqan.cpp
    source/yv/VulqanManager.cpp


    #######################################################
    #   Assets (Yes, the above will use some of these)

    source/ya/triggers/AndTrigger.cpp
    source/ya/triggers/KeyPressTrigger.cpp
    source/ya/triggers/NandTrigger.cpp
    source/ya/triggers/NorTrigger.cpp
    source/ya/triggers/NotTrigger.cpp
    source/ya/triggers/OrTrigger.cpp
    source/ya/triggers/PostTrigger.cpp
    
    source/ya/messages/EmptyMessage.cpp

    source/ya/posts/AnyPost.cpp
    source/ya/posts/EmptyPost.cpp
    source/ya/posts/StringPost.cpp

    source/ya/spatials/SimpleSpatial3.cpp
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

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/public
    ${CMAKE_CURRENT_LIST_DIR}/../../api
    ${VULQAN_API_DIR}
)


target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_asset
    yq_color
    yq_gui3rd
    yq_imgui 
    yq_keyv
    yq_process
    yq_raster
    yq_stb 
    yq_vma

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)
