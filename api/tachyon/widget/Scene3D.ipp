////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/Scene3D.hpp>
#include <tachyon/gpu/ViContext.hpp>
#include <tachyon/gpu/Visualizer.hpp>

namespace yq::tachyon {
    Scene3D::Scene3D()
    {
    }
    
    Scene3D::~Scene3D()
    {
    }
    
    void    Scene3D::vulkan_(ViContext& u)
    {
        if(u.viz())
            u.viz()->draw_scene(u, scene, perspective);
    }

    void    Scene3D::add_thing(RenderedPtr r)
    {
        if(r)
            scene.things.push_back(r);
    }
    
    void    Scene3D::set_camera(CameraCPtr c)
    {
        if(c)
            perspective.camera  = c;
    }

    void    Scene3D::prerecord(ViContext& u) 
    {
        if(u.viz())
            u.viz()->update(u, scene);
        Widget::prerecord(u);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scene3D)
