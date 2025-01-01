////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Scene3DWidget.hpp"
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/api/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    Scene3DWidget0::Scene3DWidget0()
    {
    }
    
    Scene3DWidget0::~Scene3DWidget0()
    {
    }
    
    void    Scene3DWidget0::vulkan_(ViContext& u)
    {
        if(u.viz)
            u.viz->draw_scene(u, scene, perspective);
    }

    void    Scene3DWidget0::add_thing(RenderedPtr r)
    {
        if(r)
            scene.things.push_back(r);
    }
    
    void    Scene3DWidget0::set_camera(CameraCPtr c)
    {
        if(c)
            perspective.camera  = c;
    }

    void    Scene3DWidget0::prerecord(ViContext& u) 
    {
        if(u.viz)
            u.viz->update(u, scene);
        Widget::prerecord(u);
    }

    void Scene3DWidget0::init_info()
    {   
        auto w = writer<Scene3DWidget0>();
        w.description("Widget for a 3D Scene (current implementation)");
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene3DWidget0)
