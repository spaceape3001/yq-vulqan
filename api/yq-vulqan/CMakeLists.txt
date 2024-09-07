project(yqvulqan)


find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED
    errors.hpp
    logging.hpp
    
    asset/Asset.hpp
    asset/Asset.cpp
    asset/AssetCache.hpp
    asset/AssetCache.cpp
    asset/AssetFactory.hpp
    asset/AssetFactory.cpp
    asset/AssetInfoWriter.hpp
    asset/ImageAsset.hpp
    asset/ImageAsset.cpp
    asset/ShaderAsset.hpp
    asset/ShaderAsset.cpp
    
    basic/Required.hpp
    basic/Tristate.hpp
    basic/Tristate.cpp
    
    camera/Camera.hpp
    camera/Camera.cpp
    camera/NullCamera.hpp
    camera/NullCamera.cpp
    camera/SpaceCamera.hpp
    camera/SpaceCamera.cpp
    camera/TargetCamera.hpp
    camera/TargetCamera.cpp
    
    config/build.hpp
    config/build.cpp
    
    driver/STBImage.cpp
    
    glfw/AppGLFW.hpp
    glfw/AppGLFW.cpp
    glfw/Joystick.hpp
    glfw/Joystick.cpp
    glfw/Logging.hpp
    glfw/Monitor.hpp
    glfw/Monitor.cpp
    glfw/VideoMode.hpp
    glfw/VideoMode.cpp
    
    image/ComponentSwizzle.hpp
    image/ComponentSwizzle.cpp
    image/DataFormat.hpp
    image/DataFormat.cpp
    image/Image.hpp
    image/ImageAspect.hpp
    image/ImageAspect.cpp
    image/ImageInfo.hpp
    image/ImageLayout.hpp
    image/ImageLayout.cpp
    image/ImageTiling.hpp
    image/ImageTiling.cpp
    image/ImageType.hpp
    image/ImageType.cpp
    
    image_view/ImageViewCreateFlags.hpp
    image_view/ImageViewCreateFlags.cpp
    image_view/ImageViewInfo.hpp
    image_view/ImageViewType.hpp
    image_view/ImageViewType.cpp
    
    imgui/MyImGui.hpp
    imgui/MyImGui.cpp
    
    logic/CompareOp.hpp
    logic/CompareOp.cpp
    logic/LogicOp.hpp
    logic/LogicOp.cpp
    
    memory/Buffer.hpp
    memory/Buffer.cpp
    memory/BufferObject.hpp
    memory/BufferUsage.hpp
    memory/BufferUsage.cpp
    memory/Memory.hpp
    memory/Memory.cpp
    memory/SystemAllocationScope.hpp
    memory/SystemAllocationScope.cpp
    
    sampler/BorderColor.hpp
    sampler/BorderColor.cpp
    sampler/SamplerAddressMode.hpp
    sampler/SamplerAddressMode.cpp
    sampler/SamplerCreateFlags.hpp
    sampler/SamplerCreateFlags.cpp
    sampler/SamplerFilter.hpp
    sampler/SamplerFilter.cpp
    sampler/SamplerInfo.hpp
    sampler/SamplerMipmapMode.hpp
    sampler/SamplerMipmapMode.cpp
    
    scene/Perspective.hpp
    scene/Perspective.cpp

    shader/Shader.hpp
    shader/ShaderType.hpp
    shader/ShaderType.cpp
    
    undo/Undo.hpp
    undo/Undo.cpp
    
    widget/ImGuiDemoWidget.hpp
    widget/ImGuiDemoWidget.cpp
    widget/StackedWidget.hpp
    widget/StackedWidget.cpp
    widget/Widget.hpp
    widget/Widget.cpp
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
    yqtoolbox
    ${Vulkan_LIBRARIES} 
    ${GLFW3_LIBRARY} 
    imgui 
    stb 
    vma
)

LinkTest(${PROJECT_NAME})
