################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)

#   SUPERSCRIPTS ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ʰ ᵖ ⁿ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ
#   Numbers ① ② ③ ④

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    
    #######################################################
    #   Core First
    
    yt/enums.cpp
    yt/strings.cpp
    
    yt/1D/1D.cpp
    yt/1D/Widget1.cpp

    yt/2D/2D.cpp
    yt/2D/Rendered2.cpp
    yt/2D/Widget2.cpp

    yt/3D/3D.cpp
    yt/3D/Camera3.cpp
    yt/3D/Light3.cpp
    yt/3D/Rendered3.cpp
    yt/3D/Scene3.cpp
    yt/3D/Spatial3.cpp
    yt/3D/Widget3.cpp
    
    yt/4D/Widget4.cpp

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
    
    yt/api/meta/AssetGetter.cpp
    yt/api/meta/AssetProperty.cpp
    yt/api/meta/AssetSetter.cpp
    yt/api/meta/DelegateGetter.cpp
    yt/api/meta/DelegateProperty.cpp
    yt/api/meta/DelegateSetter.cpp

    yt/app/Application.cpp
    yt/app/Viewer.cpp

    yt/config/build.cpp

    yt/enum/UICardinal.cpp
    yt/enum/UIFlags.cpp

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
    yt/io/Save.cpp
    
    yt/io/save/SaveAsset.cpp
    yt/io/save/SaveDelegate.cpp
    yt/io/save/SaveObject.cpp
    yt/io/save/SaveTachyon.cpp
    yt/io/save/SaveThread.cpp

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
    yt/ui/ImWidget.cpp
    yt/ui/Layout.cpp
    yt/ui/Mini.cpp
    yt/ui/MyImGui.cpp
    yt/ui/Panel.cpp
    #yt/ui/Tool.cpp
    yt/ui/UIElement.cpp
    yt/ui/UIElementWriter.cpp
    yt/ui/UIUtils.cpp
    #yt/ui/UIWriter.cpp
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
    #yv/ViQueueManager.cpp
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
    
    ya/actions/NullAction.cpp
    ya/actions/PostAction.cpp

    ya/aspects/AMaxSize1.cpp
    ya/aspects/AMaxSize2.cpp
    ya/aspects/AMaxSize3.cpp
    ya/aspects/AMaxSize4.cpp
    ya/aspects/AMinSize1.cpp
    ya/aspects/AMinSize2.cpp
    ya/aspects/AMinSize3.cpp
    ya/aspects/AMinSize4.cpp
    ya/aspects/AOrientation3.cpp
    ya/aspects/APosition1.cpp
    ya/aspects/APosition2.cpp
    ya/aspects/APosition3.cpp
    ya/aspects/APosition4.cpp
    ya/aspects/AScale1.cpp
    ya/aspects/AScale2.cpp
    ya/aspects/AScale3.cpp
    ya/aspects/ASize1.cpp
    ya/aspects/ASize2.cpp
    ya/aspects/ASize3.cpp
    ya/aspects/ASize4.cpp

    ya/cameras/NullCamera.cpp
    ya/cameras/SpaceCamera.cpp
    ya/cameras/TargetCamera.cpp

    ya/commands/AddChildCommand.cpp
    ya/commands/AppCommand.cpp
    ya/commands/AppDeleteViewerCommand.cpp
    ya/commands/CameraCommand.cpp
    ya/commands/ControllerCommand.cpp
    ya/commands/CursorCommand.cpp
    ya/commands/EmptyCommand.cpp
    ya/commands/GamepadCommand.cpp
    ya/commands/GLFWCommand.cpp
    ya/commands/IOCommand.cpp
    ya/commands/JoystickCommand.cpp
    ya/commands/LightCommand.cpp
    ya/commands/MouseCommand.cpp
    #ya/commands/SetParentCommand.cpp
    ya/commands/SimCommand.cpp
    ya/commands/SpatialCommand.cpp
    ya/commands/TachyonCommand.cpp
    ya/commands/ThreadCommand.cpp
    ya/commands/UICommand.cpp
    ya/commands/ViewerCommand.cpp
    ya/commands/WidgetCommand.cpp
    ya/commands/WindowCommand.cpp
    
    ya/commands/aabb/SetAABB1.cpp
    ya/commands/aabb/SetAABB2.cpp
    ya/commands/aabb/SetAABB3.cpp
    ya/commands/aabb/SetAABB4.cpp
    
    ya/commands/camera/CameraSetScreen.cpp

    ya/commands/controller/ControlCommand.cpp
    ya/commands/controller/DisableCommand.cpp
    ya/commands/controller/EnableCommand.cpp
    ya/commands/controller/ListenCommand.cpp
    ya/commands/controller/UncontrolCommand.cpp
    ya/commands/controller/UnlistenCommand.cpp

    ya/commands/cursor/CursorCaptureCommand.cpp
    ya/commands/cursor/CursorDisableCommand.cpp
    ya/commands/cursor/CursorHideCommand.cpp
    ya/commands/cursor/CursorNormalCommand.cpp

    ya/commands/gamepad/GamepadZeroCommand.cpp

    ya/commands/io/SaveCommand.cpp

    ya/commands/joystick/JoystickZeroCommand.cpp

    ya/commands/sim/ResumeCommand.cpp
    ya/commands/sim/PauseCommand.cpp

    ya/commands/orientation/PitchBy.cpp
    ya/commands/orientation/RotateBy3.cpp
    ya/commands/orientation/RollBy.cpp
    ya/commands/orientation/SetHeading.cpp
    ya/commands/orientation/SetOrientation3.cpp
    ya/commands/orientation/SetPitch.cpp
    ya/commands/orientation/SetRoll.cpp
    ya/commands/orientation/YawBy.cpp

    ya/commands/position/AddPosition1.cpp
    ya/commands/position/AddPosition2.cpp
    ya/commands/position/AddPosition3.cpp
    ya/commands/position/AddPosition4.cpp
    ya/commands/position/AddPositionW.cpp
    ya/commands/position/AddPositionX.cpp
    ya/commands/position/AddPositionY.cpp
    ya/commands/position/AddPositionZ.cpp
    ya/commands/position/MoveBy1.cpp
    ya/commands/position/MoveBy2.cpp
    ya/commands/position/MoveBy3.cpp
    ya/commands/position/MoveBy4.cpp
    ya/commands/position/MoveByW.cpp
    ya/commands/position/MoveByX.cpp
    ya/commands/position/MoveByY.cpp
    ya/commands/position/MoveByZ.cpp
    ya/commands/position/MultiplyPosition.cpp
    ya/commands/position/MultiplyPosition1.cpp
    ya/commands/position/MultiplyPosition2.cpp
    ya/commands/position/MultiplyPosition3.cpp
    ya/commands/position/MultiplyPosition4.cpp
    ya/commands/position/MultiplyPositionW.cpp
    ya/commands/position/MultiplyPositionX.cpp
    ya/commands/position/MultiplyPositionY.cpp
    ya/commands/position/MultiplyPositionZ.cpp
    ya/commands/position/SetPosition1.cpp
    ya/commands/position/SetPosition2.cpp
    ya/commands/position/SetPosition3.cpp
    ya/commands/position/SetPosition4.cpp
    ya/commands/position/SetPositionW.cpp
    ya/commands/position/SetPositionX.cpp
    ya/commands/position/SetPositionY.cpp
    ya/commands/position/SetPositionZ.cpp

    ya/commands/scale/AddScale1.cpp
    ya/commands/scale/AddScale2.cpp
    ya/commands/scale/AddScale3.cpp
    ya/commands/scale/AddScaleX.cpp
    ya/commands/scale/AddScaleY.cpp
    ya/commands/scale/AddScaleZ.cpp
    ya/commands/scale/MultiplyScale.cpp
    ya/commands/scale/MultiplyScale1.cpp
    ya/commands/scale/MultiplyScale2.cpp
    ya/commands/scale/MultiplyScale3.cpp
    ya/commands/scale/MultiplyScaleX.cpp
    ya/commands/scale/MultiplyScaleY.cpp
    ya/commands/scale/MultiplyScaleZ.cpp
    ya/commands/scale/SetScale1.cpp
    ya/commands/scale/SetScale2.cpp
    ya/commands/scale/SetScale3.cpp
    ya/commands/scale/SetScaleX.cpp
    ya/commands/scale/SetScaleY.cpp
    ya/commands/scale/SetScaleZ.cpp


    ya/commands/size/AddMaxSize1.cpp
    ya/commands/size/AddMaxSize2.cpp
    ya/commands/size/AddMaxSize3.cpp
    ya/commands/size/AddMaxSize4.cpp
    ya/commands/size/AddMaxSizeW.cpp
    ya/commands/size/AddMaxSizeX.cpp
    ya/commands/size/AddMaxSizeY.cpp
    ya/commands/size/AddMaxSizeZ.cpp
    ya/commands/size/AddMinSize1.cpp
    ya/commands/size/AddMinSize2.cpp
    ya/commands/size/AddMinSize3.cpp
    ya/commands/size/AddMinSize4.cpp
    ya/commands/size/AddMinSizeW.cpp
    ya/commands/size/AddMinSizeX.cpp
    ya/commands/size/AddMinSizeY.cpp
    ya/commands/size/AddMinSizeZ.cpp
    ya/commands/size/AddSize1.cpp
    ya/commands/size/AddSize2.cpp
    ya/commands/size/AddSize3.cpp
    ya/commands/size/AddSize4.cpp
    ya/commands/size/AddSizeW.cpp
    ya/commands/size/AddSizeX.cpp
    ya/commands/size/AddSizeY.cpp
    ya/commands/size/AddSizeZ.cpp
    ya/commands/size/MultiplyMaxSize.cpp
    ya/commands/size/MultiplyMaxSize1.cpp
    ya/commands/size/MultiplyMaxSize2.cpp
    ya/commands/size/MultiplyMaxSize3.cpp
    ya/commands/size/MultiplyMaxSize4.cpp
    ya/commands/size/MultiplyMaxSizeW.cpp
    ya/commands/size/MultiplyMaxSizeX.cpp
    ya/commands/size/MultiplyMaxSizeY.cpp
    ya/commands/size/MultiplyMaxSizeZ.cpp
    ya/commands/size/MultiplyMinSize.cpp
    ya/commands/size/MultiplyMinSize1.cpp
    ya/commands/size/MultiplyMinSize2.cpp
    ya/commands/size/MultiplyMinSize3.cpp
    ya/commands/size/MultiplyMinSize4.cpp
    ya/commands/size/MultiplyMinSizeW.cpp
    ya/commands/size/MultiplyMinSizeX.cpp
    ya/commands/size/MultiplyMinSizeY.cpp
    ya/commands/size/MultiplyMinSizeZ.cpp
    ya/commands/size/MultiplySize.cpp
    ya/commands/size/MultiplySize1.cpp
    ya/commands/size/MultiplySize2.cpp
    ya/commands/size/MultiplySize3.cpp
    ya/commands/size/MultiplySize4.cpp
    ya/commands/size/MultiplySizeW.cpp
    ya/commands/size/MultiplySizeX.cpp
    ya/commands/size/MultiplySizeY.cpp
    ya/commands/size/MultiplySizeZ.cpp
    ya/commands/size/SetMaxSize1.cpp
    ya/commands/size/SetMaxSize2.cpp
    ya/commands/size/SetMaxSize3.cpp
    ya/commands/size/SetMaxSize4.cpp
    ya/commands/size/SetMaxSizeW.cpp
    ya/commands/size/SetMaxSizeX.cpp
    ya/commands/size/SetMaxSizeY.cpp
    ya/commands/size/SetMaxSizeZ.cpp
    ya/commands/size/SetMinSize1.cpp
    ya/commands/size/SetMinSize2.cpp
    ya/commands/size/SetMinSize3.cpp
    ya/commands/size/SetMinSize4.cpp
    ya/commands/size/SetMinSizeW.cpp
    ya/commands/size/SetMinSizeX.cpp
    ya/commands/size/SetMinSizeY.cpp
    ya/commands/size/SetMinSizeZ.cpp
    ya/commands/size/SetSize1.cpp
    ya/commands/size/SetSize2.cpp
    ya/commands/size/SetSize3.cpp
    ya/commands/size/SetSize4.cpp
    ya/commands/size/SetSizeW.cpp
    ya/commands/size/SetSizeX.cpp
    ya/commands/size/SetSizeY.cpp
    ya/commands/size/SetSizeZ.cpp
    
    ya/commands/spatial/AABBCommand.cpp
    ya/commands/spatial/OrientationCommand.cpp
    ya/commands/spatial/PositionCommand.cpp
    ya/commands/spatial/ScaleCommand.cpp
    ya/commands/spatial/SizeCommand.cpp
    
    ya/commands/tachyon/AddChildCommand.cpp
    ya/commands/tachyon/DestroyCommand.cpp
    ya/commands/tachyon/RemoveChildCommand.cpp
    ya/commands/tachyon/RethreadCommand.cpp
    ya/commands/tachyon/SetNameCommand.cpp
    ya/commands/tachyon/SetParentCommand.cpp
    ya/commands/tachyon/SnoopCommand.cpp
    ya/commands/tachyon/SubscribeCommand.cpp
    ya/commands/tachyon/UnsnoopCommand.cpp
    ya/commands/tachyon/UnsubscribeCommand.cpp
    
    ya/commands/thread/ScheduleCommand.cpp
    
    ya/commands/ui/AspectCommand.cpp
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
    ya/commands/ui/TitleCommand.cpp
    ya/commands/ui/UnfloatCommand.cpp

    ya/commands/viewer/SetWidgetCommand.cpp
    
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
    ya/events/CursorEvent.cpp
    ya/events/EmptyEvent.cpp
    ya/events/GamepadEvent.cpp
    ya/events/InputEvent.cpp
    ya/events/IOEvent.cpp
    ya/events/JoystickEvent.cpp
    ya/events/KeyboardEvent.cpp
    ya/events/MonitorEvent.cpp
    ya/events/MouseEvent.cpp
    ya/events/OSEvent.cpp
    ya/events/SimEvent.cpp
    ya/events/SpatialEvent.cpp
    ya/events/TachyonEvent.cpp
    ya/events/ThreadEvent.cpp
    ya/events/UIEvent.cpp
    ya/events/ViewerEvent.cpp
    ya/events/VulqanEvent.cpp
    ya/events/WidgetEvent.cpp
    ya/events/WindowEvent.cpp
    
    ya/events/cursor/CursorCaptureEvent.cpp
    ya/events/cursor/CursorDisableEvent.cpp
    ya/events/cursor/CursorHideEvent.cpp
    ya/events/cursor/CursorNormalEvent.cpp
    
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

    ya/events/keyboard/KeyCharacterEvent.cpp
    ya/events/keyboard/KeyPressEvent.cpp
    ya/events/keyboard/KeyReleaseEvent.cpp
    ya/events/keyboard/KeyRepeatEvent.cpp
    
    ya/events/monitor/MonitorConnectEvent.cpp
    ya/events/monitor/MonitorDisconnectEvent.cpp

    ya/events/mouse/MouseDropEvent.cpp
    ya/events/mouse/MouseEnterEvent.cpp
    ya/events/mouse/MouseLeaveEvent.cpp
    ya/events/mouse/MouseMoveEvent.cpp
    ya/events/mouse/MousePressEvent.cpp
    ya/events/mouse/MouseReleaseEvent.cpp
    ya/events/mouse/MouseScrollEvent.cpp

    ya/events/spatial/AABB1Event.cpp
    ya/events/spatial/AABB2Event.cpp
    ya/events/spatial/AABB3Event.cpp
    ya/events/spatial/AABB4Event.cpp
    ya/events/spatial/MaxSize1Event.cpp
    ya/events/spatial/MaxSize2Event.cpp
    ya/events/spatial/MaxSize3Event.cpp
    ya/events/spatial/MaxSize4Event.cpp
    ya/events/spatial/MinSize1Event.cpp
    ya/events/spatial/MinSize2Event.cpp
    ya/events/spatial/MinSize3Event.cpp
    ya/events/spatial/MinSize4Event.cpp
    ya/events/spatial/Position1Event.cpp
    ya/events/spatial/Position2Event.cpp
    ya/events/spatial/Position3Event.cpp
    ya/events/spatial/Position4Event.cpp
    ya/events/spatial/Orientation3Event.cpp
    ya/events/spatial/Scale1Event.cpp
    ya/events/spatial/Scale2Event.cpp
    ya/events/spatial/Scale3Event.cpp
    ya/events/spatial/Size1Event.cpp
    ya/events/spatial/Size2Event.cpp
    ya/events/spatial/Size3Event.cpp
    ya/events/spatial/Size4Event.cpp
    
    ya/events/sim/PauseEvent.cpp
    ya/events/sim/ResumeEvent.cpp
    ya/events/sim/TickEvent.cpp
    
    ya/events/tachyon/ChildAddEvent.cpp
    ya/events/tachyon/ChildRemoveEvent.cpp
    ya/events/tachyon/DestroyEvent.cpp
    ya/events/tachyon/DirtyEvent.cpp
    ya/events/tachyon/NameChangeEvent.cpp
    ya/events/tachyon/ParentChangeEvent.cpp
    
    ya/events/thread/ThreadAddTachyonEvent.cpp

    ya/events/ui/AspectEvent.cpp
    ya/events/ui/DefocusEvent.cpp
    ya/events/ui/CloseEvent.cpp
    ya/events/ui/FocusEvent.cpp
    ya/events/ui/HideEvent.cpp
    ya/events/ui/IconifyEvent.cpp
    ya/events/ui/MaximizeEvent.cpp
    ya/events/ui/RestoreEvent.cpp
    ya/events/ui/ShowEvent.cpp
    ya/events/ui/TitleEvent.cpp
    
    ya/events/window/FramebufferResizeEvent.cpp
    
    ya/formats/SaveXML.cpp

    ya/interfaces/IMaxSize1.cpp
    ya/interfaces/IMaxSize2.cpp
    ya/interfaces/IMaxSize3.cpp
    ya/interfaces/IMaxSize4.cpp
    ya/interfaces/IMinSize1.cpp
    ya/interfaces/IMinSize2.cpp
    ya/interfaces/IMinSize3.cpp
    ya/interfaces/IMinSize4.cpp
    ya/interfaces/IOrientation3.cpp
    ya/interfaces/IPosition1.cpp
    ya/interfaces/IPosition2.cpp
    ya/interfaces/IPosition3.cpp
    ya/interfaces/IPosition4.cpp
    ya/interfaces/IScale1.cpp
    ya/interfaces/IScale2.cpp
    ya/interfaces/IScale3.cpp
    ya/interfaces/ISize1.cpp
    ya/interfaces/ISize2.cpp
    ya/interfaces/ISize3.cpp
    ya/interfaces/ISize4.cpp

    ya/messages/EmptyMessage.cpp
    
    ya/minis/TextLabel.cpp

    ya/posts/AnyPost.cpp
    ya/posts/EmptyPost.cpp
    ya/posts/StringPost.cpp

    ya/proxies/PMaxSize1.cpp
    ya/proxies/PMaxSize2.cpp
    ya/proxies/PMaxSize3.cpp
    ya/proxies/PMaxSize4.cpp
    ya/proxies/PMinSize1.cpp
    ya/proxies/PMinSize2.cpp
    ya/proxies/PMinSize3.cpp
    ya/proxies/PMinSize4.cpp
    ya/proxies/POrientation3.cpp
    ya/proxies/PPosition1.cpp
    ya/proxies/PPosition2.cpp
    ya/proxies/PPosition3.cpp
    ya/proxies/PPosition4.cpp
    ya/proxies/PScale1.cpp
    ya/proxies/PScale2.cpp
    ya/proxies/PScale3.cpp
    ya/proxies/PSize1.cpp
    ya/proxies/PSize2.cpp
    ya/proxies/PSize3.cpp
    ya/proxies/PSize4.cpp
    
    ya/rasters/PatternRasters.cpp
    ya/rasters/DebugRasters.cpp

    ya/rendereds/Billboard3.cpp
    ya/rendereds/ImageQuad3.cpp
    ya/rendereds/Quadrilateral3.cpp
    ya/rendereds/SkyBox3.cpp
    ya/rendereds/Tetrahedron3.cpp
    ya/rendereds/Triangle3.cpp

    ya/replies/AnyReply.cpp
    ya/replies/AppReply.cpp
    ya/replies/CameraReply.cpp
    ya/replies/EmptyReply.cpp
    ya/replies/GraphicsCardReply.cpp
    ya/replies/IOReply.cpp
    ya/replies/SimReply.cpp
    ya/replies/StringReply.cpp
    ya/replies/TachyonReply.cpp
    ya/replies/UIReply.cpp
    ya/replies/ViewerReply.cpp
    #ya/replies/ViewerWidgetReply.cpp
    ya/replies/WindowReply.cpp
    
    ya/replies/app/OpenFileReply.cpp
    ya/replies/app/SaveFileReply.cpp
    
    ya/replies/graphics_card/GetDeviceReply.cpp
    
    ya/replies/io/SaveReply.cpp
    
    ya/replies/ui/CloseReply.cpp
    
    ya/requests/AppRequest.cpp
    ya/requests/CameraRequest.cpp
    ya/requests/EmptyRequest.cpp
    ya/requests/GraphicsCardRequest.cpp
    ya/requests/IORequest.cpp
    ya/requests/SimRequest.cpp
    ya/requests/TachyonRequest.cpp
    ya/requests/UIRequest.cpp
    ya/requests/ViewerRequest.cpp
    ya/requests/WidgetRequest.cpp
    #ya/requests/WindowRefreshRequest.cpp
    ya/requests/WindowRequest.cpp
    
    ya/requests/app/OpenFileRequest.cpp
    ya/requests/app/SaveFileRequest.cpp
    
    ya/requests/graphics_card/GetDeviceRequest.cpp
    
    ya/requests/io/SaveRequest.cpp
    
    ya/requests/ui/CloseRequest.cpp
    ya/requests/ui/RefreshRequest.cpp

    ya/scenes/SimpleScene3.cpp

    ya/spatials/GeoSpatial3.cpp
    ya/spatials/SimpleSpatial3.cpp

    ya/threads/AppThread.cpp
    ya/threads/AudioThread.cpp
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
    
    ya/uis/UIAppMain.cpp
    ya/uis/UIAppMainWriter.cpp
    ya/uis/UIAssetImage.cpp
    ya/uis/UIButton.cpp
    ya/uis/UICenterAlign.cpp
    ya/uis/UIElements.cpp
    ya/uis/UIElementsWriter.cpp
    ya/uis/UIHBox.cpp
    ya/uis/UIImage.cpp
    ya/uis/UIMenu.cpp
    ya/uis/UIMenuWriter.cpp
    ya/uis/UIMenuBar.cpp
    ya/uis/UIMenuBarWriter.cpp
    ya/uis/UIMenuItem.cpp
    ya/uis/UIRightAlign.cpp
    ya/uis/UISpacer.cpp
    ya/uis/UITextLabel.cpp
    ya/uis/UIToolBar.cpp
    ya/uis/UIToolBarWriter.cpp
    ya/uis/UIWindow.cpp
    ya/uis/UIWindowWriter.cpp
    
    ya/utilities/LoggerBox.cpp

    #ya/widgets/AbstractSceneWidgetHelper.cpp
    ya/widgets/AppWidget.cpp
    ya/widgets/FormWidget.cpp
    ya/widgets/FrameInspector.cpp
    ya/widgets/ImGuiDemoWidget.cpp
    #ya/widgets/LabelWidget.cpp
    ya/widgets/Scene3Widget.cpp
    ya/widgets/SpaceCameraRemote.cpp
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
    yq_keyv
    yq_math
    yq_process
    yq_raster
    yq_text
    yq_xml

    ImGui
    STBImage 
    VulkanMemoryAllocator

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)
