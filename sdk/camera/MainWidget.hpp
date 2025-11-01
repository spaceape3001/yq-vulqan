////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/widget/SceneWidget.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/camera3.hpp>

namespace yq::tachyon {
    class SpaceCamera;
    class CameraMeta;
    class FrameInspector;
    class SpaceCameraRemote;
}

using namespace yq;
using namespace yq::tachyon;


/*! \brief Main camera app widget
    
*/
class MainWidget : public SceneWidget {
    YQ_TACHYON_DECLARE(MainWidget, SceneWidget)
public:

    MainWidget();
    ~MainWidget();
    
    void        imgui(ViContext&) override;
    Execution   setup(const Context& ctx) override;
    
    static void init_meta();
    
private:
    
    struct Cam {
        const CameraMeta*   info;
        std::string         stem;
        CameraID            id;
    };

    std::vector<Cam>        m_cameras;
    TypedID                 m_camera;
    TypedID                 m_scene;
    TypedID                 m_controller;
    Ref<FrameInspector>     m_inspector;
    Ref<SpaceCameraRemote>  m_remote;
    bool                    m_init          = false;
};
