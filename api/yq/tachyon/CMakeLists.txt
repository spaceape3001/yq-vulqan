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

    Application.cpp
    Buffer.cpp
    Camera.cpp
    GLFWManager.cpp
    GLSLShader.cpp
    Joystick.cpp
    Manager.cpp
    Manipulator.cpp
    Monitor.cpp
    MyImGui.cpp
    Perspective.cpp
    Pipeline.cpp
    PipelineUtils.cpp
    Raster.cpp
    Render2D.cpp
    Render3D.cpp
    Rendered.cpp
    #RenderPass.cpp
    SamplerInfoFile.cpp
    Sampler.cpp
    Shader.cpp
    STBImage.cpp
    Tachyon.cpp
    Task.cpp
    TaskEngine.cpp
    Texture.cpp
    Thread.cpp
    Tool.cpp
    Undo.cpp
    VideoMode.cpp
    Viewer.cpp
    ViGui.cpp
    vulqan.cpp
    VulqanManager.cpp
    Widget.cpp
    
    2D/2D.cpp

    3D/Tetrahedron.cpp

   
    cameras/cameras.cpp
    
    commands/commands.cpp
    
    config/build.cpp
    
    #editor/Editor.cpp
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    events/events.cpp
    
    font/Font.cpp
    
    
    replies/replies.cpp
    
    requests/requests.cpp
    
    
    #v/VqEnumerations.cpp
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
    
    widgets/ImGuiDemoWidget.cpp
    widgets/Scene3DWidget.cpp
    widgets/StackedWidget.cpp
    widgets/TextArea.cpp
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
