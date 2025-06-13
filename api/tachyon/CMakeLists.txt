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

    aspect/AColor.cpp
    aspect/ADrawMode.cpp
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
    aspect/AVertices3.cpp
        
    camera/NullCamera.cpp
    camera/SpaceCamera.cpp
    camera/TargetCamera.cpp

    command/AddChildCommand.cpp
    command/AppCommand.cpp
    command/AppDeleteViewerCommand.cpp
    command/CameraCommand.cpp
    command/ColorCommand.cpp
    command/ControllerCommand.cpp
    command/CursorCommand.cpp
    command/EmptyCommand.cpp
    command/GamepadCommand.cpp
    command/GLFWCommand.cpp
    command/IOCommand.cpp
    command/JoystickCommand.cpp
    command/LightCommand.cpp
    command/MouseCommand.cpp
    command/SceneCommand.cpp
    command/ShapeCommand.cpp
    command/SimCommand.cpp
    command/SpatialCommand.cpp
    command/TachyonCommand.cpp
    command/ThreadCommand.cpp
    command/UICommand.cpp
    command/VertexCommand.cpp
    command/ViewerCommand.cpp
    command/WidgetCommand.cpp
    command/WindowCommand.cpp
    
    command/aabb/SetAABB1.cpp
    command/aabb/SetAABB2.cpp
    command/aabb/SetAABB3.cpp
    command/aabb/SetAABB4.cpp
    
    command/camera/CameraSetScreen.cpp

    command/color/SetBgColorCommand.cpp
    command/color/SetColorCommand.cpp

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

    command/orientation/PitchByCommand.cpp
    command/orientation/RotateBy2Command.cpp
    command/orientation/RotateBy3Command.cpp
    command/orientation/RollByCommand.cpp
    command/orientation/SetHeadingCommand.cpp
    command/orientation/SetOrientation2Command.cpp
    command/orientation/SetOrientation3Command.cpp
    command/orientation/SetPitchCommand.cpp
    command/orientation/SetRollCommand.cpp
    command/orientation/YawByCommand.cpp

    command/position/AddPosition1Command.cpp
    command/position/AddPosition2Command.cpp
    command/position/AddPosition3Command.cpp
    command/position/AddPosition4Command.cpp
    command/position/AddPositionWCommand.cpp
    command/position/AddPositionXCommand.cpp
    command/position/AddPositionYCommand.cpp
    command/position/AddPositionZCommand.cpp
    command/position/MoveBy1Command.cpp
    command/position/MoveBy2Command.cpp
    command/position/MoveBy3Command.cpp
    command/position/MoveBy4Command.cpp
    command/position/MoveByWCommand.cpp
    command/position/MoveByXCommand.cpp
    command/position/MoveByYCommand.cpp
    command/position/MoveByZCommand.cpp
    command/position/MultiplyPositionCommand.cpp
    command/position/MultiplyPosition1Command.cpp
    command/position/MultiplyPosition2Command.cpp
    command/position/MultiplyPosition3Command.cpp
    command/position/MultiplyPosition4Command.cpp
    command/position/MultiplyPositionWCommand.cpp
    command/position/MultiplyPositionXCommand.cpp
    command/position/MultiplyPositionYCommand.cpp
    command/position/MultiplyPositionZCommand.cpp
    command/position/SetPosition1Command.cpp
    command/position/SetPosition2Command.cpp
    command/position/SetPosition3Command.cpp
    command/position/SetPosition4Command.cpp
    command/position/SetPositionWCommand.cpp
    command/position/SetPositionXCommand.cpp
    command/position/SetPositionYCommand.cpp
    command/position/SetPositionZCommand.cpp
    command/position/SetVertexPosition3Command.cpp

    command/scale/AddScale1Command.cpp
    command/scale/AddScale2Command.cpp
    command/scale/AddScale3Command.cpp
    command/scale/AddScaleXCommand.cpp
    command/scale/AddScaleYCommand.cpp
    command/scale/AddScaleZCommand.cpp
    command/scale/MultiplyScaleCommand.cpp
    command/scale/MultiplyScale1Command.cpp
    command/scale/MultiplyScale2Command.cpp
    command/scale/MultiplyScale3Command.cpp
    command/scale/MultiplyScaleXCommand.cpp
    command/scale/MultiplyScaleYCommand.cpp
    command/scale/MultiplyScaleZCommand.cpp
    command/scale/SetScale1Command.cpp
    command/scale/SetScale2Command.cpp
    command/scale/SetScale3Command.cpp
    command/scale/SetScaleXCommand.cpp
    command/scale/SetScaleYCommand.cpp
    command/scale/SetScaleZCommand.cpp

    command/shape/SetDrawModeCommand.cpp

    command/size/AddMaxSize1Command.cpp
    command/size/AddMaxSize2Command.cpp
    command/size/AddMaxSize3Command.cpp
    command/size/AddMaxSize4Command.cpp
    command/size/AddMaxSizeWCommand.cpp
    command/size/AddMaxSizeXCommand.cpp
    command/size/AddMaxSizeYCommand.cpp
    command/size/AddMaxSizeZCommand.cpp
    command/size/AddMinSize1Command.cpp
    command/size/AddMinSize2Command.cpp
    command/size/AddMinSize3Command.cpp
    command/size/AddMinSize4Command.cpp
    command/size/AddMinSizeWCommand.cpp
    command/size/AddMinSizeXCommand.cpp
    command/size/AddMinSizeYCommand.cpp
    command/size/AddMinSizeZCommand.cpp
    command/size/AddSize1Command.cpp
    command/size/AddSize2Command.cpp
    command/size/AddSize3Command.cpp
    command/size/AddSize4Command.cpp
    command/size/AddSizeWCommand.cpp
    command/size/AddSizeXCommand.cpp
    command/size/AddSizeYCommand.cpp
    command/size/AddSizeZCommand.cpp
    command/size/MultiplyMaxSizeCommand.cpp
    command/size/MultiplyMaxSize1Command.cpp
    command/size/MultiplyMaxSize2Command.cpp
    command/size/MultiplyMaxSize3Command.cpp
    command/size/MultiplyMaxSize4Command.cpp
    command/size/MultiplyMaxSizeWCommand.cpp
    command/size/MultiplyMaxSizeXCommand.cpp
    command/size/MultiplyMaxSizeYCommand.cpp
    command/size/MultiplyMaxSizeZCommand.cpp
    command/size/MultiplyMinSizeCommand.cpp
    command/size/MultiplyMinSize1Command.cpp
    command/size/MultiplyMinSize2Command.cpp
    command/size/MultiplyMinSize3Command.cpp
    command/size/MultiplyMinSize4Command.cpp
    command/size/MultiplyMinSizeWCommand.cpp
    command/size/MultiplyMinSizeXCommand.cpp
    command/size/MultiplyMinSizeYCommand.cpp
    command/size/MultiplyMinSizeZCommand.cpp
    command/size/MultiplySizeCommand.cpp
    command/size/MultiplySize1Command.cpp
    command/size/MultiplySize2Command.cpp
    command/size/MultiplySize3Command.cpp
    command/size/MultiplySize4Command.cpp
    command/size/MultiplySizeWCommand.cpp
    command/size/MultiplySizeXCommand.cpp
    command/size/MultiplySizeYCommand.cpp
    command/size/MultiplySizeZCommand.cpp
    command/size/SetMaxSize1Command.cpp
    command/size/SetMaxSize2Command.cpp
    command/size/SetMaxSize3Command.cpp
    command/size/SetMaxSize4Command.cpp
    command/size/SetMaxSizeWCommand.cpp
    command/size/SetMaxSizeXCommand.cpp
    command/size/SetMaxSizeYCommand.cpp
    command/size/SetMaxSizeZCommand.cpp
    command/size/SetMinSize1Command.cpp
    command/size/SetMinSize2Command.cpp
    command/size/SetMinSize3Command.cpp
    command/size/SetMinSize4Command.cpp
    command/size/SetMinSizeWCommand.cpp
    command/size/SetMinSizeXCommand.cpp
    command/size/SetMinSizeYCommand.cpp
    command/size/SetMinSizeZCommand.cpp
    command/size/SetSize1Command.cpp
    command/size/SetSize2Command.cpp
    command/size/SetSize3Command.cpp
    command/size/SetSize4Command.cpp
    command/size/SetSizeWCommand.cpp
    command/size/SetSizeXCommand.cpp
    command/size/SetSizeYCommand.cpp
    command/size/SetSizeZCommand.cpp
    
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

    command/vertex/AppendVertex3Command.cpp
    command/vertex/EraseVertexCommand.cpp
    command/vertex/InsertVertex3Command.cpp
    command/vertex/SetVertex3Command.cpp
    command/vertex/SetVertexColorCommand.cpp
    command/vertex/SetVertexNormal2Command.cpp
    command/vertex/SetVertexNormal3Command.cpp
    command/vertex/SetVertexPoint2Command.cpp
    command/vertex/SetVertexPoint3Command.cpp
    command/vertex/SetVertexUVCommand.cpp
    command/vertex/SetVertexUVWCommand.cpp

    command/viewer/SetWidgetCommand.cpp
    
    command/widget/SetViewer.cpp

    config/build.cpp

    control/Orientation3Control.cpp

    controller/Space3Controller.cpp
    
    data/Vertex3.cpp
    
    edit/DrawModeUI.cpp
    edit/Orientation3UI.cpp
    edit/Position2UI.cpp
    edit/Position3UI.cpp
    edit/Position4UI.cpp
    edit/Scale3UI.cpp
    edit/SceneUI.cpp
    edit/SimpleSpatial3UI.cpp
    edit/SkyBox3UI.cpp
    edit/TachyonUI.cpp

    enum/Cardinal.cpp
    enum/UIFlags.cpp


    event/AppEvent.cpp
    event/CameraEvent.cpp
    event/ColorEvent.cpp
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
    event/PanelEvent.cpp
    event/SimEvent.cpp
    event/SpatialEvent.cpp
    event/TachyonEvent.cpp
    event/ThreadEvent.cpp
    event/UIEvent.cpp
    event/ViewerEvent.cpp
    event/VulqanEvent.cpp
    event/WidgetEvent.cpp
    event/WindowEvent.cpp
    
    event/color/ColorChangeEvent.cpp
    
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

    event/panel/InfoSelectionChangedEvent.cpp

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

    interface/IColor.cpp
    interface/IDrawMode.cpp
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
    interface/IVertices3.cpp
    
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
    
    panel/UIConcreteInfoList.cpp
    panel/UIInfoList.cpp

    post/AnyPost.cpp
    post/EmptyPost.cpp
    post/StringPost.cpp

    proxy/PColor.cpp
    proxy/PDrawMode.cpp
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
    proxy/PVertices3.cpp
    
    raster/PatternRasters.cpp
    raster/DebugRasters.cpp

    rendered/AbstractShape3.cpp
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
    scene/CompositeScene.cpp
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
    ui/UIEditor.cpp
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
