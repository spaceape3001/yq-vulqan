################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)

#   SUPERSCRIPTS ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ʰ ᵖ ⁿ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED

    #glfw/GLFWManager.cpp
    
    MyImGui.cpp
    
    vulqan.cpp

    3D/Camera3.cpp
    3D/Light3.cpp
    3D/Rendered3.cpp
    3D/Scene3.cpp
    3D/Spatial3.cpp

    api/Controller.cpp
    #api/Context.hpp
    #api/Editor.cpp
    api/Frame.cpp
    api/InterfaceInfo.cpp
    api/Manager.cpp
    api/Model.cpp
    api/Proxy.cpp
    api/Raster.cpp
    api/Tachyon.cpp
    api/Thread.cpp
    #api/Tool.cpp
    api/TypedID.cpp
    api/Widget.cpp

    app/Application.cpp
    app/AppThread.cpp
    app/TaskThread.cpp
    app/Viewer.cpp
    app/ViewerThread.cpp

    cameras/NullCamera.cpp
    cameras/SpaceCamera.cpp
    cameras/TargetCamera.cpp

    commands/AddChildCommand.cpp
    commands/AppCommand.cpp
    commands/AppDeleteViewerCommand.cpp
    commands/CameraCommand.cpp
    commands/CameraPitchCommand.cpp
    commands/CameraRollCommand.cpp
    commands/CameraYawCommand.cpp
    commands/ControllerCommand.cpp
    commands/ControllerControlCommand.cpp
    commands/ControllerDisableCommand.cpp
    commands/ControllerEnableCommand.cpp
    commands/ControllerListenCommand.cpp
    commands/ControllerUncontrolCommand.cpp
    commands/ControllerUnlistenCommand.cpp
    commands/EmptyCommand.cpp
    commands/GLFWCommand.cpp
    commands/MouseCaptureCommand.cpp
    commands/MouseCommand.cpp
    commands/MouseDisableCommand.cpp
    commands/MouseHideCommand.cpp
    commands/MouseNormalCommand.cpp
    #commands/SetParentCommand.cpp
    commands/SetSize1.cpp
    commands/SetSize2.cpp
    commands/SetSize3.cpp
    commands/SetSizeX.cpp
    commands/SetSizeY.cpp
    commands/SetSizeZ.cpp
    commands/SpatialCommand.cpp
    commands/TachyonCommand.cpp
    commands/TachyonDeleteCommand.cpp
    commands/TachyonProxyCommand.cpp
    commands/TachyonSnoopCommand.cpp
    commands/TachyonSubscribeCommand.cpp
    commands/TachyonThreadCommand.cpp
    commands/TachyonUnsnoopCommand.cpp
    commands/TachyonUnsubscribeCommand.cpp
    commands/ThreadCommand.cpp
    commands/ViewerAspectCommand.cpp
    commands/ViewerAttentionCommand.cpp
    commands/ViewerCloseCommand.cpp
    commands/ViewerCommand.cpp
    commands/ViewerCursorCaptureCommand.cpp
    commands/ViewerCursorDisableCommand.cpp
    commands/ViewerCursorHideCommand.cpp
    commands/ViewerCursorNormalCommand.cpp
    commands/ViewerFloatCommand.cpp
    commands/ViewerFocusCommand.cpp
    commands/ViewerHideCommand.cpp
    commands/ViewerIconifyCommand.cpp
    commands/ViewerMaximizeCommand.cpp
    commands/ViewerMoveCommand.cpp
    commands/ViewerPauseCommand.cpp
    commands/ViewerRestoreCommand.cpp
    commands/ViewerResumeCommand.cpp
    commands/ViewerShowCommand.cpp
    commands/ViewerSizeCommand.cpp
    commands/ViewerTitleCommand.cpp
    commands/ViewerUnfloatCommand.cpp
    commands/WidgetCommand.cpp
    commands/WidgetStartupCommand.cpp
    commands/WindowAspectCommand.cpp
    commands/WindowAttentionCommand.cpp
    commands/WindowCommand.cpp
    commands/WindowCursorCaptureCommand.cpp
    commands/WindowCursorDisableCommand.cpp
    commands/WindowCursorHideCommand.cpp
    commands/WindowCursorNormalCommand.cpp
    commands/WindowDestroyCommand.cpp
    commands/WindowFloatCommand.cpp
    commands/WindowFocusCommand.cpp
    commands/WindowHideCommand.cpp
    commands/WindowIconifyCommand.cpp
    commands/WindowMaximizeCommand.cpp
    commands/WindowMoveCommand.cpp
    commands/WindowRestoreCommand.cpp
    commands/WindowShowCommand.cpp
    commands/WindowSizeCommand.cpp
    commands/WindowTitleCommand.cpp
    commands/WindowUnfloatCommand.cpp

    commands/spatial/MoveBy1.cpp
    commands/spatial/MoveBy2.cpp
    commands/spatial/MoveBy3.cpp
    commands/spatial/MoveByX.cpp
    commands/spatial/MoveByY.cpp
    commands/spatial/MoveByZ.cpp
    commands/spatial/PitchBy.cpp
    commands/spatial/RotateBy3.cpp
    commands/spatial/RollBy.cpp
    commands/spatial/SetOrientation3.cpp
    commands/spatial/SetPosition1.cpp
    commands/spatial/SetPosition2.cpp
    commands/spatial/SetPosition3.cpp
    commands/spatial/SetPositionX.cpp
    commands/spatial/SetPositionY.cpp
    commands/spatial/SetPositionZ.cpp
    commands/spatial/SetScale1.cpp
    commands/spatial/SetScale2.cpp
    commands/spatial/SetScale3.cpp
    commands/spatial/SetScaleX.cpp
    commands/spatial/SetScaleY.cpp
    commands/spatial/SetScaleZ.cpp
    commands/spatial/YawBy.cpp

    enum/enum.cpp

    events/AppEvent.cpp
    events/CameraEvent.cpp
    events/EmptyEvent.cpp
    events/InputEvent.cpp
    #events/JoystickAxisEvent.cpp
    #events/JoystickConnectEvent.cpp
    #events/JoystickDisconnectEvent.cpp
    #events/JoystickEvent.cpp
    #events/JoystickHatEvent.cpp
    #events/JoystickPressEvent.cpp
    #events/JoystickReleaseEvent.cpp
    events/KeyboardEvent.cpp
    events/KeyCharacterEvent.cpp
    events/KeyPressEvent.cpp
    events/KeyReleaseEvent.cpp
    events/KeyRepeatEvent.cpp
    #events/MonitorConnectEvent.cpp
    #events/MonitorDisconnectEvent.cpp
    #events/MonitorEvent.cpp
    events/MouseCaptureEvent.cpp
    events/MouseDisableEvent.cpp
    events/MouseDropEvent.cpp
    events/MouseEnterEvent.cpp
    events/MouseEvent.cpp
    events/MouseHideEvent.cpp
    events/MouseLeaveEvent.cpp
    events/MouseMoveEvent.cpp
    events/MouseNormalEvent.cpp
    events/MousePressEvent.cpp
    events/MouseReleaseEvent.cpp
    events/MouseScrollEvent.cpp
    events/TachyonEvent.cpp
    events/ThreadEvent.cpp
    events/ThreadAddTachyonEvent.cpp
    events/ViewerCloseEvent.cpp
    events/ViewerDestroyEvent.cpp
    events/ViewerEvent.cpp
    events/ViewerPauseEvent.cpp
    events/ViewerResumeEvent.cpp
    events/ViewerTickEvent.cpp
    events/VulqanEvent.cpp
    events/WidgetEvent.cpp
    events/WindowAspectEvent.cpp
    events/WindowCursorCaptureEvent.cpp
    events/WindowCursorDisableEvent.cpp
    events/WindowCursorHideEvent.cpp
    events/WindowCursorNormalEvent.cpp
    events/WindowDefocusEvent.cpp
    events/WindowDestroyEvent.cpp
    events/WindowEvent.cpp
    events/WindowFocusEvent.cpp
    events/WindowFrameBufferResizeEvent.cpp
    events/WindowHideEvent.cpp
    events/WindowIconifyEvent.cpp
    events/WindowMaximizeEvent.cpp
    events/WindowMoveEvent.cpp
    events/WindowResizeEvent.cpp
    events/WindowRestoreEvent.cpp
    events/WindowScaleEvent.cpp
    events/WindowShowEvent.cpp
    events/WindowTitleEvent.cpp
    
    # font/Font.cpp      # Issue/TODO
    
    gfx/Buffer.cpp
    gfx/Pipeline.cpp
    gfx/PipelineUtils.cpp
    gfx/RenderPass.cpp
    gfx/Sampler.cpp
    gfx/Shader.cpp
    gfx/Texture.cpp

    glfw/CursorGLFW.cpp
    glfw/DesktopGLFW.cpp
    glfw/JoystickGLFW.cpp
    glfw/KeyboardGLFW.cpp
    glfw/MonitorGLFW.cpp
    glfw/MouseGLFW.cpp
    glfw/WindowGLFW.cpp

    interfaces/IPosition1.cpp
    interfaces/IPosition2.cpp
    interfaces/IPosition3.cpp

    io/GLSLShader.cpp
    io/SamplerInfoFile.cpp
    io/STBImage.cpp

    #manipulator/Manipulator.cpp
    
    
    #models/models.cpp

    proxies/PPosition1.cpp
    proxies/PPosition2.cpp
    proxies/PPosition3.cpp

    renders/ImageQuad.cpp
    renders/Quadrilateral.cpp
    renders/Tetrahedron.cpp
    renders/Triangle.cpp

    replies/AnyReply.cpp
    replies/AppReply.cpp
    replies/CameraReply.cpp
    replies/EmptyReply.cpp
    replies/StringReply.cpp
    replies/TachyonReply.cpp
    replies/ViewerCloseReply.cpp
    replies/ViewerReply.cpp
    replies/ViewerWidgetReply.cpp
    replies/WindowReply.cpp
    
    requests/AppRequest.cpp
    requests/CameraRequest.cpp
    requests/EmptyRequest.cpp
    requests/TachyonRequest.cpp
    requests/ViewerCloseRequest.cpp
    requests/ViewerRequest.cpp
    #requests/ViewerWidgetRequest.cpp
    requests/WindowCloseRequest.cpp
    requests/WindowRefreshRequest.cpp
    requests/WindowRequest.cpp

    scene/Camera.cpp
    scene/Light.cpp
    scene/Perspective.cpp
    scene/Rendered.cpp
    #scene/Rendered2.cpp
    scene/Scene.cpp
    #scene/Scene2.cpp
    scene/Spatial.cpp

    spatials/SimpleSpatial3.cpp
    
    #task/Task.cpp
    #task/TaskEngine.cpp
    #tools/tools.cpp
    
    
    util/LoggerBox.cpp


    # v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    v/VqUtils.cpp
    v/Vulqan.cpp
    
    viz/ViBuffer.cpp
    viz/ViCommandBuffer.cpp
    viz/ViCommandBufferVector.cpp
    viz/ViCommandPool.cpp
    viz/ViContext.cpp
    viz/ViData.cpp
    viz/ViDevice.cpp
    viz/ViFence.cpp
    viz/ViFrame.cpp
    viz/ViGui.cpp
    viz/ViImage.cpp
    viz/ViPipeline.cpp
    viz/ViPipelineLayout.cpp
    viz/ViQueueManager.cpp
    viz/ViQueueTasker.cpp
    viz/ViRendered.cpp
    viz/ViRenderPass.cpp
    viz/ViSampler.cpp
    viz/ViShader.cpp
    viz/ViSurface.cpp
    viz/ViSwapchain.cpp
    viz/ViTexture.cpp
    viz/ViTasker.cpp
    viz/ViThread.cpp
    viz/ViVisualizer.cpp
    viz/Visualizer.cpp
    
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
    ../../../lib/tachyon/public
    ${VULQAN_API_DIR}
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_tachyon2
)

LinkTest(${PROJECT_NAME})

