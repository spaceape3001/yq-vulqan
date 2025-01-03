################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tachyon)

#   SUPERSCRIPTS ⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ʰ ᵖ ⁿ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ

find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

set(VULKAN_DIR $ENV{VULKAN_SDK})
find_package(Vulkan REQUIRED)

add_library(${PROJECT_NAME} SHARED

    #glfw/GLFWManager.cpp
    
    

    api/Controller.cpp
    #api/Context.hpp
    api/Frame.cpp
    api/InterfaceInfo.cpp
    api/Manager.cpp
    api/Proxy.cpp
    api/Tachyon.cpp
    api/Thread.cpp
    api/TypedID.cpp

    app/Application.cpp
    app/AppThread.cpp
    app/TaskThread.cpp
    app/Viewer.cpp
    app/ViewerThread.cpp

    cameras/NullCamera.cpp
    cameras/SpaceCamera.cpp
    cameras/TargetCamera.cpp


    #manipulator/Manipulator.cpp
    
    
    #models/models.cpp

    renders/ImageQuad.cpp
    renders/Quadrilateral.cpp
    renders/Tetrahedron.cpp
    renders/Triangle.cpp

    
    #task/Task.cpp
    #task/TaskEngine.cpp
    #tools/tools.cpp
    
    
    widgets/ImGuiDemoWidget.cpp
    widgets/Scene3DWidget.cpp
    widgets/StackedWidget.cpp
    widgets/TextArea.cpp
)


target_compile_definitions(${PROJECT_NAME} 
    PUBLIC
        GLFW_INCLUDE_VULKAN=1
        YQ_USE_GLM=1
    PRIVATE 
        VK_ENABLE_BETA_EXTENSIONS=1
        DONT_DEFINE_AGAIN__STB_IMAGE_IMPLEMENTATION=1
        DONT_DEFINE_AGAIN__STB_IMAGE_RESIZE_IMPLEMENTATION=1
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ../../../lib/tachyon/public
    ${VULQAN_API_DIR}
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC 
    yq_tachyon2
)

LinkTest(${PROJECT_NAME})

