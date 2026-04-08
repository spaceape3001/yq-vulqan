################################################################################
##
##  YOUR QUILL
##
################################################################################

project(yq_tedit)


find_package(Qt6 REQUIRED Core Gui PrintSupport Widgets )

SET(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
    TEDocument.cpp
    #TEDocument.hpp
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
    #TEViewer.hpp
    
    app/TEApp.cpp
    app/TEAppThread.cpp
    app/TEAppThread.hpp

    

    xrs/MCamera.cpp
    xrs/MCamera.hpp
    xrs/MCamera3.cpp
    xrs/MCamera3.hpp
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
    xrs/MKinetic3.cpp
    xrs/MKinetic3.hpp
    xrs/MLayer.cpp
    xrs/MLayer.hpp
    xrs/MLight.cpp
    xrs/MLight.hpp
    xrs/MLight3.cpp
    xrs/MLight3.hpp
    xrs/MManager.cpp
    xrs/MManager.hpp
    xrs/MModel.cpp
    xrs/MModel.hpp
    xrs/MPhysics.cpp
    xrs/MPhysics.hpp
    xrs/MRendered.cpp
    xrs/MRendered.hpp
    xrs/MRendered3.cpp
    xrs/MRendered3.hpp
    xrs/MScene.cpp
    xrs/MScene.hpp
    xrs/MScene3.cpp
    xrs/MScene3.hpp
    xrs/MSpatial.cpp
    xrs/MSpatial.hpp
    xrs/MSpatial3.cpp
    xrs/MSpatial3.hpp
    xrs/MTachyon.cpp
    xrs/MTachyon.hpp
    xrs/MThread.cpp
    xrs/MThread.hpp
    xrs/MViewer.cpp
    xrs/MViewer.hpp
    xrs/MWidget.cpp
    xrs/MWidget.hpp
    xrs/MWindow.cpp
    xrs/MWindow.hpp
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    yq_vkqt
    yq_assetvk
)

LinkTest(${PROJECT_NAME})

