################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)

#   SUPERSCRIPTS ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ʰ ᵖ ⁿ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ
#   Numbers ① ② ③ ④
#   Greek Δ δ

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    #   ALPHABETICAL

    MyImGui.cpp
    enums.cpp
    strings.cpp

    accessor/StringFunction.cpp
    accessor/StringValue.cpp

    action/CallbackAction.cpp
    action/NullAction.cpp
    action/PostAction.cpp
    action/VisibleUIAction.cpp


    api/1D.cpp
    api/2D.cpp
    api/3D.cpp
    api/Action.cpp
    api/Camera.cpp
    api/Camera3.cpp
    api/CameraTweak.cpp
    api/Command.cpp
    api/Control.cpp
    api/Controller.cpp
    api/Delegate.cpp
    #api/Editor.cpp
    api/Event.cpp
    api/Frame.cpp
    api/InterfaceInfo.cpp
    api/Layer.cpp
    api/Light.cpp    
    api/Light3.cpp
    api/Manager.cpp
    api/Message.cpp
    api/Mini.cpp
    api/Model.cpp
    api/N.cpp
    api/Panel.cpp
    api/Payload.cpp
    api/Perspective.cpp
    api/Post.cpp
    api/Proxy.cpp
    api/Rendered.cpp
    api/Rendered2.cpp
    api/Rendered3.cpp
    api/Reply.cpp
    api/Request.cpp
    api/Scene.cpp
    #api/Scene2.cpp
    api/Scene3.cpp
    api/Spatial.cpp
    api/Spatial2.cpp
    api/Spatial3.cpp
    api/Tachyon.cpp
    api/Thread.cpp
    #api/Tool.cpp
    api/Trigger.cpp
    api/TypedID.cpp
    api/Undo.cpp
    api/Widget.cpp
    
    api/meta/AssetGetter.cpp
    api/meta/AssetProperty.cpp
    api/meta/AssetSetter.cpp
    api/meta/DelegateGetter.cpp
    api/meta/DelegateProperty.cpp
    api/meta/DelegateSetter.cpp

    app/Application.cpp
    app/Viewer.cpp
    app/VulqanConfig.cpp

    aspect/AMaxSize1.cpp
    aspect/AMaxSize2.cpp
    aspect/AMaxSize3.cpp
    aspect/AMaxSize4.cpp
    aspect/AMinSize1.cpp
    aspect/AMinSize2.cpp
    aspect/AMinSize3.cpp
    aspect/AMinSize4.cpp
    aspect/AOrientation2.cpp
    aspect/AOrientation3.cpp
    aspect/APosition1.cpp
    aspect/APosition2.cpp
    aspect/APosition3.cpp
    aspect/APosition4.cpp
    aspect/AScale1.cpp
    aspect/AScale2.cpp
    aspect/AScale3.cpp
    aspect/ASize1.cpp
    aspect/ASize2.cpp
    aspect/ASize3.cpp
    aspect/ASize4.cpp
        
    camera/NullCamera.cpp
    camera/SpaceCamera.cpp
    camera/TargetCamera.cpp


    command/AddChildCommand.cpp
    command/AppCommand.cpp
    command/AppDeleteViewerCommand.cpp
    command/CameraCommand.cpp
    command/ControllerCommand.cpp
    command/CursorCommand.cpp
    command/EmptyCommand.cpp
    command/GamepadCommand.cpp
    command/GLFWCommand.cpp
    command/IOCommand.cpp
    command/JoystickCommand.cpp
    command/LightCommand.cpp
    command/MouseCommand.cpp
    #command/SetParentCommand.cpp
    command/SimCommand.cpp
    command/SpatialCommand.cpp
    command/TachyonCommand.cpp
    command/ThreadCommand.cpp
    command/UICommand.cpp
    command/ViewerCommand.cpp
    command/WidgetCommand.cpp
    command/WindowCommand.cpp
    
    command/aabb/SetAABB1.cpp
    command/aabb/SetAABB2.cpp
    command/aabb/SetAABB3.cpp
    command/aabb/SetAABB4.cpp
    
    command/camera/CameraSetScreen.cpp

    command/controller/ControlCommand.cpp
    command/controller/DisableCommand.cpp
    command/controller/EnableCommand.cpp
    command/controller/ListenCommand.cpp
    command/controller/UncontrolCommand.cpp
    command/controller/UnlistenCommand.cpp

    command/cursor/CursorCaptureCommand.cpp
    command/cursor/CursorDisableCommand.cpp
    command/cursor/CursorHideCommand.cpp
    command/cursor/CursorNormalCommand.cpp

    command/gamepad/GamepadZeroCommand.cpp

    command/io/SaveCommand.cpp

    command/joystick/JoystickZeroCommand.cpp

    command/sim/ResumeCommand.cpp
    command/sim/PauseCommand.cpp

    command/orientation/PitchBy.cpp
    command/orientation/RotateBy2.cpp
    command/orientation/RotateBy3.cpp
    command/orientation/RollBy.cpp
    command/orientation/SetHeading.cpp
    command/orientation/SetOrientation2.cpp
    command/orientation/SetOrientation3.cpp
    command/orientation/SetPitch.cpp
    command/orientation/SetRoll.cpp
    command/orientation/YawBy.cpp

    command/position/AddPosition1.cpp
    command/position/AddPosition2.cpp
    command/position/AddPosition3.cpp
    command/position/AddPosition4.cpp
    command/position/AddPositionW.cpp
    command/position/AddPositionX.cpp
    command/position/AddPositionY.cpp
    command/position/AddPositionZ.cpp
    command/position/MoveBy1.cpp
    command/position/MoveBy2.cpp
    command/position/MoveBy3.cpp
    command/position/MoveBy4.cpp
    command/position/MoveByW.cpp
    command/position/MoveByX.cpp
    command/position/MoveByY.cpp
    command/position/MoveByZ.cpp
    command/position/MultiplyPosition.cpp
    command/position/MultiplyPosition1.cpp
    command/position/MultiplyPosition2.cpp
    command/position/MultiplyPosition3.cpp
    command/position/MultiplyPosition4.cpp
    command/position/MultiplyPositionW.cpp
    command/position/MultiplyPositionX.cpp
    command/position/MultiplyPositionY.cpp
    command/position/MultiplyPositionZ.cpp
    command/position/SetPosition1.cpp
    command/position/SetPosition2.cpp
    command/position/SetPosition3.cpp
    command/position/SetPosition4.cpp
    command/position/SetPositionW.cpp
    command/position/SetPositionX.cpp
    command/position/SetPositionY.cpp
    command/position/SetPositionZ.cpp

    command/scale/AddScale1.cpp
    command/scale/AddScale2.cpp
    command/scale/AddScale3.cpp
    command/scale/AddScaleX.cpp
    command/scale/AddScaleY.cpp
    command/scale/AddScaleZ.cpp
    command/scale/MultiplyScale.cpp
    command/scale/MultiplyScale1.cpp
    command/scale/MultiplyScale2.cpp
    command/scale/MultiplyScale3.cpp
    command/scale/MultiplyScaleX.cpp
    command/scale/MultiplyScaleY.cpp
    command/scale/MultiplyScaleZ.cpp
    command/scale/SetScale1.cpp
    command/scale/SetScale2.cpp
    command/scale/SetScale3.cpp
    command/scale/SetScaleX.cpp
    command/scale/SetScaleY.cpp
    command/scale/SetScaleZ.cpp


    command/size/AddMaxSize1.cpp
    command/size/AddMaxSize2.cpp
    command/size/AddMaxSize3.cpp
    command/size/AddMaxSize4.cpp
    command/size/AddMaxSizeW.cpp
    command/size/AddMaxSizeX.cpp
    command/size/AddMaxSizeY.cpp
    command/size/AddMaxSizeZ.cpp
    command/size/AddMinSize1.cpp
    command/size/AddMinSize2.cpp
    command/size/AddMinSize3.cpp
    command/size/AddMinSize4.cpp
    command/size/AddMinSizeW.cpp
    command/size/AddMinSizeX.cpp
    command/size/AddMinSizeY.cpp
    command/size/AddMinSizeZ.cpp
    command/size/AddSize1.cpp
    command/size/AddSize2.cpp
    command/size/AddSize3.cpp
    command/size/AddSize4.cpp
    command/size/AddSizeW.cpp
    command/size/AddSizeX.cpp
    command/size/AddSizeY.cpp
    command/size/AddSizeZ.cpp
    command/size/MultiplyMaxSize.cpp
    command/size/MultiplyMaxSize1.cpp
    command/size/MultiplyMaxSize2.cpp
    command/size/MultiplyMaxSize3.cpp
    command/size/MultiplyMaxSize4.cpp
    command/size/MultiplyMaxSizeW.cpp
    command/size/MultiplyMaxSizeX.cpp
    command/size/MultiplyMaxSizeY.cpp
    command/size/MultiplyMaxSizeZ.cpp
    command/size/MultiplyMinSize.cpp
    command/size/MultiplyMinSize1.cpp
    command/size/MultiplyMinSize2.cpp
    command/size/MultiplyMinSize3.cpp
    command/size/MultiplyMinSize4.cpp
    command/size/MultiplyMinSizeW.cpp
    command/size/MultiplyMinSizeX.cpp
    command/size/MultiplyMinSizeY.cpp
    command/size/MultiplyMinSizeZ.cpp
    command/size/MultiplySize.cpp
    command/size/MultiplySize1.cpp
    command/size/MultiplySize2.cpp
    command/size/MultiplySize3.cpp
    command/size/MultiplySize4.cpp
    command/size/MultiplySizeW.cpp
    command/size/MultiplySizeX.cpp
    command/size/MultiplySizeY.cpp
    command/size/MultiplySizeZ.cpp
    command/size/SetMaxSize1.cpp
    command/size/SetMaxSize2.cpp
    command/size/SetMaxSize3.cpp
    command/size/SetMaxSize4.cpp
    command/size/SetMaxSizeW.cpp
    command/size/SetMaxSizeX.cpp
    command/size/SetMaxSizeY.cpp
    command/size/SetMaxSizeZ.cpp
    command/size/SetMinSize1.cpp
    command/size/SetMinSize2.cpp
    command/size/SetMinSize3.cpp
    command/size/SetMinSize4.cpp
    command/size/SetMinSizeW.cpp
    command/size/SetMinSizeX.cpp
    command/size/SetMinSizeY.cpp
    command/size/SetMinSizeZ.cpp
    command/size/SetSize1.cpp
    command/size/SetSize2.cpp
    command/size/SetSize3.cpp
    command/size/SetSize4.cpp
    command/size/SetSizeW.cpp
    command/size/SetSizeX.cpp
    command/size/SetSizeY.cpp
    command/size/SetSizeZ.cpp
    
    command/spatial/AABBCommand.cpp
    command/spatial/OrientationCommand.cpp
    command/spatial/PositionCommand.cpp
    command/spatial/ScaleCommand.cpp
    command/spatial/SizeCommand.cpp
    
    command/tachyon/AddChildCommand.cpp
    command/tachyon/DestroyCommand.cpp
    command/tachyon/RemoveChildCommand.cpp
    command/tachyon/RethreadCommand.cpp
    command/tachyon/SetAttributeCommand.cpp
    command/tachyon/SetNameCommand.cpp
    command/tachyon/SetParentCommand.cpp
    command/tachyon/SnoopCommand.cpp
    command/tachyon/SubscribeCommand.cpp
    command/tachyon/UnsnoopCommand.cpp
    command/tachyon/UnsubscribeCommand.cpp
    
    command/thread/ScheduleCommand.cpp
    
    command/ui/AspectCommand.cpp
    command/ui/AttentionCommand.cpp
    command/ui/CloseCommand.cpp
    command/ui/FloatCommand.cpp
    command/ui/FocusCommand.cpp
    command/ui/HideCommand.cpp
    command/ui/IconifyCommand.cpp
    command/ui/MaximizeCommand.cpp
    command/ui/RestoreCommand.cpp
    command/ui/ShowCommand.cpp
    command/ui/StartupCommand.cpp
    command/ui/TitleCommand.cpp
    command/ui/UnfloatCommand.cpp

    command/viewer/SetWidgetCommand.cpp
    
    command/widget/SetViewer.cpp

    config/build.cpp

    control/Orientation3Control.cpp

    controller/Space3Controller.cpp

    enum/Cardinal.cpp
    enum/UIFlags.cpp


    event/AppEvent.cpp
    event/CameraEvent.cpp
    event/CursorEvent.cpp
    event/EmptyEvent.cpp
    event/GamepadEvent.cpp
    event/InputEvent.cpp
    event/IOEvent.cpp
    event/JoystickEvent.cpp
    event/KeyboardEvent.cpp
    event/MonitorEvent.cpp
    event/MouseEvent.cpp
    event/OSEvent.cpp
    event/SimEvent.cpp
    event/SpatialEvent.cpp
    event/TachyonEvent.cpp
    event/ThreadEvent.cpp
    event/UIEvent.cpp
    event/ViewerEvent.cpp
    event/VulqanEvent.cpp
    event/WidgetEvent.cpp
    event/WindowEvent.cpp
    
    event/cursor/CursorCaptureEvent.cpp
    event/cursor/CursorDisableEvent.cpp
    event/cursor/CursorHideEvent.cpp
    event/cursor/CursorNormalEvent.cpp
    
    event/gamepad/GamepadAxisEvent.cpp
    event/gamepad/GamepadConnectEvent.cpp
    event/gamepad/GamepadDisconnectEvent.cpp
    event/gamepad/GamepadHatEvent.cpp
    event/gamepad/GamepadPressEvent.cpp
    event/gamepad/GamepadReleaseEvent.cpp
    event/gamepad/GamepadZeroEvent.cpp

    event/joystick/JoystickAxisEvent.cpp
    event/joystick/JoystickConnectEvent.cpp
    event/joystick/JoystickDisconnectEvent.cpp
    event/joystick/JoystickHatEvent.cpp
    event/joystick/JoystickPressEvent.cpp
    event/joystick/JoystickReleaseEvent.cpp
    event/joystick/JoystickZeroEvent.cpp

    event/keyboard/KeyCharacterEvent.cpp
    event/keyboard/KeyPressEvent.cpp
    event/keyboard/KeyReleaseEvent.cpp
    event/keyboard/KeyRepeatEvent.cpp
    
    event/monitor/MonitorConnectEvent.cpp
    event/monitor/MonitorDisconnectEvent.cpp

    event/mouse/MouseDropEvent.cpp
    event/mouse/MouseEnterEvent.cpp
    event/mouse/MouseLeaveEvent.cpp
    event/mouse/MouseMoveEvent.cpp
    event/mouse/MousePressEvent.cpp
    event/mouse/MouseReleaseEvent.cpp
    event/mouse/MouseScrollEvent.cpp

    event/spatial/AABB1Event.cpp
    event/spatial/AABB2Event.cpp
    event/spatial/AABB3Event.cpp
    event/spatial/AABB4Event.cpp
    event/spatial/MaxSize1Event.cpp
    event/spatial/MaxSize2Event.cpp
    event/spatial/MaxSize3Event.cpp
    event/spatial/MaxSize4Event.cpp
    event/spatial/MinSize1Event.cpp
    event/spatial/MinSize2Event.cpp
    event/spatial/MinSize3Event.cpp
    event/spatial/MinSize4Event.cpp
    event/spatial/Position1Event.cpp
    event/spatial/Position2Event.cpp
    event/spatial/Position3Event.cpp
    event/spatial/Position4Event.cpp
    event/spatial/Orientation2Event.cpp
    event/spatial/Orientation3Event.cpp
    event/spatial/Scale1Event.cpp
    event/spatial/Scale2Event.cpp
    event/spatial/Scale3Event.cpp
    event/spatial/Size1Event.cpp
    event/spatial/Size2Event.cpp
    event/spatial/Size3Event.cpp
    event/spatial/Size4Event.cpp
    
    event/sim/PauseEvent.cpp
    event/sim/ResumeEvent.cpp
    event/sim/TickEvent.cpp
    
    event/tachyon/ChildAddEvent.cpp
    event/tachyon/ChildRemoveEvent.cpp
    event/tachyon/DestroyEvent.cpp
    event/tachyon/DirtyEvent.cpp
    event/tachyon/NameChangeEvent.cpp
    event/tachyon/ParentChangeEvent.cpp
    
    event/thread/ThreadAddTachyonEvent.cpp

    event/ui/AspectEvent.cpp
    event/ui/DefocusEvent.cpp
    event/ui/CloseEvent.cpp
    event/ui/FocusEvent.cpp
    event/ui/HideEvent.cpp
    event/ui/IconifyEvent.cpp
    event/ui/MaximizeEvent.cpp
    event/ui/RestoreEvent.cpp
    event/ui/ShowEvent.cpp
    event/ui/TitleEvent.cpp
    
    event/window/FramebufferResizeEvent.cpp
    
    gfx/Buffer.cpp
    gfx/Pipeline.cpp
    gfx/PipelineUtils.cpp
    gfx/Raster.cpp
    gfx/RenderPass.cpp
    gfx/Sampler.cpp
    gfx/Shader.cpp
    gfx/Texture.cpp

    interface/IMaxSize1.cpp
    interface/IMaxSize2.cpp
    interface/IMaxSize3.cpp
    interface/IMaxSize4.cpp
    interface/IMinSize1.cpp
    interface/IMinSize2.cpp
    interface/IMinSize3.cpp
    interface/IMinSize4.cpp
    interface/IOrientation2.cpp
    interface/IOrientation3.cpp
    interface/IPosition1.cpp
    interface/IPosition2.cpp
    interface/IPosition3.cpp
    interface/IPosition4.cpp
    interface/IScale1.cpp
    interface/IScale2.cpp
    interface/IScale3.cpp
    interface/ISize1.cpp
    interface/ISize2.cpp
    interface/ISize3.cpp
    interface/ISize4.cpp
    
    io/FileIOManager.cpp
    io/GLSLShader.cpp
    io/SamplerInfoFile.cpp
    io/STBImage.cpp
    io/Save.cpp
    
    io/save/SaveAsset.cpp
    io/save/SaveDelegate.cpp
    io/save/SaveObject.cpp
    io/save/SaveTachyon.cpp
    io/save/SaveThread.cpp
    io/save/SaveXML.cpp
    
    layer/BackgroundLayer.cpp
    layer/ForegroundLayer.cpp
    layer/HUDLayer.cpp

    message/EmptyMessage.cpp

    mini/TextLabel.cpp
    

    os/Cursor.cpp
    os/Desktop.cpp
    os/Gamepad.cpp
    os/GraphicsCard.cpp
    os/Joystick.cpp
    os/Keyboard.cpp
    os/KeyCode.cpp
    os/ModifierKey.cpp
    os/Monitor.cpp
    os/Mouse.cpp
    os/VideoMode.cpp
    os/Window.cpp

    os/glfw/CursorGLFW.cpp
    os/glfw/DesktopGLFW.cpp
    os/glfw/GamepadGLFW.cpp
    os/glfw/JoystickGLFW.cpp
    os/glfw/KeyboardGLFW.cpp
    os/glfw/MonitorGLFW.cpp
    os/glfw/MouseGLFW.cpp
    os/glfw/WindowGLFW.cpp

    post/AnyPost.cpp
    post/EmptyPost.cpp
    post/StringPost.cpp

    proxy/PMaxSize1.cpp
    proxy/PMaxSize2.cpp
    proxy/PMaxSize3.cpp
    proxy/PMaxSize4.cpp
    proxy/PMinSize1.cpp
    proxy/PMinSize2.cpp
    proxy/PMinSize3.cpp
    proxy/PMinSize4.cpp
    proxy/POrientation2.cpp
    proxy/POrientation3.cpp
    proxy/PPosition1.cpp
    proxy/PPosition2.cpp
    proxy/PPosition3.cpp
    proxy/PPosition4.cpp
    proxy/PScale1.cpp
    proxy/PScale2.cpp
    proxy/PScale3.cpp
    proxy/PSize1.cpp
    proxy/PSize2.cpp
    proxy/PSize3.cpp
    proxy/PSize4.cpp
    
    raster/PatternRasters.cpp
    raster/DebugRasters.cpp

    rendered/Billboard3.cpp
    rendered/ImageQuad3.cpp
    rendered/Quadrilateral3.cpp
    rendered/SkyBox3.cpp
    rendered/Tetrahedron3.cpp
    rendered/Triangle3.cpp

    reply/AnyReply.cpp
    reply/AppReply.cpp
    reply/CameraReply.cpp
    reply/EmptyReply.cpp
    reply/GraphicsCardReply.cpp
    reply/IOReply.cpp
    reply/SimReply.cpp
    reply/StringReply.cpp
    reply/TachyonReply.cpp
    reply/UIReply.cpp
    reply/ViewerReply.cpp
    #reply/ViewerWidgetReply.cpp
    reply/WindowReply.cpp
    
    reply/app/OpenFileReply.cpp
    reply/app/SaveFileReply.cpp
    
    reply/graphics_card/GetDeviceReply.cpp
    
    reply/io/LoadTSXReply.cpp
    reply/io/SaveReply.cpp
    reply/io/SaveTSXReply.cpp
    
    reply/ui/CloseReply.cpp
    
    request/AppRequest.cpp
    request/CameraRequest.cpp
    request/EmptyRequest.cpp
    request/GraphicsCardRequest.cpp
    request/IORequest.cpp
    request/SimRequest.cpp
    request/TachyonRequest.cpp
    request/UIRequest.cpp
    request/ViewerRequest.cpp
    request/WidgetRequest.cpp
    #request/WindowRefreshRequest.cpp
    request/WindowRequest.cpp
    
    request/app/OpenFileRequest.cpp
    request/app/SaveFileRequest.cpp
    
    request/graphics_card/GetDeviceRequest.cpp
    
    request/io/LoadTSXRequest.cpp
    request/io/SaveRequest.cpp
    request/io/SaveTSXRequest.cpp
    
    request/ui/CloseRequest.cpp
    request/ui/RefreshRequest.cpp

    scene/BackgroundScene.cpp
    scene/ForegroundScene.cpp
    scene/HUDScene.cpp
    scene/SimpleScene.cpp
    
    spatial/GeoSpatial3.cpp
    spatial/SimpleSpatial2.cpp
    spatial/SimpleSpatial3.cpp

    thread/AppThread.cpp
    thread/AudioThread.cpp
    thread/GameThread.cpp
    thread/IOThread.cpp
    thread/NetworkThread.cpp
    thread/SimThread.cpp
    thread/TaskThread.cpp
    thread/ViewerThread.cpp

    trigger/AndTrigger.cpp
    trigger/KeyPressTrigger.cpp
    trigger/NandTrigger.cpp
    trigger/NorTrigger.cpp
    trigger/NotTrigger.cpp
    trigger/OrTrigger.cpp
    trigger/PostTrigger.cpp

    tweak/OriginCameraTweak.cpp
    
    ui/UIAppMain.cpp
    ui/UIAppMainWriter.cpp
    ui/UIButton.cpp
    ui/UICallback.cpp
    ui/UICheckBox.cpp
    ui/UICheckBox_Simple.cpp
    ui/UICheckBox_Visible.cpp
    ui/UIDock.cpp
    ui/UIDocker.cpp
    ui/UIElement.cpp
    ui/UIElementWriter.cpp
    ui/UIElements.cpp
    ui/UIElementsWriter.cpp
    ui/UIGenerator.cpp
    ui/UIGroup.cpp
    ui/UIImage.cpp
    ui/UILayout.cpp
    ui/UILayoutWriter.cpp
    ui/UIMenu.cpp
    ui/UIMenuWriter.cpp
    ui/UIMenuBar.cpp
    ui/UIMenuBarWriter.cpp
    ui/UIMenuItem.cpp
    ui/UISection.cpp
    ui/UISimpleTree.cpp
    ui/UISpacer.cpp
    ui/UITextLabel.cpp
    ui/UIToolBar.cpp
    ui/UIToolBarWriter.cpp
    ui/UIUtils.cpp
    ui/UIWindow.cpp
    ui/UIWindowWriter.cpp

    ui/align/UICenterAlign.cpp
    ui/align/UIHLine.cpp
    ui/align/UIRightAlign.cpp

    ui/layout/UIHBoxLayout.cpp
    ui/layout/UIVBoxLayout.cpp
    
    utility/LoggerBox.cpp

    vulkan/vulqan.cpp
    vulkan/VulqanGPU.cpp
    vulkan/VulqanManager.cpp

    # vulkan/VqEnumerations.cpp
    vulkan/VqEnums.cpp
    vulkan/VqLogging.cpp
    vulkan/VqUtils.cpp

    vulkan/ViBuffer.cpp
    vulkan/ViCommandBuffer.cpp
    vulkan/ViCommandBufferVector.cpp
    vulkan/ViCommandPool.cpp
    vulkan/ViContext.cpp
    vulkan/ViData.cpp
    vulkan/ViDevice.cpp
    vulkan/ViFence.cpp
    vulkan/ViFrame.cpp
    vulkan/ViGui.cpp
    vulkan/ViImage.cpp
    vulkan/ViPipeline.cpp
    vulkan/ViPipelineLayout.cpp
    #vulkan/ViQueueManager.cpp
    vulkan/ViQueueTasker.cpp
    vulkan/ViRendered.cpp
    vulkan/ViRenderPass.cpp
    vulkan/ViSampler.cpp
    vulkan/ViShader.cpp
    vulkan/ViSurface.cpp
    vulkan/ViSwapchain.cpp
    vulkan/ViTexture.cpp
    vulkan/ViTasker.cpp
    vulkan/ViThread.cpp
    vulkan/ViVisualizer.cpp
    vulkan/Visualizer.cpp
        
    
    #widget/AbstractSceneWidgetHelper.cpp
    widget/AppWidget.cpp
    widget/CompositeWidget.cpp
    widget/FormWidget.cpp
    widget/FrameInspector.cpp
    widget/ImGuiDemoWidget.cpp
    #widget/LabelWidget.cpp
    widget/SceneWidget.cpp
    widget/SpaceCameraRemote.cpp
    widget/StackedWidget.cpp
    widget/TextArea.cpp
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
