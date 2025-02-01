add_executable(camera 
    CameraController.cpp
    CameraScene.cpp
    CameraWidget.cpp
    camera.cpp
)
target_link_libraries(camera yq_tachyon)
