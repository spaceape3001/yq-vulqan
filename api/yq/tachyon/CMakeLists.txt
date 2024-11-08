################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)


find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    strings.cpp

    #Application.cpp
    #GLFWManager.cpp
    
    MyImGui.cpp
    
    #Viewer.cpp
    #ViGui.cpp
    vulqan.cpp
    VulqanManager.cpp

    app/Manager.cpp
    
    buffer/Buffer.cpp

    core/Tachyon.cpp
    core/Thread.cpp

    camera/Camera.cpp
   
    cameras/cameras.cpp
    
    commands/commands.cpp
    
    config/build.cpp
    
    editor/Editor.cpp
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    events/events.cpp
    
    # font/Font.cpp      # Issue/TODO
    
    # frame/AppFrame.cpp # Issue/TODO
    
    #glfw/GLFWManager.cpp
    glfw/Joystick.cpp
    glfw/Monitor.cpp
    glfw/VideoMode.cpp

    image/Raster.cpp
    image/STBImage.cpp

    manipulator/Manipulator.cpp
    
    pass/RenderPass.cpp

    pipeline/Pipeline.cpp
    pipeline/PipelineUtils.cpp

    render/Render2D.cpp
    render/Render3D.cpp
    render/Rendered.cpp

    renders/renders.cpp

    replies/replies.cpp
    
    
    requests/requests.cpp

    sampler/Sampler.cpp
    sampler/SamplerInfoFile.cpp

    scene/Perspective.cpp
    
    shader/GLSLShader.cpp
    shader/Shader.cpp
    
    task/Task.cpp
    task/TaskEngine.cpp

    texture/Texture.cpp

    tool/Tool.cpp

    undo/Undo.cpp

    # v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    v/VqUtils.cpp
    
    #viewer/GLFWManager.cpp
    
    viz/ViCommandBufferVector.cpp
    viz/ViData.cpp
    viz/ViFrame.cpp
    viz/ViPipeline.cpp
    viz/ViPipelineLayout.cpp
    viz/ViRendered.cpp
    viz/ViTasker.cpp
    viz/ViThread.cpp
    viz/ViVisualizer.cpp
    viz/Visualizer.cpp
    
    viz/viz.cpp
    
    widget/Widget.cpp
    
    #widgets/ImGuiDemoWidget.cpp
    #widgets/Scene3DWidget.cpp
    #widgets/StackedWidget.cpp
    #widgets/TextArea.cpp
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
    ${VULQAN_API_DIR}
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_asset
    yq_color
    yq_gui3rd
    yq_imgui 
    yq_keyv
    yq_post
    yq_process
    yq_raster
    yq_stb 
    yq_vma

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)

LinkTest(${PROJECT_NAME})
