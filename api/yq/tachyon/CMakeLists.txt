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

    2D/2D.cpp

    3D/Tetrahedron.cpp

    Application.cpp
    Camera.cpp
    

    GLFWManager.cpp
    GLSLShader.cpp
    Joystick.cpp
    Manager.cpp
    Monitor.cpp
    #MouseEvent.cpp
    MyImGui.cpp
    Shader.cpp
    Task.cpp
    TaskEngine.cpp
    Texture.cpp
    Undo.cpp
    VideoMode.cpp
    vulqan.cpp
    VulqanManager.cpp
    # Widget.cpp
    
    
    cameras/cameras.cpp
    
    #command/Command.cpp
    
    config/build.cpp
    
    #editor/Editor.cpp
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    events/InputEvent.cpp
    events/JoystickConnectEvent.cpp
    events/JoystickDisconnectEvent.cpp
    events/JoystickEvent.cpp
    events/KeyboardEvent.cpp
    events/KeyPressEvent.cpp
    events/KeyReleaseEvent.cpp
    events/MonitorConnectEvent.cpp
    events/MonitorEvent.cpp
    events/ViewerEvent.cpp
    events/VulqanEvent.cpp
    
    font/Font.cpp
    
    
    image/image.cpp
    image/STBImage.cpp
    
    
    #joystick/joystick.cpp
    
    #keyboard/keyboard.cpp
    
    #manipulator/Manipulator.cpp
    
    memory/memory.cpp
    
    #monitor/monitor.cpp
    
    # pass/RenderPass.cpp
    
    pipeline/pipeline.cpp
    
    render/Render2D.cpp
    render/Render3D.cpp
    render/Rendered.cpp
    
    sampler/SamplerInfoFile.cpp
    sampler/sampler.cpp
    
    scene/Perspective.cpp

    
    
    tool/Tool.cpp
    
    
    #v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    v/VqUtils.cpp
    
    #viewer/GLFWManager.cpp
    
    viz/ViCommandBufferVector.cpp
    viz/ViData.cpp
    viz/ViFrame.cpp
    #viz/ViGui.cpp
    viz/ViPipeline.cpp
    viz/ViPipelineLayout.cpp
    viz/ViRendered.cpp
    viz/ViTasker.cpp
    viz/ViThread.cpp
    viz/ViVisualizer.cpp
    viz/Visualizer.cpp
    
    viz/viz.cpp
    
    #widget/ImGuiDemoWidget.cpp
    #widget/Scene3DWidget.cpp
    #widget/StackedWidget.cpp
    #widget/TextArea.cpp
    #widget/Widget.cpp
    
    Viewer.cpp
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
