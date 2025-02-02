////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWidget.hpp"
#include "CameraScene.hpp"
#include "CameraController.hpp"

#include <ya/cameras/SpaceCamera.hpp>
#include <ya/widgets/FrameInspector.hpp>
#include <yt/ui/MyImGui.hpp>

using namespace yq;
using namespace yq::tachyon;

void MainWidget::init_info()
{
    auto w = writer<MainWidget>();
    w.description("Camera SDK Example Main Widget");
}


MainWidget::MainWidget()
{
    for(const CameraInfo* ci : CameraInfo::all()){
        if(!ci)
            continue;
        if(ci->is_abstract())
            continue;
        m_infos.push_back({ .info=ci, .stem=ci->name_stem()});
    }
    
    std::stable_sort(m_cameras.begin(), m_cameras.end(), 
        [](const Cam& a, const Cam& b) 
        {
            return is_less_igCase(a.stem, b.stem);
        }
    );
}

MainWidget::~MainWidget()
{
}

void    MainWidget::imgui(ViContext&ctx) 
{
    if(!m_init)
        return ;
    
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("Camera")){
            if(MenuItem("Frame Inspector")){
                m_inspector->cmd_show();
            }
            ImGui::EndMenu();
        }
        
    }
    
    Widget::imgui(ctx);
}

void    MainWidget::setup(const Context& ctx) 
{
    if(!m_init){
        if(!m_scene)
            m_scene         = create<CameraScene>();
        if(!m_camera){
            m_camera        = create<SpaceCamera>();
            m_camera->make_simple_spatial(
                Vector3D(-10, 0, -5.),
                Quaternion3D(HPR, (Radian) 0._deg, (Radian) 180._deg, (Radian) 0._deg)
            );
            m_camera->set_near(.1);
            m_camera->set_far(20.);
        }
        if(!m_controller)
            m_controller    = create<CameraController>(*m_camera);
        if(!m_inspector)
            m_inspector     = create_child<FrameInspector>();
        
        const Frame*    curFrame    = Frame::current();
        if(!curFrame)
            return WAIT;
        
        if(!curFrame->contains(id()))
            return WAIT;

        if(!curFrame->contains(m_scene->id()))
            return WAIT;

        if(!curFrame->contains(m_controller->id()))
            return WAIT;

        if(!curFrame->contains(m_inspector->id()))
            return WAIT;
            
        Viewer* v   = viewer();
        if(!v)
            return WAIT;
            
        m_controller->cmd_listen(v->id());
        m_init = true;
    }
    return Widget::setup(ctx);
}

