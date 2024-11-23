################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)


find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    strings.cpp

    #glfw/GLFWManager.cpp
    
    MyImGui.cpp
    
    vulqan.cpp

    api/AppThread.cpp

    #api/Application.cpp
    api/Buffer.cpp
    api/Camera.cpp
    api/Command.cpp
    api/Context.hpp
    #api/Editor.cpp
    api/Event.cpp
    api/Frame.cpp
    api/Interface.hpp
    api/InterfaceInfo.hpp
    api/Light.cpp
    api/Manager.cpp
    api/Message.cpp
    api/Model.cpp
    api/Perspective.cpp
    api/Pipeline.cpp
    api/PipelineUtils.cpp
    api/Post.cpp
    api/Proxy.cpp
    api/Raster.cpp
    #api/Render2D.cpp
    api/Render3D.cpp
    api/Rendered.cpp
    api/RenderPass.cpp
    api/Reply.cpp
    api/Request.cpp
    api/Sampler.cpp
    api/Shader.cpp
    api/Tachyon.cpp
    api/Texture.cpp
    api/Thread.cpp
    #api/Tool.cpp
    api/Undo.cpp
    #api/Viewer.cpp
    api/Widget.cpp

    cameras/NullCamera.cpp
    cameras/SpaceCamera.cpp
    cameras/TargetCamera.cpp
    
    commands/commands.cpp

    
    config/build.cpp
    
    #controller/Controller.cpp
    #controllers/controllers.cpp
    
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    events/events.cpp
    
    # font/Font.cpp      # Issue/TODO
    
    # frame/AppFrame.cpp # Issue/TODO
    
    #glfw/GLFWManager.cpp
    glfw/Joystick.cpp
    glfw/Monitor.cpp
    glfw/VideoMode.cpp

    #interfaces/interfaces.cpp

    io/GLSLShader.cpp
    io/SamplerInfoFile.cpp
    #io/STBImage.cpp

    #manipulator/Manipulator.cpp
    
    messages/messages.cpp
    
    #models/models.cpp

    posts/AnyPost.cpp
    posts/EmptyPost.cpp
    posts/StringPost.cpp

    #proxies/proxies.cpp

    #renders/renders.cpp

    replies/replies.cpp
    
    
    requests/requests.cpp
    
    #task/Task.cpp
    #task/TaskEngine.cpp
    #tools/tools.cpp


    # v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    v/VqUtils.cpp
    v/VulqanManager.cpp
    
    viz/ViCommandBufferVector.cpp
    viz/ViData.cpp
    viz/ViFrame.cpp
    viz/ViPipeline.cpp
    viz/ViPipelineLayout.cpp
    viz/ViRendered.cpp
    viz/ViTasker.cpp
    viz/ViThread.cpp
    viz/ViVisualizer.cpp
    viz/Visualizer.cpp
    
    viz/viz.cpp
    
    #widgets/ImGuiDemoWidget.cpp
    #widgets/Scene3DWidget.cpp
    #widgets/StackedWidget.cpp
    #widgets/TextArea.cpp
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
