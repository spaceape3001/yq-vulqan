################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_assetvk SHARED
    camera/SpaceCamera.cpp
    
    controller/Space3Controller.cpp

    edit/SkyBox3UI.cpp

        #   TODO... unify the color/grad in a way that makes sense (and won't be terribly confusing)

    rendered/Billboard3.cpp
    rendered/Box3.cpp
    rendered/ColorBox3.cpp
    rendered/ColorDiamond3.cpp
    rendered/ColorTetrahedron3.cpp
    rendered/ColorTriangle3.cpp
    rendered/Diamond3.cpp
    rendered/GradBox3.cpp
    rendered/GradDiamond3.cpp
    rendered/GradTetrahedron3.cpp
    rendered/GradTriangle3.cpp
    rendered/ImageQuad3.cpp
    rendered/Quadrilateral3.cpp
    rendered/SkyBox3.cpp
    rendered/Tetrahedron3.cpp
    rendered/Triangle3.cpp

    widget/FrameInspector.cpp
    widget/SpaceCameraRemote.cpp
)

target_link_libraries(yq_assetvk 
PUBLIC
    yq_tachyon
)

vulqan_library(yq_assetvk)
LinkTest(yq_assetvk)

