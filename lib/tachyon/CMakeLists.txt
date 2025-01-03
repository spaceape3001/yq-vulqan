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

    source/yt/3D/Camera3.cpp
    source/yt/3D/Light3.cpp
    source/yt/3D/Rendered3.cpp
    source/yt/3D/Scene3.cpp
    source/yt/3D/Spatial3.cpp

    source/yt/api/Action.cpp
    source/yt/api/Delegate.cpp

    source/yt/config/build.cpp

    # font/Font.cpp      # Issue/TODO

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

    source/yt/scene/Camera.cpp
    source/yt/scene/Light.cpp
    source/yt/scene/Perspective.cpp
    source/yt/scene/Rendered.cpp
    #source/yt/scene/Rendered2.cpp
    source/yt/scene/Scene.cpp
    #source/yt/scene/Scene2.cpp
    source/yt/scene/Spatial.cpp

    source/yt/sim/Model.cpp

    #source/yt/ui/Editor.cpp
    source/yt/ui/MyImGui.cpp
    #source/yt/ui/Tool.cpp
    source/yt/ui/Undo.cpp
    source/yt/ui/Widget.cpp

    #######################################################
    #   Vulqan
    
    source/yv/vulqan.cpp
    source/yv/VulqanManager.cpp

    # source/yv/VqEnumerations.cpp
    source/yv/VqEnums.cpp
    source/yv/VqLogging.cpp
    source/yv/VqUtils.cpp

    source/yv/ViBuffer.cpp
    source/yv/ViCommandBuffer.cpp
    source/yv/ViCommandBufferVector.cpp
    source/yv/ViCommandPool.cpp
    source/yv/ViContext.cpp
    source/yv/ViData.cpp
    source/yv/ViDevice.cpp
    source/yv/ViFence.cpp
    source/yv/ViFrame.cpp
    source/yv/ViGui.cpp
    source/yv/ViImage.cpp
    source/yv/ViPipeline.cpp
    source/yv/ViPipelineLayout.cpp
    source/yv/ViQueueManager.cpp
    source/yv/ViQueueTasker.cpp
    source/yv/ViRendered.cpp
    source/yv/ViRenderPass.cpp
    source/yv/ViSampler.cpp
    source/yv/ViShader.cpp
    source/yv/ViSurface.cpp
    source/yv/ViSwapchain.cpp
    source/yv/ViTexture.cpp
    source/yv/ViTasker.cpp
    source/yv/ViThread.cpp
    source/yv/ViVisualizer.cpp
    source/yv/Visualizer.cpp
    
    #######################################################
    #   Assets (Yes, the above will use some of these)


    source/ya/commands/AddChildCommand.cpp
    source/ya/commands/AppCommand.cpp
    source/ya/commands/AppDeleteViewerCommand.cpp
    source/ya/commands/CameraCommand.cpp
    source/ya/commands/CameraPitchCommand.cpp
    source/ya/commands/CameraRollCommand.cpp
    source/ya/commands/CameraYawCommand.cpp
    source/ya/commands/ControllerCommand.cpp
    source/ya/commands/ControllerControlCommand.cpp
    source/ya/commands/ControllerDisableCommand.cpp
    source/ya/commands/ControllerEnableCommand.cpp
    source/ya/commands/ControllerListenCommand.cpp
    source/ya/commands/ControllerUncontrolCommand.cpp
    source/ya/commands/ControllerUnlistenCommand.cpp
    source/ya/commands/EmptyCommand.cpp
    source/ya/commands/GLFWCommand.cpp
    source/ya/commands/MouseCaptureCommand.cpp
    source/ya/commands/MouseCommand.cpp
    source/ya/commands/MouseDisableCommand.cpp
    source/ya/commands/MouseHideCommand.cpp
    source/ya/commands/MouseNormalCommand.cpp
    #source/ya/commands/SetParentCommand.cpp
    source/ya/commands/SetSize1.cpp
    source/ya/commands/SetSize2.cpp
    source/ya/commands/SetSize3.cpp
    source/ya/commands/SetSizeX.cpp
    source/ya/commands/SetSizeY.cpp
    source/ya/commands/SetSizeZ.cpp
    source/ya/commands/SpatialCommand.cpp
    source/ya/commands/TachyonCommand.cpp
    source/ya/commands/TachyonDeleteCommand.cpp
    source/ya/commands/TachyonProxyCommand.cpp
    source/ya/commands/TachyonSnoopCommand.cpp
    source/ya/commands/TachyonSubscribeCommand.cpp
    source/ya/commands/TachyonThreadCommand.cpp
    source/ya/commands/TachyonUnsnoopCommand.cpp
    source/ya/commands/TachyonUnsubscribeCommand.cpp
    source/ya/commands/ThreadCommand.cpp
    source/ya/commands/ViewerAspectCommand.cpp
    source/ya/commands/ViewerAttentionCommand.cpp
    source/ya/commands/ViewerCloseCommand.cpp
    source/ya/commands/ViewerCommand.cpp
    source/ya/commands/ViewerCursorCaptureCommand.cpp
    source/ya/commands/ViewerCursorDisableCommand.cpp
    source/ya/commands/ViewerCursorHideCommand.cpp
    source/ya/commands/ViewerCursorNormalCommand.cpp
    source/ya/commands/ViewerFloatCommand.cpp
    source/ya/commands/ViewerFocusCommand.cpp
    source/ya/commands/ViewerHideCommand.cpp
    source/ya/commands/ViewerIconifyCommand.cpp
    source/ya/commands/ViewerMaximizeCommand.cpp
    source/ya/commands/ViewerMoveCommand.cpp
    source/ya/commands/ViewerPauseCommand.cpp
    source/ya/commands/ViewerRestoreCommand.cpp
    source/ya/commands/ViewerResumeCommand.cpp
    source/ya/commands/ViewerShowCommand.cpp
    source/ya/commands/ViewerSizeCommand.cpp
    source/ya/commands/ViewerTitleCommand.cpp
    source/ya/commands/ViewerUnfloatCommand.cpp
    source/ya/commands/WidgetCommand.cpp
    source/ya/commands/WidgetStartupCommand.cpp
    source/ya/commands/WindowAspectCommand.cpp
    source/ya/commands/WindowAttentionCommand.cpp
    source/ya/commands/WindowCommand.cpp
    source/ya/commands/WindowCursorCaptureCommand.cpp
    source/ya/commands/WindowCursorDisableCommand.cpp
    source/ya/commands/WindowCursorHideCommand.cpp
    source/ya/commands/WindowCursorNormalCommand.cpp
    source/ya/commands/WindowDestroyCommand.cpp
    source/ya/commands/WindowFloatCommand.cpp
    source/ya/commands/WindowFocusCommand.cpp
    source/ya/commands/WindowHideCommand.cpp
    source/ya/commands/WindowIconifyCommand.cpp
    source/ya/commands/WindowMaximizeCommand.cpp
    source/ya/commands/WindowMoveCommand.cpp
    source/ya/commands/WindowRestoreCommand.cpp
    source/ya/commands/WindowShowCommand.cpp
    source/ya/commands/WindowSizeCommand.cpp
    source/ya/commands/WindowTitleCommand.cpp
    source/ya/commands/WindowUnfloatCommand.cpp

    source/ya/commands/spatial/MoveBy1.cpp
    source/ya/commands/spatial/MoveBy2.cpp
    source/ya/commands/spatial/MoveBy3.cpp
    source/ya/commands/spatial/MoveByX.cpp
    source/ya/commands/spatial/MoveByY.cpp
    source/ya/commands/spatial/MoveByZ.cpp
    source/ya/commands/spatial/PitchBy.cpp
    source/ya/commands/spatial/RotateBy3.cpp
    source/ya/commands/spatial/RollBy.cpp
    source/ya/commands/spatial/SetOrientation3.cpp
    source/ya/commands/spatial/SetPosition1.cpp
    source/ya/commands/spatial/SetPosition2.cpp
    source/ya/commands/spatial/SetPosition3.cpp
    source/ya/commands/spatial/SetPositionX.cpp
    source/ya/commands/spatial/SetPositionY.cpp
    source/ya/commands/spatial/SetPositionZ.cpp
    source/ya/commands/spatial/SetScale1.cpp
    source/ya/commands/spatial/SetScale2.cpp
    source/ya/commands/spatial/SetScale3.cpp
    source/ya/commands/spatial/SetScaleX.cpp
    source/ya/commands/spatial/SetScaleY.cpp
    source/ya/commands/spatial/SetScaleZ.cpp
    source/ya/commands/spatial/YawBy.cpp

    source/ya/desktops/glfw/CursorGLFW.cpp
    source/ya/desktops/glfw/DesktopGLFW.cpp
    source/ya/desktops/glfw/JoystickGLFW.cpp
    source/ya/desktops/glfw/KeyboardGLFW.cpp
    source/ya/desktops/glfw/MonitorGLFW.cpp
    source/ya/desktops/glfw/MouseGLFW.cpp
    source/ya/desktops/glfw/WindowGLFW.cpp

    source/ya/events/AppEvent.cpp
    source/ya/events/CameraEvent.cpp
    source/ya/events/EmptyEvent.cpp
    source/ya/events/InputEvent.cpp
    #source/ya/events/JoystickAxisEvent.cpp
    #source/ya/events/JoystickConnectEvent.cpp
    #source/ya/events/JoystickDisconnectEvent.cpp
    #source/ya/events/JoystickEvent.cpp
    #source/ya/events/JoystickHatEvent.cpp
    #source/ya/events/JoystickPressEvent.cpp
    #source/ya/events/JoystickReleaseEvent.cpp
    source/ya/events/KeyboardEvent.cpp
    source/ya/events/KeyCharacterEvent.cpp
    source/ya/events/KeyPressEvent.cpp
    source/ya/events/KeyReleaseEvent.cpp
    source/ya/events/KeyRepeatEvent.cpp
    #source/ya/events/MonitorConnectEvent.cpp
    #source/ya/events/MonitorDisconnectEvent.cpp
    #source/ya/events/MonitorEvent.cpp
    source/ya/events/MouseCaptureEvent.cpp
    source/ya/events/MouseDisableEvent.cpp
    source/ya/events/MouseDropEvent.cpp
    source/ya/events/MouseEnterEvent.cpp
    source/ya/events/MouseEvent.cpp
    source/ya/events/MouseHideEvent.cpp
    source/ya/events/MouseLeaveEvent.cpp
    source/ya/events/MouseMoveEvent.cpp
    source/ya/events/MouseNormalEvent.cpp
    source/ya/events/MousePressEvent.cpp
    source/ya/events/MouseReleaseEvent.cpp
    source/ya/events/MouseScrollEvent.cpp
    source/ya/events/TachyonEvent.cpp
    source/ya/events/ThreadEvent.cpp
    source/ya/events/ThreadAddTachyonEvent.cpp
    source/ya/events/ViewerCloseEvent.cpp
    source/ya/events/ViewerDestroyEvent.cpp
    source/ya/events/ViewerEvent.cpp
    source/ya/events/ViewerPauseEvent.cpp
    source/ya/events/ViewerResumeEvent.cpp
    source/ya/events/ViewerTickEvent.cpp
    source/ya/events/VulqanEvent.cpp
    source/ya/events/WidgetEvent.cpp
    source/ya/events/WindowAspectEvent.cpp
    source/ya/events/WindowCursorCaptureEvent.cpp
    source/ya/events/WindowCursorDisableEvent.cpp
    source/ya/events/WindowCursorHideEvent.cpp
    source/ya/events/WindowCursorNormalEvent.cpp
    source/ya/events/WindowDefocusEvent.cpp
    source/ya/events/WindowDestroyEvent.cpp
    source/ya/events/WindowEvent.cpp
    source/ya/events/WindowFocusEvent.cpp
    source/ya/events/WindowFrameBufferResizeEvent.cpp
    source/ya/events/WindowHideEvent.cpp
    source/ya/events/WindowIconifyEvent.cpp
    source/ya/events/WindowMaximizeEvent.cpp
    source/ya/events/WindowMoveEvent.cpp
    source/ya/events/WindowResizeEvent.cpp
    source/ya/events/WindowRestoreEvent.cpp
    source/ya/events/WindowScaleEvent.cpp
    source/ya/events/WindowShowEvent.cpp
    source/ya/events/WindowTitleEvent.cpp
    
    source/ya/interfaces/IPosition1.cpp
    source/ya/interfaces/IPosition2.cpp
    source/ya/interfaces/IPosition3.cpp

    source/ya/messages/EmptyMessage.cpp

    source/ya/posts/AnyPost.cpp
    source/ya/posts/EmptyPost.cpp
    source/ya/posts/StringPost.cpp

    source/ya/proxies/PPosition1.cpp
    source/ya/proxies/PPosition2.cpp
    source/ya/proxies/PPosition3.cpp

    source/ya/replies/AnyReply.cpp
    source/ya/replies/AppReply.cpp
    source/ya/replies/CameraReply.cpp
    source/ya/replies/EmptyReply.cpp
    source/ya/replies/StringReply.cpp
    source/ya/replies/TachyonReply.cpp
    source/ya/replies/ViewerCloseReply.cpp
    source/ya/replies/ViewerReply.cpp
    source/ya/replies/ViewerWidgetReply.cpp
    source/ya/replies/WindowReply.cpp
    
    source/ya/requests/AppRequest.cpp
    source/ya/requests/CameraRequest.cpp
    source/ya/requests/EmptyRequest.cpp
    source/ya/requests/TachyonRequest.cpp
    source/ya/requests/ViewerCloseRequest.cpp
    source/ya/requests/ViewerRequest.cpp
    #source/ya/requests/ViewerWidgetRequest.cpp
    source/ya/requests/WindowCloseRequest.cpp
    source/ya/requests/WindowRefreshRequest.cpp
    source/ya/requests/WindowRequest.cpp

    source/ya/spatials/SimpleSpatial3.cpp

    source/ya/triggers/AndTrigger.cpp
    source/ya/triggers/KeyPressTrigger.cpp
    source/ya/triggers/NandTrigger.cpp
    source/ya/triggers/NorTrigger.cpp
    source/ya/triggers/NotTrigger.cpp
    source/ya/triggers/OrTrigger.cpp
    source/ya/triggers/PostTrigger.cpp
    
    source/ya/utils/LoggerBox.cpp
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
    ${VULQAN_API_DIR}
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/source
    ${CMAKE_CURRENT_LIST_DIR}/../../api
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
