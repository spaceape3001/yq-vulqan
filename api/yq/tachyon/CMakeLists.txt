################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)

#   SUPERSCRIPTS ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ⁿ

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    strings.cpp

    #glfw/GLFWManager.cpp
    
    MyImGui.cpp
    
    vulqan.cpp

    api/Application.cpp
    api/AppThread.cpp
    api/Buffer.cpp
    api/Camera.cpp
    api/Command.cpp
    api/Controller.cpp
    api/Cursor.cpp
    #api/Context.hpp
    api/Desktop.cpp
    #api/Editor.cpp
    api/Event.cpp
    api/Frame.cpp
    api/InterfaceInfo.cpp
    api/Joystick.cpp
    api/Keyboard.cpp
    api/Light.cpp
    api/Manager.cpp
    api/Message.cpp
    api/Model.cpp
    api/Monitor.cpp
    api/Mouse.cpp
    api/Perspective.cpp
    api/Pipeline.cpp
    api/PipelineUtils.cpp
    api/Post.cpp
    api/Proxy.cpp
    api/Raster.cpp
    #api/Render².cpp
    api/Render³.cpp
    api/Rendered.cpp
    api/RenderPass.cpp
    api/Reply.cpp
    api/Request.cpp
    api/Sampler.cpp
    api/Shader.cpp
    api/Tachyon.cpp
    api/TaskThread.cpp
    api/Texture.cpp
    api/Thread.cpp
    #api/Tool.cpp
    api/Trigger.cpp
    api/TypedID.cpp
    api/Undo.cpp
    api/VideoMode.cpp
    api/Viewer.cpp
    api/ViewerThread.cpp
    api/Widget.cpp
    api/Window.cpp

    cameras/NullCamera.cpp
    cameras/SpaceCamera.cpp
    cameras/TargetCamera.cpp

    commands/AddChildCommand.cpp
    commands/AdjustPosition1D.cpp
    commands/AdjustPosition1I.cpp
    commands/AdjustPosition1M.cpp
    commands/AdjustPosition2D.cpp
    commands/AdjustPosition2I.cpp
    commands/AdjustPosition2M.cpp
    commands/AdjustPosition3D.cpp
    commands/AdjustPosition3I.cpp
    commands/AdjustPosition3M.cpp
    commands/AdjustPosition4D.cpp
    commands/AdjustPosition4I.cpp
    commands/AdjustPosition4M.cpp
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
    commands/SetPosition1D.cpp
    commands/SetPosition1I.cpp
    commands/SetPosition1M.cpp
    commands/SetPosition2D.cpp
    commands/SetPosition2I.cpp
    commands/SetPosition2M.cpp
    commands/SetPosition3D.cpp
    commands/SetPosition3I.cpp
    commands/SetPosition3M.cpp
    commands/SetPosition4D.cpp
    commands/SetPosition4I.cpp
    commands/SetPosition4M.cpp
    commands/SetSize2I.cpp
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
    
    config/build.cpp
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    events/AppEvent.cpp
    events/CameraEvent.cpp
    events/EmptyEvent.cpp
    events/InputEvent.cpp
    events/JoystickAxisEvent.cpp
    events/JoystickConnectEvent.cpp
    events/JoystickDisconnectEvent.cpp
    events/JoystickEvent.cpp
    events/JoystickHatEvent.cpp
    events/JoystickPressEvent.cpp
    events/JoystickReleaseEvent.cpp
    events/KeyboardEvent.cpp
    events/KeyCharacterEvent.cpp
    events/KeyPressEvent.cpp
    events/KeyReleaseEvent.cpp
    events/KeyRepeatEvent.cpp
    events/MonitorConnectEvent.cpp
    events/MonitorDisconnectEvent.cpp
    events/MonitorEvent.cpp
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
    
    glfw/CursorGLFW.cpp
    glfw/DesktopGLFW.cpp
    glfw/JoystickGLFW.cpp
    glfw/KeyboardGLFW.cpp
    glfw/MonitorGLFW.cpp
    glfw/MouseGLFW.cpp
    glfw/WindowGLFW.cpp

    interfaces/IPosition1D.cpp
    interfaces/IPosition1I.cpp
    interfaces/IPosition1M.cpp
    interfaces/IPosition2D.cpp
    interfaces/IPosition2I.cpp
    interfaces/IPosition2M.cpp
    interfaces/IPosition3D.cpp
    interfaces/IPosition3I.cpp
    interfaces/IPosition3M.cpp
    interfaces/IPosition4D.cpp
    interfaces/IPosition4I.cpp
    interfaces/IPosition4M.cpp

    io/GLSLShader.cpp
    io/SamplerInfoFile.cpp
    io/STBImage.cpp

    #manipulator/Manipulator.cpp
    
    messages/EmptyMessage.cpp
    
    #models/models.cpp

    posts/AnyPost.cpp
    posts/EmptyPost.cpp
    posts/StringPost.cpp

    proxies/PPosition1D.cpp
    proxies/PPosition1I.cpp
    proxies/PPosition1M.cpp
    proxies/PPosition2D.cpp
    proxies/PPosition2I.cpp
    proxies/PPosition2M.cpp
    proxies/PPosition3D.cpp
    proxies/PPosition3I.cpp
    proxies/PPosition3M.cpp
    proxies/PPosition4D.cpp
    proxies/PPosition4I.cpp
    proxies/PPosition4M.cpp

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
    
    #task/Task.cpp
    #task/TaskEngine.cpp
    #tools/tools.cpp
    
    triggers/AndTrigger.cpp
    triggers/KeyPressTrigger.cpp
    triggers/NandTrigger.cpp
    triggers/NorTrigger.cpp
    triggers/NotTrigger.cpp
    triggers/OrTrigger.cpp
    triggers/PostTrigger.cpp
    
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

