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
    
    
    3D/Camera3.cpp
    3D/Light3.cpp
    3D/Rendered3.cpp
    3D/Scene3.cpp
    3D/Spatial3.cpp

    api/Controller.cpp
    #api/Context.hpp
    api/Frame.cpp
    api/InterfaceInfo.cpp
    api/Manager.cpp
    api/Model.cpp
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

    events/AppEvent.cpp
    events/CameraEvent.cpp
    events/EmptyEvent.cpp
    events/InputEvent.cpp
    #events/JoystickAxisEvent.cpp
    #events/JoystickConnectEvent.cpp
    #events/JoystickDisconnectEvent.cpp
    #events/JoystickEvent.cpp
    #events/JoystickHatEvent.cpp
    #events/JoystickPressEvent.cpp
    #events/JoystickReleaseEvent.cpp
    events/KeyboardEvent.cpp
    events/KeyCharacterEvent.cpp
    events/KeyPressEvent.cpp
    events/KeyReleaseEvent.cpp
    events/KeyRepeatEvent.cpp
    #events/MonitorConnectEvent.cpp
    #events/MonitorDisconnectEvent.cpp
    #events/MonitorEvent.cpp
    events/MouseCaptureEvent.cpp
    events/MouseDisableEvent.cpp
    events/MouseDropEvent.cpp
    events/MouseEnterEvent.cpp
    events/MouseEvent.cpp
    events/MouseHideEvent.cpp
    events/MouseLeaveEvent.cpp
    events/MouseMoveEvent.cpp
    events/MouseNormalEvent.cpp
    events/MousePressEvent.cpp
    events/MouseReleaseEvent.cpp
    events/MouseScrollEvent.cpp
    events/TachyonEvent.cpp
    events/ThreadEvent.cpp
    events/ThreadAddTachyonEvent.cpp
    events/ViewerCloseEvent.cpp
    events/ViewerDestroyEvent.cpp
    events/ViewerEvent.cpp
    events/ViewerPauseEvent.cpp
    events/ViewerResumeEvent.cpp
    events/ViewerTickEvent.cpp
    events/VulqanEvent.cpp
    events/WidgetEvent.cpp
    events/WindowAspectEvent.cpp
    events/WindowCursorCaptureEvent.cpp
    events/WindowCursorDisableEvent.cpp
    events/WindowCursorHideEvent.cpp
    events/WindowCursorNormalEvent.cpp
    events/WindowDefocusEvent.cpp
    events/WindowDestroyEvent.cpp
    events/WindowEvent.cpp
    events/WindowFocusEvent.cpp
    events/WindowFrameBufferResizeEvent.cpp
    events/WindowHideEvent.cpp
    events/WindowIconifyEvent.cpp
    events/WindowMaximizeEvent.cpp
    events/WindowMoveEvent.cpp
    events/WindowResizeEvent.cpp
    events/WindowRestoreEvent.cpp
    events/WindowScaleEvent.cpp
    events/WindowShowEvent.cpp
    events/WindowTitleEvent.cpp
    

    #manipulator/Manipulator.cpp
    
    
    #models/models.cpp

    renders/ImageQuad.cpp
    renders/Quadrilateral.cpp
    renders/Tetrahedron.cpp
    renders/Triangle.cpp

    replies/AnyReply.cpp
    replies/AppReply.cpp
    replies/CameraReply.cpp
    replies/EmptyReply.cpp
    replies/StringReply.cpp
    replies/TachyonReply.cpp
    replies/ViewerCloseReply.cpp
    replies/ViewerReply.cpp
    replies/ViewerWidgetReply.cpp
    replies/WindowReply.cpp
    
    requests/AppRequest.cpp
    requests/CameraRequest.cpp
    requests/EmptyRequest.cpp
    requests/TachyonRequest.cpp
    requests/ViewerCloseRequest.cpp
    requests/ViewerRequest.cpp
    #requests/ViewerWidgetRequest.cpp
    requests/WindowCloseRequest.cpp
    requests/WindowRefreshRequest.cpp
    requests/WindowRequest.cpp

    scene/Camera.cpp
    scene/Light.cpp
    scene/Perspective.cpp
    scene/Rendered.cpp
    #scene/Rendered2.cpp
    scene/Scene.cpp
    #scene/Scene2.cpp
    scene/Spatial.cpp

    
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

