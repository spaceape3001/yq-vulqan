project(yqvulqan)


find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    2D/ImageQuad2.hpp
    2D/ImageQuad2.cpp
    2D/Quadrilateral.hpp
    2D/Quadrilateral.cpp
    2D/Triangle.hpp
    2D/Triangle.cpp
    
    3D/Tetrahedron.hpp
    3D/Tetrahedron.cpp

    app/AppCreateInfo.hpp

    asset/asset.cpp
    
    basic/Required.hpp
    basic/Tristate.hpp
    basic/Tristate.cpp
    
    camera/Camera.hpp
    camera/Camera.cpp
    camera/NullCamera.hpp
    camera/NullCamera.cpp
    camera/SpaceCamera.hpp
    camera/SpaceCamera.cpp
    camera/TargetCamera.hpp
    camera/TargetCamera.cpp
    
    command/Command.hpp
    command/Command.cpp
    
    config/build.hpp
    config/build.cpp
    
    data/ColorVertex2D.hpp
    data/ColorVertex3D.hpp
    data/ColorVertexData.hpp
    
    editor/Editor.hpp
    editor/Editor.cpp
    
    event/Event.hpp
    event/Event.cpp
    event/KeyboardEvent.hpp
    event/KeyboardEvent.cpp
    event/JoystickEvent.hpp
    event/JoystickEvent.cpp
    event/MonitorEvent.hpp
    event/MonitorEvent.cpp
    event/MouseEvent.hpp
    event/MouseEvent.cpp
    event/WidgetEvent.hpp
    event/WidgetEvent.cpp
    event/WindowEvent.hpp
    event/WindowEvent.cpp
    
    glfw/AppGLFW.hpp
    glfw/AppGLFW.cpp
    glfw/Joystick.hpp
    glfw/Joystick.cpp
    glfw/Logging.hpp
    glfw/Monitor.hpp
    glfw/Monitor.cpp
    glfw/VideoMode.hpp
    glfw/VideoMode.cpp
    
    image/image.cpp
    image/STBImage.cpp
    
    image_view/ImageViewCreateFlags.hpp
    image_view/ImageViewCreateFlags.cpp
    image_view/ImageViewInfo.hpp
    image_view/ImageViewType.hpp
    image_view/ImageViewType.cpp
    
    imgui/MyImGui.hpp
    imgui/MyImGui.cpp
    
    input/KeyCode.hpp
    input/KeyCode.cpp
    input/ModifierKey.hpp
    input/ModifierKey.cpp
    
    logic/CompareOp.hpp
    logic/CompareOp.cpp
    logic/LogicOp.hpp
    logic/LogicOp.cpp
    
    manipulator/Manipulator.hpp
    manipulator/Manipulator.cpp
    
    memory/memory.cpp
    pipeline/pipeline.cpp

    render/Render2D.hpp
    render/Render2D.cpp
    render/Render2DWriter.hpp
    render/Render3D.hpp
    render/Render3D.cpp
    render/Render3DWriter.hpp
    render/Rendered.hpp
    render/Rendered.cpp
    render/RenderedWriter.hpp
    
    sampler/BorderColor.hpp
    sampler/BorderColor.cpp
    sampler/SamplerAddressMode.hpp
    sampler/SamplerAddressMode.cpp
    sampler/SamplerCreateFlags.hpp
    sampler/SamplerCreateFlags.cpp
    sampler/SamplerFilter.hpp
    sampler/SamplerFilter.cpp
    sampler/SamplerInfo.hpp
    sampler/SamplerMipmapMode.hpp
    sampler/SamplerMipmapMode.cpp
    
    scene/Perspective.hpp
    scene/Perspective.cpp

    shader/GLSLShader.hpp
    shader/GLSLShader.cpp
    shader/Shader.hpp
    shader/Shader.cpp
    shader/ShaderType.hpp
    shader/ShaderType.cpp
    
    task/task.cpp
    
    texture/Texture.hpp
    texture/Texture.cpp
    
    tool/Tool.hpp
    tool/Tool.cpp
    
    undo/Undo.hpp
    undo/Undo.cpp
    
    v/VqApp.hpp
    v/VqApp.cpp
    v/VqEnumerations.hpp
    v/VqEnumerations.cpp
    v/VqEnums.hpp
    v/VqEnums.cpp
    v/VqException.hpp
    v/VqLogging.hpp
    v/VqLogging.cpp
    v/VqStructs.hpp
    v/VqUtils.hpp
    v/VqUtils.cpp
    
    viewer/PresentMode.hpp
    viewer/PresentMode.cpp
    viewer/ViewerCreateInfo.hpp
    
    viz/ViBuffer.hpp
    viz/ViBuffer.cpp
    viz/ViBufferManager.hpp
    viz/ViBufferManager.cpp
    viz/ViBufferObject.hpp
    viz/ViBufferObject.cpp
    viz/ViCleanupManager.hpp
    viz/ViCleanupManager.cpp
    viz/ViCommandPool.hpp
    viz/ViCommandPool.cpp
    viz/ViQueueManager.hpp
    viz/ViQueueManager.cpp
    viz/ViShader.hpp
    viz/ViShader.cpp
    viz/ViShaderManager.hpp
    viz/ViShaderManager.cpp
    viz/ViVisualizer.cpp
    viz/ViVisualizer.hpp
    
    widget/ImGuiDemoWidget.hpp
    widget/ImGuiDemoWidget.cpp
    widget/StackedWidget.hpp
    widget/StackedWidget.cpp
    widget/TextArea.hpp
    widget/TextArea.cpp
    widget/Widget.hpp
    widget/Widget.cpp
    
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
    yqtoolbox
    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
    imgui 
    stb 
    vma
)

LinkTest(${PROJECT_NAME})
