add_executable(camera 
    CameraController.cpp
    CameraScene.cpp
    MainWidget.cpp
    main.cpp
)
target_link_libraries(camera yq_tachyon)
