////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/widget/Scene3DWidget.hpp>
#include <tachyon/vulkan/ViContext.hpp>
#include <tachyon/vulkan/Visualizer.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    Scene3DWidget0::Scene3DWidget0()
    {
    }
    
    Scene3DWidget0::~Scene3DWidget0()
    {
    }
    
    void    Scene3DWidget0::vulkan(ViContext& u)
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
