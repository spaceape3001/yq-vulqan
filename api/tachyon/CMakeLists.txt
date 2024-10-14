project(yq_tachyon)


find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    strings.cpp

    2D/2D.cpp

    3D/Tetrahedron.cpp

    app/Application.cpp
    #asset/asset.cpp
    
    #basic/Tristate.cpp
    
    camera/Camera.cpp
    camera/NullCamera.cpp
    camera/SpaceCamera.cpp
    camera/TargetCamera.cpp
    
    command/Command.cpp
    
    config/build.cpp
    
    editor/Editor.cpp
    
    enum/enum.cpp
    enum/KeyCode.cpp
    
    event/Event.cpp
    event/KeyboardEvent.cpp
    event/JoystickEvent.cpp
    event/MonitorEvent.cpp
    event/MouseEvent.cpp
    event/WidgetEvent.cpp
    event/WindowEvent.cpp
    
    font/Font.cpp
    
    glfw/AppGLFW.cpp
    glfw/Joystick.cpp
    glfw/Monitor.cpp
    glfw/VideoMode.cpp
    
    image/image.cpp
    image/STBImage.cpp
    
    imgui/MyImGui.cpp
    imgui/ViGui.cpp
    
    manipulator/Manipulator.cpp
    
    memory/memory.cpp
    
    # pass/RenderPass.cpp
    
    pipeline/pipeline.cpp
    
    render/Render2D.cpp
    render/Render3D.cpp
    render/Rendered.cpp
    
    sampler/SamplerInfoFile.cpp
    sampler/sampler.cpp
    
    scene/Perspective.cpp

    shader/GLSLShader.cpp
    shader/Shader.cpp
    
    task/task.cpp
    
    texture/Texture.cpp
    
    tool/Tool.cpp
    
    undo/Undo.cpp
    
    v/VqApp.cpp
    #v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    v/VqUtils.cpp
    
    viewer/Viewer.cpp
    
    viz/ViCleanupManager.cpp
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
    
    widget/ImGuiDemoWidget.cpp
    widget/Scene3DWidget.cpp
    widget/StackedWidget.cpp
    widget/TextArea.cpp
    widget/Widget.cpp
    
    window/Window.cpp
    
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
    yq_process
    yq_raster
    yq_stb 
    yq_vma

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)

LinkTest(${PROJECT_NAME})
