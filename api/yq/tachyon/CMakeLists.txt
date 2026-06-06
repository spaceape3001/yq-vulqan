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
find_package(Vulkan 1.4 REQUIRED)

add_library(${PROJECT_NAME} SHARED
    #   Keep these sections in ALPHABETICAL order!
    ##  These are the "unity" build files
    
    api_camera.cpp
    api_dim.cpp
    api_light.cpp
    api_kinetic.cpp
    api_meta.cpp
    api_physics.cpp
    api_post.cpp
    api_rendered.cpp
    api_scene.cpp
    api_spatial.cpp

    aspect_count.cpp
    aspect_max_size.cpp
    aspect_min_size.cpp
    aspect_orientation.cpp
    aspect_position.cpp
    aspect_range.cpp
    aspect_scale.cpp
    aspect_size.cpp
    aspect_tessellation.cpp

    command_camera.cpp
    command_color.cpp
    command_color_profile.cpp
    command_controller.cpp
    command_count.cpp
    command_cursor.cpp
    command_file.cpp
    command_height_field.cpp
    command_light.cpp
    command_master.cpp
    command_material.cpp
    command_mesh.cpp
    #command_offset.cpp
    command_orientation.cpp
    command_position.cpp
    command_range.cpp
    command_rendered.cpp
    command_scale.cpp
    command_shape.cpp
    command_sim.cpp
    command_size.cpp
    command_spatial.cpp
    command_tachyon.cpp
    command_tessellation.cpp
    command_texture.cpp
    command_thread.cpp
    command_ui.cpp
    command_vertex.cpp
    command_viewer.cpp

    engine.cpp

    event_camera.cpp
    event_color.cpp
    event_count.cpp
    event_cursor.cpp
    event_gamepad.cpp
    event_joystick.cpp
    event_keyboard.cpp
    event_light.cpp
    event_master.cpp
    event_monitor.cpp
    event_mouse.cpp
    event_range.cpp
    event_sim.cpp
    event_spatial.cpp
    event_tachyon.cpp
    event_tessellation.cpp
    event_ui.cpp
    event_window.cpp
    
    gesture_file.cpp
    
    interface.cpp

    os.cpp
    os_glfw.cpp
    
    post.cpp
    
    proxy_count.cpp
    proxy_max_size.cpp
    proxy_min_size.cpp
    proxy_orientation.cpp
    proxy_position.cpp
    proxy_range.cpp
    proxy_scale.cpp
    proxy_size.cpp
    proxy_tessellation.cpp
    
    screen.cpp

    thread.cpp
    
    ui.cpp
    ui_align.cpp
    ui_input.cpp
    ui_layout.cpp
    ui_menu.cpp
    
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

    #api/1D.cpp
    #api/2D.cpp
    #api/3D.cpp
    api/Action.cpp
    api/CameraTweak.cpp
    api/Control.cpp
    api/Controller.cpp
    api/Delegate.cpp
    api/Domain.cpp
    #api/Editor.cpp
    api/Frame.cpp
    api/Gesture.cpp
    api/InterfaceMeta.cpp
    api/Layer.cpp
    api/Manager.cpp
    api/Math.cpp
    api/Mini.cpp
    api/Model.cpp
    #api/N.cpp
    api/Panel.cpp
    api/Payload.cpp
    api/Perspective.cpp
    api/Proxy.cpp
    api/Tachyon.cpp
    api/Tasker.cpp
    api/Thread.cpp
    #api/Tool.cpp
    api/Trigger.cpp
    api/TypedID.cpp
    api/Undo.cpp
    api/Widget.cpp
    
    app/Application.cpp
    app/Master.cpp
    app/Viewer.cpp
    app/VulqanConfig.cpp

    aspect/ABgColor.cpp
    aspect/AColor.cpp
    aspect/AColorProfile.cpp
    aspect/ADrawMode.cpp
    aspect/AFarPlane.cpp
    aspect/AFieldOfView.cpp
    aspect/AHeightField.cpp
    aspect/AMassKG.cpp
    aspect/AMaterial.cpp
    aspect/AMesh.cpp
    aspect/ANearPlane.cpp
    aspect/ARenderMode.cpp
    aspect/ASpatial3D.cpp
    aspect/ATexture.cpp
    aspect/ATopology.cpp
    aspect/AVertices3.cpp
        
    asset/AssetPak.cpp
    asset/CameraSpec.cpp
    #asset/GriddedData.cpp
    asset/HeightField.cpp
    asset/LightSpec.cpp
    asset/Material.cpp
    asset/Mesh.cpp
    asset/Raster.cpp
    asset/Sampler.cpp
    asset/Shader.cpp
    asset/Sound.cpp
    asset/Texture.cpp
    asset/Video.cpp

    asset/material/BasicMaterial.cpp

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
    command/MassCommand.cpp
    command/MouseCommand.cpp
    command/SceneCommand.cpp
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
    
    command/mass/AddMassGramCommand.cpp
    command/mass/AddMassKGCommand.cpp
    command/mass/MultiplyMassCommand.cpp
    command/mass/SetMassGramCommand.cpp
    command/mass/SetMassKGCommand.cpp

    command/widget/SetRenderModeCommand.cpp
    command/widget/SetViewer.cpp

    config/build.cpp

    
    data/Vertex3.cpp
    
    enum/UIFlags.cpp

    event/AppEvent.cpp
    event/EditorEvent.cpp
    event/EmptyEvent.cpp
    event/GestureEvent.cpp
    event/InputEvent.cpp
    event/IOEvent.cpp
    event/MassEvent.cpp
    event/MassGramEvent.cpp
    event/MassKGEvent.cpp
    event/OSEvent.cpp
    event/PanelEvent.cpp
    event/SetColorProfileEvent.cpp
    event/SetHeightFieldEvent.cpp
    event/SetMaterialEvent.cpp
    event/SetMeshEvent.cpp
    event/SetTextureEvent.cpp
    event/ShapeEvent.cpp
    event/ThreadEvent.cpp
    event/ViewerEvent.cpp
    event/VulqanEvent.cpp
    event/WidgetEvent.cpp

    event/thread/ThreadAddTachyonEvent.cpp
    event/vulqan/VulqanDebugEvent.cpp
    
    gesture/DragGesture.cpp
    
    im.cpp
    
    interface/IColorProfile.cpp
    interface/IHeightField.cpp
    interface/IMassKG.cpp
    interface/IMaterial.cpp
    interface/IMesh.cpp
    interface/ITexture.cpp
    
    io/CVPLoader.cpp
    io/GLSLShader.cpp
    io/GLTFLoader.cpp
    io/ImageHMV.cpp
    io/MaterialKV.cpp
    #io/MeshXML.cpp
    io/ObjLoader.cpp
    io/SamplerInfoFile.cpp
    io/STBImage.cpp
    io/Save.cpp
    io/SaveXML.cpp
    
    #io/builder/DelegateBuilder.cpp
    #io/builder/ObjectBuilder.cpp
    
    #io/Wavefront.cpp
    
    message/EmptyMessage.cpp

    pipeline/Buffer.cpp
    pipeline/Pipeline.cpp
    pipeline/PipelineUtils.cpp
    pipeline/RenderPass.cpp

    proxy/PBgColor.cpp
    proxy/PColor.cpp
    proxy/PColorProfile.cpp
    proxy/PDrawMode.cpp
    proxy/PFarPlane.cpp
    proxy/PFieldOfView.cpp
    proxy/PHeightField.cpp
    proxy/PMassKG.cpp
    proxy/PMaterial.cpp
    proxy/PMesh.cpp
    proxy/PNearPlane.cpp
    proxy/PRenderMode.cpp
    proxy/PTexture.cpp
    proxy/PTopology.cpp
    proxy/PVertices3.cpp
    
    raster/PatternRasters.cpp
    raster/DebugRasters.cpp 
    
    rendered/Shape3.cpp

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
    
    # request/app/OpenFileRequest.cpp
    # request/app/SaveFileRequest.cpp
    
    request/graphics_card/GetDeviceRequest.cpp
    
    request/io/LoadTSXRequest.cpp
    request/io/SaveRequest.cpp
    request/io/SaveTSXRequest.cpp

    
    request/ui/CloseRequest.cpp
    request/ui/RefreshRequest.cpp
    
    request/viewer/ViewerScreenshotRequest.cpp

    

    ui/UIAppMain.cpp
    ui/UICalc.cpp
    ui/UIDock.cpp
    ui/UIDocker.cpp
    ui/UIEditor.cpp
    ui/UIElement.cpp
    ui/UIElementWriter.cpp
    ui/UIElements.cpp
    ui/UIElementsWriter.cpp
    ui/UIGenerator.cpp
    ui/UIForm.cpp
    ui/UIImage.cpp
    ui/UILayout.cpp
    ui/UILayoutWriter.cpp
    #ui/UIPositioner.cpp    # TBD
    ui/UIUtils.cpp
    ui/UIWidget.cpp
    ui/UIWindow.cpp
    ui/UIWindowWriter.cpp

    ui/UIToolBar.cpp

    ui/calc/SnapLeftToOtherRightUICalc.cpp
    
    ui/input/UIInputBar.cpp
    ui/input/UILineInput.cpp

    ui/layout/UIPanel.cpp
    ui/layout/UITree.cpp

    utility/LoggerBox.cpp

    vulkan/VulqanGPU.cpp
    vulkan/VulqanManager.cpp

    # vulkan/VqEnumerations.cpp
    vulkan/VqEnums.cpp
    vulkan/VqUtils.cpp

    #vulkan/ViCommandBufferVector.cpp
    vulkan/ViData.cpp
    vulkan/ViDescriptorPool.cpp
    vulkan/ViDevice.cpp
    vulkan/ViFence.cpp
    vulkan/ViGui.cpp
    vulkan/ViGraphicsProcessor.cpp
    vulkan/ViHeadless.cpp
    vulkan/ViImage.cpp
    vulkan/ViPipeline.cpp
    vulkan/ViPipelineLayout.cpp
    vulkan/ViProcessor.cpp
    #vulkan/ViQueueManager.cpp
    vulkan/ViQueueTasker.cpp
    vulkan/ViRendered.cpp
    vulkan/ViSampler.cpp
    vulkan/ViSwapchain.cpp
    vulkan/ViTexture.cpp
    vulkan/ViTasker.cpp
    vulkan/ViThread.cpp
    vulkan/ViVisualizer.cpp
    vulkan/ViWorker.cpp
    vulkan/VizBase.cpp
    vulkan/metatypes.cpp
    
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
    TinyGLTF
    TinyOBJ
    STBImage 
    VulkanMemoryAllocator

    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 


PRIVATE
    ImGuiFileDialog
    stdc++exp
)


LinkTest(${PROJECT_NAME})

