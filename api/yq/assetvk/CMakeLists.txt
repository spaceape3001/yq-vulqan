################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_assetvk SHARED
    command_circular3.cpp
    command_user3.cpp
    event_circular3.cpp
    event_user3.cpp
    trigger.cpp
    
    camera/SpaceCamera.cpp
    
    control/Position3Control.cpp
    control/Orientation3Control.cpp
    control/ThreadOverclockEditUI.cpp
    control/ThreadTimeEditUI.cpp

    controller/Space3Controller.cpp

    edit/BgColorUI.cpp
    edit/CircularSpatial3UI.cpp
    edit/ColorProfileUI.cpp
    edit/ColorUI.cpp
    edit/Count1UI.cpp
    edit/Count2UI.cpp
    edit/Count3UI.cpp
    edit/Count4UI.cpp
    edit/DrawModeUI.cpp
    edit/FarPlaneUI.cpp
    edit/FieldOfViewUI.cpp
    edit/HeightFieldUI.cpp
    edit/LightUI.cpp
    edit/MaterialUI.cpp
    edit/MeshUI.cpp
    edit/NearPlaneUI.cpp
    edit/Orientation3UI.cpp
    edit/Position1UI.cpp
    edit/Position2UI.cpp
    edit/Position3UI.cpp
    edit/Position4UI.cpp
    edit/RenderedUI.cpp
    edit/Scale3UI.cpp
    edit/SceneUI.cpp
    edit/SimpleSpatial3UI.cpp
    edit/Size3UI.cpp
    edit/SkyBox3UI.cpp
    edit/TachyonUI.cpp
    edit/TextureUI.cpp
    edit/TopologyUI.cpp
    edit/UserSpatial3UI.cpp
    edit/Vertices3UI.cpp

    event/panel/MetaSelectionChangedEvent.cpp

    io/FileIOManager.cpp

    layer/BackgroundLayer.cpp
    layer/ForegroundLayer.cpp
    layer/HUDLayer.cpp
    
    light/AmbientLight.cpp

    menu/CreateMenuUI.cpp

    mini/TextLabel.cpp


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
    rendered/HeightField3.cpp
    rendered/ImageQuad3.cpp
    rendered/Mesh3.cpp
    rendered/Quadrilateral3.cpp
    rendered/SkyBox3.cpp
    rendered/Tetrahedron3.cpp
    rendered/Triangle3.cpp

    scene/BackgroundScene.cpp
    scene/CompositeScene.cpp
    scene/ForegroundScene.cpp
    scene/HUDScene.cpp
    scene/SimpleScene.cpp
    
    spatial/CircularSpatial3.cpp
    spatial/GeoSpatial3.cpp
    #spatial/OrbitSpatial3.cpp
    spatial/SimpleSpatial2.cpp
    spatial/SimpleSpatial3.cpp
    spatial/UserSpatial3.cpp

    tweak/OriginCameraTweak.cpp
    
    ui/UIConcreteMetaList.cpp
    ui/UIFrameMetrics.cpp
    ui/UIMetaList.cpp
    ui/UISimpleTree.cpp
    ui/UIStacked.cpp
    ui/UITachyonEditor.cpp

    widget/CompositeWidget.cpp
    widget/FrameInspector.cpp
    widget/FormWidget.cpp
    widget/ImGuiDemoWidget.cpp
    widget/SceneWidget.cpp
    widget/SpaceCameraRemote.cpp
    widget/StackedWidget.cpp
    widget/TextArea.cpp

)

target_link_libraries(yq_assetvk 
PUBLIC
    yq_tachyon
    yq_userexpr
)

vulqan_library(yq_assetvk)
LinkTest(yq_assetvk)

