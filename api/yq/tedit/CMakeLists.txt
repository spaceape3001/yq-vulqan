################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tedit)


find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    TEApp.cpp
    TEAppThread.cpp
    TEAppThread.hpp
    TEDoc.cpp
    TEDoc.hpp
    TEEditor.cpp
    TEEditor.hpp
    TEManager.cpp
    TEManager.hpp
    TEViewCtrl.cpp
    TEViewCtrl.hpp
    TEViewCtrlBox.cpp
    TEViewCtrlBox.hpp
    TEViewCtrlDock.cpp
    TEViewCtrlDock.hpp
    TEViewer.cpp
    TEViewer.hpp
    
    xrs/MCamera.cpp
    xrs/MCamera.hpp
    xrs/MCompositeWidget.cpp
    xrs/MCompositeWidget.hpp
    xrs/MController.cpp
    xrs/MController.hpp
    xrs/MDomain.cpp
    xrs/MDomain.hpp
    #xrs/MGroup.cpp
    #xrs/MGroup.hpp
    xrs/MKinetic.cpp
    xrs/MKinetic.hpp
    xrs/MLayer.cpp
    xrs/MLayer.hpp
    xrs/MLight.cpp
    xrs/MLight.hpp
    xrs/MManager.cpp
    xrs/MManager.hpp
    xrs/MModel.cpp
    xrs/MModel.hpp
    xrs/MPhysics.cpp
    xrs/MPhysics.hpp
    xrs/MRendered.cpp
    xrs/MRendered.hpp
    xrs/MScene.cpp
    xrs/MScene.hpp
    xrs/MSpatial.cpp
    xrs/MSpatial.hpp
    xrs/MTachyon.cpp
    xrs/MTachyon.hpp
    xrs/MThread.cpp
    xrs/MThread.hpp
    xrs/MViewer.cpp
    xrs/MViewer.hpp
    xrs/MWidget.cpp
    xrs/MWidget.hpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
    yq_assetvk
)
