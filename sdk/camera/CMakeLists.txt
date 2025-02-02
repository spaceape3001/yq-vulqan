################################################################################
##
##  YOUR QUILL
##
################################################################################

add_executable(camera 
    CameraScene.cpp
    SpaceCameraRemote.cpp
    MainWidget.cpp
    main.cpp
)
target_link_libraries(camera yq_tachyon)
