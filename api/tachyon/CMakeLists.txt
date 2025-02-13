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
    
    #######################################################
    #   Core First
    
    yt/enums.cpp
    yt/strings.cpp

    yt/3D/3D.cpp
    yt/3D/Camera3.cpp
    yt/3D/Light3.cpp
    yt/3D/Rendered3.cpp
    yt/3D/Scene3.cpp
    yt/3D/Spatial3.cpp

    yt/api/Action.cpp
    yt/api/Controller.cpp
    yt/api/Delegate.cpp
    yt/api/Frame.cpp
    yt/api/InterfaceInfo.cpp
    yt/api/Manager.cpp
    yt/api/Proxy.cpp
    yt/api/Tachyon.cpp
    yt/api/Thread.cpp
    yt/api/TypedID.cpp

    yt/app/Application.cpp
    yt/app/Viewer.cpp

    yt/config/build.cpp

    # font/Font.cpp      # Issue/TODO

    yt/gfx/Buffer.cpp
    yt/gfx/Pipeline.cpp
    yt/gfx/PipelineUtils.cpp
    yt/gfx/Raster.cpp
    yt/gfx/RenderPass.cpp
    yt/gfx/Sampler.cpp
    yt/gfx/Shader.cpp
    yt/gfx/Texture.cpp

    yt/io/GLSLShader.cpp
    yt/io/SamplerInfoFile.cpp
    yt/io/STBImage.cpp

    yt/msg/Command.cpp
    yt/msg/Event.cpp
    yt/msg/Message.cpp
    yt/msg/Post.cpp
    yt/msg/Reply.cpp
    yt/msg/Request.cpp
    yt/msg/Trigger.cpp
    
    yt/os/Cursor.cpp
    yt/os/Desktop.cpp
    yt/os/Gamepad.cpp
    yt/os/GraphicsCard.cpp
    yt/os/Joystick.cpp
    yt/os/Keyboard.cpp
    yt/os/KeyCode.cpp
    yt/os/ModifierKey.cpp
    yt/os/Monitor.cpp
    yt/os/Mouse.cpp
    yt/os/VideoMode.cpp
    yt/os/Window.cpp

    yt/scene/Camera.cpp
    yt/scene/Light.cpp
    yt/scene/Perspective.cpp
    yt/scene/Rendered.cpp
    #yt/scene/Rendered2.cpp
    yt/scene/Scene.cpp
    #yt/scene/Scene2.cpp

    yt/sim/Model.cpp
    yt/sim/N.cpp
    yt/sim/Spatial.cpp

    # possibly being removed.... TBD (IIRC, tachyon replaced its usefulness)
    #sim/Task.cpp
    #sim/TaskEngine.cpp

    yt/ui/Control.cpp
    #yt/ui/Editor.cpp
    yt/ui/Mini.cpp
    yt/ui/MyImGui.cpp
    yt/ui/Panel.cpp
    #yt/ui/Tool.cpp
    yt/ui/Undo.cpp
    yt/ui/Widget.cpp

    #######################################################
    #   Vulqan
    
    yv/vulqan.cpp
    yv/VulqanGPU.cpp
    yv/VulqanManager.cpp

    # yv/VqEnumerations.cpp
    yv/VqEnums.cpp
    yv/VqLogging.cpp
    yv/VqUtils.cpp

    yv/ViBuffer.cpp
    yv/ViCommandBuffer.cpp
    yv/ViCommandBufferVector.cpp
    yv/ViCommandPool.cpp
    yv/ViContext.cpp
    yv/ViData.cpp
    yv/ViDevice.cpp
    yv/ViFence.cpp
    yv/ViFrame.cpp
    yv/ViGui.cpp
    yv/ViImage.cpp
    yv/ViPipeline.cpp
    yv/ViPipelineLayout.cpp
    yv/ViQueueManager.cpp
    yv/ViQueueTasker.cpp
    yv/ViRendered.cpp
    yv/ViRenderPass.cpp
    yv/ViSampler.cpp
    yv/ViShader.cpp
    yv/ViSurface.cpp
    yv/ViSwapchain.cpp
    yv/ViTexture.cpp
    yv/ViTasker.cpp
    yv/ViThread.cpp
    yv/ViVisualizer.cpp
    yv/Visualizer.cpp
    
    #######################################################
    #   Assets (Yes, the above will use some of these)

    ya/accessors/StringFunction.cpp
    ya/accessors/StringValue.cpp

    ya/aspects/AMaxSize1.cpp
    ya/aspects/AMaxSize2.cpp
    ya/aspects/AMaxSize3.cpp
    ya/aspects/AMinSize1.cpp
    ya/aspects/AMinSize2.cpp
    ya/aspects/AMinSize3.cpp
    ya/aspects/AOrientation3.cpp
    ya/aspects/APosition1.cpp
    ya/aspects/APosition2.cpp
    ya/aspects/APosition3.cpp
    ya/aspects/AScale1.cpp
    ya/aspects/AScale2.cpp
    ya/aspects/AScale3.cpp
    ya/aspects/ASize1.cpp
    ya/aspects/ASize2.cpp
    ya/aspects/ASize3.cpp

    ya/cameras/NullCamera.cpp
    ya/cameras/SpaceCamera.cpp
    ya/cameras/TargetCamera.cpp

    ya/commands/AddChildCommand.cpp
    ya/commands/AppCommand.cpp
    ya/commands/AppDeleteViewerCommand.cpp
    ya/commands/CameraCommand.cpp
    ya/commands/ControllerCommand.cpp
    ya/commands/EmptyCommand.cpp
    ya/commands/GamepadCommand.cpp
    ya/commands/GLFWCommand.cpp
    ya/commands/JoystickCommand.cpp
    ya/commands/LightCommand.cpp
    ya/commands/MouseCaptureCommand.cpp
    ya/commands/MouseCommand.cpp
    ya/commands/MouseDisableCommand.cpp
    ya/commands/MouseHideCommand.cpp
    ya/commands/MouseNormalCommand.cpp
    #ya/commands/SetParentCommand.cpp
    ya/commands/SimCommand.cpp
    ya/commands/SpatialCommand.cpp
    ya/commands/TachyonCommand.cpp
    ya/commands/ThreadCommand.cpp
    ya/commands/UICommand.cpp
    ya/commands/ViewerAspectCommand.cpp
    ya/commands/ViewerCommand.cpp
    ya/commands/ViewerCursorCaptureCommand.cpp
    ya/commands/ViewerCursorDisableCommand.cpp
    ya/commands/ViewerCursorHideCommand.cpp
    ya/commands/ViewerCursorNormalCommand.cpp
    ya/commands/ViewerTitleCommand.cpp
    ya/commands/WidgetCommand.cpp
    ya/commands/WindowAspectCommand.cpp
    ya/commands/WindowCommand.cpp
    ya/commands/WindowCursorCaptureCommand.cpp
    ya/commands/WindowCursorDisableCommand.cpp
    ya/commands/WindowCursorHideCommand.cpp
    ya/commands/WindowCursorNormalCommand.cpp
    ya/commands/WindowDestroyCommand.cpp
    ya/commands/WindowTitleCommand.cpp
    
    ya/commands/camera/CameraSetScreen.cpp

    ya/commands/controller/ControlCommand.cpp
    ya/commands/controller/DisableCommand.cpp
    ya/commands/controller/EnableCommand.cpp
    ya/commands/controller/ListenCommand.cpp
    ya/commands/controller/UncontrolCommand.cpp
    ya/commands/controller/UnlistenCommand.cpp

    ya/commands/gamepad/GamepadZeroCommand.cpp

    ya/commands/joystick/JoystickZeroCommand.cpp

    ya/commands/sim/ResumeCommand.cpp
    ya/commands/sim/PauseCommand.cpp

    ya/commands/spatial/AddMaxSize1.cpp
    ya/commands/spatial/AddMaxSize2.cpp
    ya/commands/spatial/AddMaxSize3.cpp
    ya/commands/spatial/AddMaxSizeX.cpp
    ya/commands/spatial/AddMaxSizeY.cpp
    ya/commands/spatial/AddMaxSizeZ.cpp
    ya/commands/spatial/AddMinSize1.cpp
    ya/commands/spatial/AddMinSize2.cpp
    ya/commands/spatial/AddMinSize3.cpp
    ya/commands/spatial/AddMinSizeX.cpp
    ya/commands/spatial/AddMinSizeY.cpp
    ya/commands/spatial/AddMinSizeZ.cpp
    ya/commands/spatial/AddPosition1.cpp
    ya/commands/spatial/AddPosition2.cpp
    ya/commands/spatial/AddPosition3.cpp
    ya/commands/spatial/AddPositionX.cpp
    ya/commands/spatial/AddPositionY.cpp
    ya/commands/spatial/AddPositionZ.cpp
    ya/commands/spatial/AddScale1.cpp
    ya/commands/spatial/AddScale2.cpp
    ya/commands/spatial/AddScale3.cpp
    ya/commands/spatial/AddScaleX.cpp
    ya/commands/spatial/AddScaleY.cpp
    ya/commands/spatial/AddScaleZ.cpp
    ya/commands/spatial/AddSize1.cpp
    ya/commands/spatial/AddSize2.cpp
    ya/commands/spatial/AddSize3.cpp
    ya/commands/spatial/AddSizeX.cpp
    ya/commands/spatial/AddSizeY.cpp
    ya/commands/spatial/AddSizeZ.cpp
    ya/commands/spatial/MoveBy1.cpp
    ya/commands/spatial/MoveBy2.cpp
    ya/commands/spatial/MoveBy3.cpp
    ya/commands/spatial/MoveByX.cpp
    ya/commands/spatial/MoveByY.cpp
    ya/commands/spatial/MoveByZ.cpp
    ya/commands/spatial/MultiplyMaxSize.cpp
    ya/commands/spatial/MultiplyMaxSize1.cpp
    ya/commands/spatial/MultiplyMaxSize2.cpp
    ya/commands/spatial/MultiplyMaxSize3.cpp
    ya/commands/spatial/MultiplyMaxSizeX.cpp
    ya/commands/spatial/MultiplyMaxSizeY.cpp
    ya/commands/spatial/MultiplyMaxSizeZ.cpp
    ya/commands/spatial/MultiplyMinSize.cpp
    ya/commands/spatial/MultiplyMinSize1.cpp
    ya/commands/spatial/MultiplyMinSize2.cpp
    ya/commands/spatial/MultiplyMinSize3.cpp
    ya/commands/spatial/MultiplyMinSizeX.cpp
    ya/commands/spatial/MultiplyMinSizeY.cpp
    ya/commands/spatial/MultiplyMinSizeZ.cpp
    ya/commands/spatial/MultiplyPosition.cpp
    ya/commands/spatial/MultiplyPosition1.cpp
    ya/commands/spatial/MultiplyPosition2.cpp
    ya/commands/spatial/MultiplyPosition3.cpp
    ya/commands/spatial/MultiplyPositionX.cpp
    ya/commands/spatial/MultiplyPositionY.cpp
    ya/commands/spatial/MultiplyPositionZ.cpp
    ya/commands/spatial/MultiplyScale.cpp
    ya/commands/spatial/MultiplyScale1.cpp
    ya/commands/spatial/MultiplyScale2.cpp
    ya/commands/spatial/MultiplyScale3.cpp
    ya/commands/spatial/MultiplyScaleX.cpp
    ya/commands/spatial/MultiplyScaleY.cpp
    ya/commands/spatial/MultiplyScaleZ.cpp
    ya/commands/spatial/MultiplySize.cpp
    ya/commands/spatial/MultiplySize1.cpp
    ya/commands/spatial/MultiplySize2.cpp
    ya/commands/spatial/MultiplySize3.cpp
    ya/commands/spatial/MultiplySizeX.cpp
    ya/commands/spatial/MultiplySizeY.cpp
    ya/commands/spatial/MultiplySizeZ.cpp
    ya/commands/spatial/PitchBy.cpp
    ya/commands/spatial/RotateBy3.cpp
    ya/commands/spatial/RollBy.cpp
    ya/commands/spatial/SetHeading.cpp
    ya/commands/spatial/SetMaxSize1.cpp
    ya/commands/spatial/SetMaxSize2.cpp
    ya/commands/spatial/SetMaxSize3.cpp
    ya/commands/spatial/SetMaxSizeX.cpp
    ya/commands/spatial/SetMaxSizeY.cpp
    ya/commands/spatial/SetMaxSizeZ.cpp
    ya/commands/spatial/SetMinSize1.cpp
    ya/commands/spatial/SetMinSize2.cpp
    ya/commands/spatial/SetMinSize3.cpp
    ya/commands/spatial/SetMinSizeX.cpp
    ya/commands/spatial/SetMinSizeY.cpp
    ya/commands/spatial/SetMinSizeZ.cpp
    ya/commands/spatial/SetOrientation3.cpp
    ya/commands/spatial/SetPitch.cpp
    ya/commands/spatial/SetPosition1.cpp
    ya/commands/spatial/SetPosition2.cpp
    ya/commands/spatial/SetPosition3.cpp
    ya/commands/spatial/SetPositionX.cpp
    ya/commands/spatial/SetPositionY.cpp
    ya/commands/spatial/SetPositionZ.cpp
    ya/commands/spatial/SetRoll.cpp
    ya/commands/spatial/SetScale1.cpp
    ya/commands/spatial/SetScale2.cpp
    ya/commands/spatial/SetScale3.cpp
    ya/commands/spatial/SetScaleX.cpp
    ya/commands/spatial/SetScaleY.cpp
    ya/commands/spatial/SetScaleZ.cpp
    ya/commands/spatial/SetSize1.cpp
    ya/commands/spatial/SetSize2.cpp
    ya/commands/spatial/SetSize3.cpp
    ya/commands/spatial/SetSizeX.cpp
    ya/commands/spatial/SetSizeY.cpp
    ya/commands/spatial/SetSizeZ.cpp
    ya/commands/spatial/YawBy.cpp
    
    ya/commands/tachyon/DestroyCommand.cpp
    ya/commands/tachyon/RethreadCommand.cpp
    ya/commands/tachyon/SnoopCommand.cpp
    ya/commands/tachyon/SubscribeCommand.cpp
    ya/commands/tachyon/UnsnoopCommand.cpp
    ya/commands/tachyon/UnsubscribeCommand.cpp
    
    ya/commands/ui/AttentionCommand.cpp
    ya/commands/ui/CloseCommand.cpp
    ya/commands/ui/FloatCommand.cpp
    ya/commands/ui/FocusCommand.cpp
    ya/commands/ui/HideCommand.cpp
    ya/commands/ui/IconifyCommand.cpp
    ya/commands/ui/MaximizeCommand.cpp
    ya/commands/ui/RestoreCommand.cpp
    ya/commands/ui/ShowCommand.cpp
    ya/commands/ui/StartupCommand.cpp
    ya/commands/ui/UnfloatCommand.cpp

    #ya/commands/viewer/SetWidgetCommand.cpp
    
    ya/commands/widget/SetViewer.cpp


    ya/controllers/Space3Controller.cpp

    ya/controls/Orientation3Control.cpp

    ya/desktops/glfw/CursorGLFW.cpp
    ya/desktops/glfw/DesktopGLFW.cpp
    ya/desktops/glfw/GamepadGLFW.cpp
    ya/desktops/glfw/JoystickGLFW.cpp
    ya/desktops/glfw/KeyboardGLFW.cpp
    ya/desktops/glfw/MonitorGLFW.cpp
    ya/desktops/glfw/MouseGLFW.cpp
    ya/desktops/glfw/WindowGLFW.cpp

    ya/events/AppEvent.cpp
    ya/events/CameraEvent.cpp
    ya/events/EmptyEvent.cpp
    ya/events/GamepadEvent.cpp
    ya/events/InputEvent.cpp
    ya/events/JoystickEvent.cpp
    ya/events/KeyboardEvent.cpp
    ya/events/KeyCharacterEvent.cpp
    ya/events/KeyPressEvent.cpp
    ya/events/KeyReleaseEvent.cpp
    ya/events/KeyRepeatEvent.cpp
    #ya/events/MonitorConnectEvent.cpp
    #ya/events/MonitorDisconnectEvent.cpp
    #ya/events/MonitorEvent.cpp
    ya/events/MouseCaptureEvent.cpp
    ya/events/MouseDisableEvent.cpp
    ya/events/MouseDropEvent.cpp
    ya/events/MouseEnterEvent.cpp
    ya/events/MouseEvent.cpp
    ya/events/MouseHideEvent.cpp
    ya/events/MouseLeaveEvent.cpp
    ya/events/MouseMoveEvent.cpp
    ya/events/MouseNormalEvent.cpp
    ya/events/MousePressEvent.cpp
    ya/events/MouseReleaseEvent.cpp
    ya/events/MouseScrollEvent.cpp
    ya/events/SimEvent.cpp
    ya/events/SpatialEvent.cpp
    ya/events/TachyonEvent.cpp
    ya/events/ThreadEvent.cpp
    ya/events/ThreadAddTachyonEvent.cpp
    ya/events/UIEvent.cpp
    ya/events/ViewerCloseEvent.cpp
    ya/events/ViewerDestroyEvent.cpp
    ya/events/ViewerEvent.cpp
    ya/events/VulqanEvent.cpp
    ya/events/WidgetEvent.cpp
    ya/events/WindowAspectEvent.cpp
    ya/events/WindowCursorCaptureEvent.cpp
    ya/events/WindowCursorDisableEvent.cpp
    ya/events/WindowCursorHideEvent.cpp
    ya/events/WindowCursorNormalEvent.cpp
    ya/events/WindowDestroyEvent.cpp
    ya/events/WindowEvent.cpp
    ya/events/WindowFrameBufferResizeEvent.cpp
    ya/events/WindowTitleEvent.cpp
    
    ya/events/gamepad/GamepadAxisEvent.cpp
    ya/events/gamepad/GamepadConnectEvent.cpp
    ya/events/gamepad/GamepadDisconnectEvent.cpp
    ya/events/gamepad/GamepadHatEvent.cpp
    ya/events/gamepad/GamepadPressEvent.cpp
    ya/events/gamepad/GamepadReleaseEvent.cpp
    ya/events/gamepad/GamepadZeroEvent.cpp

    ya/events/joystick/JoystickAxisEvent.cpp
    ya/events/joystick/JoystickConnectEvent.cpp
    ya/events/joystick/JoystickDisconnectEvent.cpp
    ya/events/joystick/JoystickHatEvent.cpp
    ya/events/joystick/JoystickPressEvent.cpp
    ya/events/joystick/JoystickReleaseEvent.cpp
    ya/events/joystick/JoystickZeroEvent.cpp
    
    ya/events/spatial/MaxSize1Event.cpp
    ya/events/spatial/MaxSize2Event.cpp
    ya/events/spatial/MaxSize3Event.cpp
    ya/events/spatial/MinSize1Event.cpp
    ya/events/spatial/MinSize2Event.cpp
    ya/events/spatial/MinSize3Event.cpp
    ya/events/spatial/Position1Event.cpp
    ya/events/spatial/Position2Event.cpp
    ya/events/spatial/Position3Event.cpp
    ya/events/spatial/Orientation3Event.cpp
    ya/events/spatial/Scale1Event.cpp
    ya/events/spatial/Scale2Event.cpp
    ya/events/spatial/Scale3Event.cpp
    ya/events/spatial/Size1Event.cpp
    ya/events/spatial/Size2Event.cpp
    ya/events/spatial/Size3Event.cpp
    
    ya/events/sim/PauseEvent.cpp
    ya/events/sim/ResumeEvent.cpp
    ya/events/sim/TickEvent.cpp
    
    ya/events/tachyon/DestroyEvent.cpp
    ya/events/tachyon/DirtyEvent.cpp
    
    ya/events/ui/DefocusEvent.cpp
    ya/events/ui/FocusEvent.cpp
    ya/events/ui/HideEvent.cpp
    ya/events/ui/IconifyEvent.cpp
    ya/events/ui/MaximizeEvent.cpp
    ya/events/ui/RestoreEvent.cpp
    ya/events/ui/ShowEvent.cpp
    ya/events/ui/TitleEvent.cpp
    
    ya/interfaces/IMaxSize1.cpp
    ya/interfaces/IMaxSize2.cpp
    ya/interfaces/IMaxSize3.cpp
    ya/interfaces/IMinSize1.cpp
    ya/interfaces/IMinSize2.cpp
    ya/interfaces/IMinSize3.cpp
    ya/interfaces/IOrientation3.cpp
    ya/interfaces/IPosition1.cpp
    ya/interfaces/IPosition2.cpp
    ya/interfaces/IPosition3.cpp
    ya/interfaces/IScale1.cpp
    ya/interfaces/IScale2.cpp
    ya/interfaces/IScale3.cpp
    ya/interfaces/ISize1.cpp
    ya/interfaces/ISize2.cpp
    ya/interfaces/ISize3.cpp

    ya/messages/EmptyMessage.cpp
    
    ya/minis/TextLabel.cpp

    ya/posts/AnyPost.cpp
    ya/posts/EmptyPost.cpp
    ya/posts/StringPost.cpp

    ya/proxies/PMaxSize1.cpp
    ya/proxies/PMaxSize2.cpp
    ya/proxies/PMaxSize3.cpp
    ya/proxies/PMinSize1.cpp
    ya/proxies/PMinSize2.cpp
    ya/proxies/PMinSize3.cpp
    ya/proxies/POrientation3.cpp
    ya/proxies/PPosition1.cpp
    ya/proxies/PPosition2.cpp
    ya/proxies/PPosition3.cpp
    ya/proxies/PScale1.cpp
    ya/proxies/PScale2.cpp
    ya/proxies/PScale3.cpp
    ya/proxies/PSize1.cpp
    ya/proxies/PSize2.cpp
    ya/proxies/PSize3.cpp

    ya/rendereds/Billboard3.cpp
    ya/rendereds/ImageQuad3.cpp
    ya/rendereds/Quadrilateral3.cpp
    ya/rendereds/SkyBox3.cpp
    ya/rendereds/Tetrahedron3.cpp
    ya/rendereds/Triangle3.cpp

    ya/replies/AnyReply.cpp
    ya/replies/AppReply.cpp
    ya/replies/CameraReply.cpp
    ya/replies/GraphicsCardReply.cpp
    ya/replies/EmptyReply.cpp
    ya/replies/StringReply.cpp
    ya/replies/TachyonReply.cpp
    ya/replies/UIReply.cpp
    ya/replies/ViewerCloseReply.cpp
    ya/replies/ViewerReply.cpp
    #ya/replies/ViewerWidgetReply.cpp
    ya/replies/WindowReply.cpp
    
    ya/replies/graphics_card/GetDeviceReply.cpp
    
    ya/replies/ui/CloseReply.cpp
    
    ya/requests/AppRequest.cpp
    ya/requests/CameraRequest.cpp
    ya/requests/EmptyRequest.cpp
    ya/requests/GraphicsCardRequest.cpp
    ya/requests/SimRequest.cpp
    ya/requests/TachyonRequest.cpp
    ya/requests/UIRequest.cpp
    ya/requests/ViewerRequest.cpp
    ya/requests/WidgetRequest.cpp
    #ya/requests/WindowRefreshRequest.cpp
    ya/requests/WindowRequest.cpp
    
    ya/requests/graphics_card/GetDeviceRequest.cpp
    
    ya/requests/ui/CloseRequest.cpp
    ya/requests/ui/RefreshRequest.cpp

    ya/scenes/SimpleScene3.cpp

    ya/spatials/GeoSpatial3.cpp
    ya/spatials/SimpleSpatial3.cpp

    ya/threads/AppThread.cpp
    ya/threads/GameThread.cpp
    ya/threads/IOThread.cpp
    ya/threads/NetworkThread.cpp
    ya/threads/SimThread.cpp
    ya/threads/TaskThread.cpp
    ya/threads/ViewerThread.cpp

    ya/triggers/AndTrigger.cpp
    ya/triggers/KeyPressTrigger.cpp
    ya/triggers/NandTrigger.cpp
    ya/triggers/NorTrigger.cpp
    ya/triggers/NotTrigger.cpp
    ya/triggers/OrTrigger.cpp
    ya/triggers/PostTrigger.cpp
    
    ya/utils/LoggerBox.cpp

    ya/widgets/AbstractSceneWidgetHelper.cpp
    ya/widgets/FormWidget.cpp
    ya/widgets/FrameInspector.cpp
    ya/widgets/ImGuiDemoWidget.cpp
    #ya/widgets/LabelWidget.cpp
    ya/widgets/Scene3Widget.cpp
    ya/widgets/StackedWidget.cpp
    ya/widgets/TextArea.cpp
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
    ${CMAKE_CURRENT_LIST_DIR}
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
    yq_text
    yq_vma

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)
