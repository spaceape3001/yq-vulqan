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

    #GLFWManager.cpp
    
    MyImGui.cpp
    
    #vulqan.cpp

    api/System.cpp

    #api/Application.cpp
    api/Buffer.cpp
    #api/Camera.cpp
    api/Command.cpp
    #api/Editor.cpp
    api/Event.cpp
    api/Frame.cpp
    api/Interface.cpp
    #api/Light.cpp
    #api/Model.cpp
    #api/Manager.cpp
    api/Message.cpp
    #api/Perspective.cpp
    api/Pipeline.cpp
    api/PipelineUtils.cpp
    api/Post.cpp
    api/Raster.cpp
    #api/Render2D.cpp
    #api/Render3D.cpp
    #api/Rendered.cpp
    api/RenderPass.cpp
    api/Reply.cpp
    api/Request.cpp
    api/Sampler.cpp
    api/Shader.cpp
    #api/Tachyon.cpp
    api/Texture.cpp
    #api/Thread.cpp
    #api/Tool.cpp
    api/Undo.cpp
    
    
    #api/api.cpp
    
    
    commands/commands.cpp
    events/events.cpp
    #interfaces/interfaces.cpp
    #proxies/proxies.cpp


    #core/Controlling.cpp

    #cameras/cameras.cpp
    
    config/build.cpp
    
    #controller/Controller.cpp
    #controllers/controllers.cpp
    
    
    enum/enum.cpp
    enum/KeyCode.cpp
    enum/ModifierKey.cpp

    
    # font/Font.cpp      # Issue/TODO
    
    # frame/AppFrame.cpp # Issue/TODO
    
    #glfw/GLFWManager.cpp
    glfw/Joystick.cpp
    glfw/Monitor.cpp
    glfw/VideoMode.cpp

    io/GLSLShader.cpp
    io/SamplerInfoFile.cpp
    #io/STBImage.cpp

    #lights/lights.cpp

    #manipulator/Manipulator.cpp
    
    messages/messages.cpp
    
    #models/models.cpp
    
    #posts/posts.cpp

    #renders/renders.cpp

    replies/replies.cpp
    
    
    requests/requests.cpp


    #scene/Perspective.cpp
    
    
    #task/Task.cpp
    #task/TaskEngine.cpp

    #tools/tools.cpp


    # v/VqEnumerations.cpp
    v/VqEnums.cpp
    v/VqLogging.cpp
    #v/VqUtils.cpp
    #v/VulqanManager.cpp
    
    #viewer/viewer.cpp
    
    viz/ViCommandBufferVector.cpp
    viz/ViData.cpp
    viz/ViFrame.cpp
    viz/ViPipeline.cpp
    viz/ViPipelineLayout.cpp
    viz/ViRendered.cpp
    viz/ViTasker.cpp
    viz/ViThread.cpp
    #viz/ViVisualizer.cpp
    #viz/Visualizer.cpp
    
    viz/viz.cpp
    
    #widget/Widget.cpp
    
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
