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
    #   Keep these sections in ALPHABETICAL order!
    ##  These are the "unity" build files
    
    api_meta.cpp

    command_camera.cpp
    command_color.cpp
    command_controller.cpp
    command_cursor.cpp
    command_orientation.cpp
    command_position.cpp
    command_rendered.cpp
    command_scale.cpp
    command_sim.cpp
    command_size.cpp
    command_spatial.cpp
    command_tachyon.cpp
    command_ui.cpp
    command_vertex.cpp
    command_viewer.cpp

    event_color.cpp
    event_cursor.cpp
    event_gamepad.cpp
    event_joystick.cpp
    event_keyboard.cpp
    event_monitor.cpp
    event_mouse.cpp
    event_sim.cpp
    event_spatial.cpp
    event_tachyon.cpp
    event_ui.cpp
    event_window.cpp
    
    interface.cpp

    os.cpp
    os_glfw.cpp
    
    post.cpp

    thread.cpp
    
    ui.cpp
    ui_align.cpp
    
    vulkan.cpp

    ## And individual files 

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
    api/InterfaceMeta.cpp
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
        
    asset/AssetPack.cpp
    asset/CameraSpec.cpp
    asset/LightSpec.cpp
    asset/Material.cpp
    asset/Mesh.cpp
    asset/Raster.cpp
    asset/Sampler.cpp
    asset/Shader.cpp
    asset/Sound.cpp
    asset/Texture.cpp
    asset/Video.cpp

    camera/NullCamera.cpp

    command/AddChildCommand.cpp
    command/AppCommand.cpp
    command/AppDeleteViewerCommand.cpp
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
    command/ThreadCommand.cpp
    command/WidgetCommand.cpp
    command/WindowCommand.cpp
    
    command/aabb/SetAABB1.cpp
    command/aabb/SetAABB2.cpp
    command/aabb/SetAABB3.cpp
    command/aabb/SetAABB4.cpp
    
    command/app/ViewerCreateCommand.cpp
    command/gamepad/GamepadZeroCommand.cpp
    command/generic/SetSpatialCommand.cpp
    command/io/SaveCommand.cpp
    command/joystick/JoystickZeroCommand.cpp
    command/shape/SetDrawModeCommand.cpp
    command/thread/ScheduleCommand.cpp
    command/widget/SetViewer.cpp

    config/build.cpp

    
    data/Vertex3.cpp
    

    enum/Cardinal.cpp
    enum/UIFlags.cpp

    event/AppEvent.cpp
    event/CameraEvent.cpp
    event/EditorEvent.cpp
    event/EmptyEvent.cpp
    event/InputEvent.cpp
    event/IOEvent.cpp
    event/OSEvent.cpp
    event/PanelEvent.cpp
    event/ThreadEvent.cpp
    event/ViewerEvent.cpp
    event/VulqanEvent.cpp
    event/WidgetEvent.cpp

    event/thread/ThreadAddTachyonEvent.cpp
    
    im/KVTable.cpp
    
    interface/IFarPlane.cpp
    interface/IFieldOfView.cpp
    interface/INearPlane.cpp
    
    io/FileIOManager.cpp
    io/GLSLShader.cpp
    io/GLTFLoader.cpp
    #io/MeshXML.cpp
    io/ObjLoader.cpp
    io/SamplerInfoFile.cpp
    io/STBImage.cpp
    io/Save.cpp
    
    #io/Wavefront.cpp

    io/save/SaveDelegate.cpp
    io/save/SaveObject.cpp
    io/save/SaveResource.cpp
    io/save/SaveTachyon.cpp
    io/save/SaveThread.cpp
    io/save/SaveXML.cpp
    
    message/EmptyMessage.cpp

    pipeline/Buffer.cpp
    pipeline/Pipeline.cpp
    pipeline/PipelineUtils.cpp
    pipeline/RenderPass.cpp

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

    
    #   This one can't tag along with the move as it's used in the 3D (above)
    spatial/SimpleSpatial3.cpp

    ui/UIAppMain.cpp
    ui/UIAppMainWriter.cpp
    ui/UICalc.cpp
    ui/UIDock.cpp
    ui/UIDocker.cpp
    ui/UIEditor.cpp
    ui/UIElement.cpp
    ui/UIElementWriter.cpp
    ui/UIElements.cpp
    ui/UIElementsWriter.cpp
    ui/UIForm.cpp
    ui/UIGenerator.cpp
    ui/UIImage.cpp
    ui/UIInputBar.cpp
    ui/UILayout.cpp
    ui/UILayoutWriter.cpp
    ui/UILineInput.cpp
    #ui/UIPositioner.cpp    # TBD
    ui/UIToolBar.cpp
    ui/UIToolBarWriter.cpp
    ui/UIUtils.cpp
    ui/UIWindow.cpp
    ui/UIWindowWriter.cpp
    
    ui/calc/SnapLeftToOtherRightUICalc.cpp

    ui/layout/UIHBoxLayout.cpp
    ui/layout/UIVBoxLayout.cpp

    
    utility/LoggerBox.cpp

    vulkan/VulqanGPU.cpp
    vulkan/VulqanManager.cpp

    # vulkan/VqEnumerations.cpp
    vulkan/VqEnums.cpp
    vulkan/VqUtils.cpp

    vulkan/ViCommandBuffer.cpp
    vulkan/ViCommandBufferVector.cpp
    vulkan/ViCommandPool.cpp
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
    vulkan/ViSwapchain.cpp
    vulkan/ViTexture.cpp
    vulkan/ViTasker.cpp
    vulkan/ViThread.cpp
    vulkan/ViVisualizer.cpp
    vulkan/Visualizer.cpp
        
    
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
PRIVATE
    ${LUA_INCLUDE_DIR}
)


target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_resource
    yq_color
    yq_keyv
    yq_lua
    yq_math
    yq_process
    yq_raster
    yq_text
    yq_xml

    ImGui
    STBImage 
    TinyGLTF
    TinyOBJ
    VulkanMemoryAllocator

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
)


LinkTest(${PROJECT_NAME})

