////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/widgets/Scene3Widget.hpp>
#include <yt/typedef/scene3.hpp>
#include <yt/typedef/camera3.hpp>

namespace yq::tachyon {
    class SpaceCamera;
    class CameraInfo;
    class FrameInspector;
    class SpaceCameraRemote;
}

using namespace yq;
using namespace yq::tachyon;


/*! \brief Main camera app widget
    
*/
class MainWidget : public Scene³Widget {
    YQ_TACHYON_DECLARE(MainWidget, Scene³Widget)
public:

    MainWidget();
    ~MainWidget();
    
    void        imgui(ViContext&) override;
    Execution   setup(const Context& ctx) override;
    
    static void init_info();
    
private:
    
    struct Cam {
        const CameraInfo*   info;
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
