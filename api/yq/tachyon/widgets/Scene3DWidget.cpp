////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scene3DWidget.hpp"
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    Scene3DWidget::Scene3DWidget()
    {
    }
    
    Scene3DWidget::~Scene3DWidget()
    {
    }
    
    void    Scene3DWidget::vulkan_(ViContext& u)
    {
        if(u.viz)
            u.viz->draw_scene(u, scene, perspective);
    }

    void    Scene3DWidget::add_thing(RenderedPtr r)
    {
        if(r)
            scene.things.push_back(r);
    }
    
    void    Scene3DWidget::set_camera(CameraCPtr c)
    {
        if(c)
            perspective.camera  = c;
    }

    void    Scene3DWidget::prerecord(ViContext& u) 
    {
        if(u.viz)
            u.viz->update(u, scene);
        Widget::prerecord(u);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scene3DWidget)
