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
    
    Camera³ID   space_camera() const { return m_spaceCamera; }
    
    void    imgui(ViContext&) override;
    void    setup(const Context& ctx) override;
    
    static void init_info();
    
private:
    
    struct Cam {
        const CameraInfo*   info;
        std::string         stem;
        CameraID            id;
    };

    std::vector<Cam>    m_cameras;
    SpaceCamera*        m_camera        = nullptr;
    CameraScene*        m_scene         = nullptr;
    CameraController*   m_controller    = nullptr;
    FrameInspector*     m_inspector     = nullptr;
    bool                m_showInspector = false;
    bool                m_init          = false;
};
