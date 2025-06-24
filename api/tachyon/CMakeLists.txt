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

    aspect/ABgColor.cpp
    aspect/AColor.cpp
    aspect/ADrawMode.cpp
    aspect/AFarPlane.cpp
    aspect/AFieldOfView.cpp
    aspect/AMaxSize1.cpp
    aspect/AMaxSize2.cpp
    aspect/AMaxSize3.cpp
    aspect/AMaxSize4.cpp
    aspect/AMinSize1.cpp
    aspect/AMinSize2.cpp
    aspect/AMinSize3.cpp
    aspect/AMinSize4.cpp
    aspect/ANearPlane.cpp
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
    command/EditorCommand.cpp
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
    
    command/camera/camera_commands.cpp

    command/color/SetBgColorCommand.cpp
    command/color/SetColorCommand.cpp

    command/controller/ControlCommand.cpp
    command/controller/DisableCommand.cpp
    command/controller/EnableCommand.cpp
    command/controller/ListenCommand.cpp
    command/controller/SetTargetCommand.cpp
    command/controller/UncontrolCommand.cpp
    command/controller/UnlistenCommand.cpp

    command/cursor/CursorCaptureCommand.cpp
    command/cursor/CursorDisableCommand.cpp
    command/cursor/CursorHideCommand.cpp
    command/cursor/CursorNormalCommand.cpp

    command/gamepad/GamepadZeroCommand.cpp
    
    command/generic/SetSpatialCommand.cpp

    command/io/SaveCommand.cpp

    command/joystick/JoystickZeroCommand.cpp

    command/sim/ResumeCommand.cpp
    command/sim/PauseCommand.cpp

    command/orientation/orientation_commands.cpp

    command/position/position_commands.cpp

    command/scale/scale_commands.cpp

    command/shape/SetDrawModeCommand.cpp

    command/size/size_commands.cpp
    
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

    command/vertex/vertex_commands.cpp

    command/viewer/ImGuiDisableKeyboardCommand.cpp
    command/viewer/ImGuiEnableKeyboardCommand.cpp
    command/viewer/ImGuiDisableMouseCommand.cpp
    command/viewer/ImGuiEnableMouseCommand.cpp
    command/viewer/SetWidgetCommand.cpp
    
    command/widget/SetViewer.cpp

    config/build.cpp

    control/Orientation3Control.cpp

    controller/Space3Controller.cpp
    
    data/Vertex3.cpp
    
    edit/BgColorUI.cpp
    edit/ColorUI.cpp
    edit/DrawModeUI.cpp
    edit/FarPlaneUI.cpp
    edit/FieldOfViewUI.cpp
    edit/NearPlaneUI.cpp
    edit/Orientation3UI.cpp
    edit/Position2UI.cpp
    edit/Position3UI.cpp
    edit/Position4UI.cpp
    edit/Scale3UI.cpp
    edit/SceneUI.cpp
    edit/SimpleSpatial3UI.cpp
    edit/SkyBox3UI.cpp
    edit/TachyonUI.cpp
    edit/Vertices3UI.cpp

    enum/Cardinal.cpp
    enum/UIFlags.cpp


    event/AppEvent.cpp
    event/CameraEvent.cpp
    event/ColorEvent.cpp
    event/CursorEvent.cpp
    event/EditorEvent.cpp
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
    
    event/color/BgColorChangeEvent.cpp
    event/color/ColorChangeEvent.cpp
    
    event/cursor/CursorCaptureEvent.cpp
    event/cursor/CursorDisableEvent.cpp
    event/cursor/CursorHideEvent.cpp
    event/cursor/CursorNormalEvent.cpp
    
    event/gamepad/gamepad_events.cpp

    event/joystick/joystick_events.cpp

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

    event/spatial/spatial_events.cpp
    
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

    interface/IFarPlane.cpp
    interface/IFieldOfView.cpp
    interface/INearPlane.cpp
    interface/interfaces.cpp
    
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
    
    menu/CreateMenuUI.cpp

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

    os/glfw/glfw.cpp

    panel/FrameMetricsUI.cpp
    panel/UIConcreteInfoList.cpp
    panel/UIInfoList.cpp

    post/AnyPost.cpp
    post/EmptyPost.cpp
    post/StringPost.cpp

    proxy/PBgColor.cpp
    proxy/PColor.cpp
    proxy/PDrawMode.cpp
    proxy/PFarPlane.cpp
    proxy/PFieldOfView.cpp
    proxy/PMaxSize1.cpp
    proxy/PMaxSize2.cpp
    proxy/PMaxSize3.cpp
    proxy/PMaxSize4.cpp
    proxy/PMinSize1.cpp
    proxy/PMinSize2.cpp
    proxy/PMinSize3.cpp
    proxy/PMinSize4.cpp
    proxy/PNearPlane.cpp
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
    rendered/ColorTetrahedron3.cpp
    rendered/ColorTriangle3.cpp
    rendered/GradTetrahedron3.cpp
    rendered/GradTriangle3.cpp
    rendered/ImageQuad3.cpp
    rendered/Quadrilateral3.cpp
    rendered/SkyBox3.cpp
    rendered/Tetrahedron3.cpp
    rendered/Triangle3.cpp

    reply/AnyReply.cpp
    reply/AppReply.cpp
    reply/CameraReply.cpp
    reply/EditorReply.cpp
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
    
    reply/viewer/ViewerScreenshotReply.cpp
    
    request/AppRequest.cpp
    request/CameraRequest.cpp
    request/EditorRequest.cpp
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
    
    request/viewer/ViewerScreenshotRequest.cpp

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
    thread/AuxillaryThread.cpp
    thread/EditThread.cpp
    thread/GameThread.cpp
    thread/IOThread.cpp
    thread/NetworkThread.cpp
    thread/SimThread.cpp
    thread/TaskThread.cpp
    thread/ViewerThread.cpp

    trigger/triggers.cpp

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
    ui/UIForm.cpp
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
