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

    #   ALPHABETICAL
    
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
    command/orientation/RotateBy3.cpp
    command/orientation/RollBy.cpp
    command/orientation/SetHeading.cpp
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

    enum/Cardinal.cpp


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

    msg/Command.cpp
    msg/Event.cpp
    msg/Message.cpp
    msg/Post.cpp
    msg/Reply.cpp
    msg/Request.cpp
    msg/Trigger.cpp
    

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
    
    reply/io/SaveReply.cpp
    
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
    
    request/io/SaveRequest.cpp
    
    request/ui/CloseRequest.cpp
    request/ui/RefreshRequest.cpp
    
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

    yt/enum/UIFlags.cpp

    # font/Font.cpp      # Issue/TODO



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

    yt/ui/Control.cpp
    #yt/ui/Editor.cpp
    yt/ui/ImWidget.cpp
    #yt/ui/Layout.cpp
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
    

    #######################################################
    #   Assets (Yes, the above will use some of these)

    ya/accessors/StringFunction.cpp
    ya/accessors/StringValue.cpp
    
    ya/actions/CallbackAction.cpp
    ya/actions/NullAction.cpp
    ya/actions/PostAction.cpp
    ya/actions/VisibleUIAction.cpp

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




    ya/controllers/Space3Controller.cpp

    ya/controls/Orientation3Control.cpp



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
    ya/uis/UIButton.cpp
    ya/uis/UIButtonBar.cpp
    ya/uis/UIButtonBarWriter.cpp
    ya/uis/UICallback.cpp
    ya/uis/UICenterAlign.cpp
    ya/uis/UICheckBox.cpp
    ya/uis/UICheckBox_Simple.cpp
    ya/uis/UICheckBox_Visible.cpp
    ya/uis/UIElements.cpp
    ya/uis/UIElementsWriter.cpp
    ya/uis/UIGenerator.cpp
    ya/uis/UIHBox.cpp
    ya/uis/UIHLine.cpp
    ya/uis/UIImage.cpp
    ya/uis/UILayout.cpp
    ya/uis/UILayoutWriter.cpp
    ya/uis/UIMenu.cpp
    ya/uis/UIMenuWriter.cpp
    ya/uis/UIMenuBar.cpp
    ya/uis/UIMenuBarWriter.cpp
    ya/uis/UIMenuItem.cpp
    ya/uis/UIRightAlign.cpp
    ya/uis/UISpacer.cpp
    ya/uis/UITextLabel.cpp
    ya/uis/UIWindow.cpp
    ya/uis/UIWindowWriter.cpp
    ya/uis/UIVBox.cpp
    
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
