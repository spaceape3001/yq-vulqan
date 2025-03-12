////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/widgets/Scene3Widget.hpp>
#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/3D/Rendered3.hpp>
#include <yt/3D/Rendered3Data.hpp>
#include <yt/3D/Scene3.hpp>
#include <yt/3D/Scene3Data.hpp>
#include <yt/api/Frame.hpp>
#include <yt/gfx/PushData.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yv/ViContext.hpp>
#include <yv/ViRendered.hpp>
#include <yv/Visualizer.hpp>
#include <yv/Visualizer.hxx>
#include <yq/util/AutoReset.hpp>
#include <yq/tensor/Tensor44.hxx>
#include <yt/logging.hpp>
#include <yq/vector/Vector4.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Scene³Widget)

/*
    Musings on the rendered... may need the concept of a 
    global UBO/SBO for lights, etc for the shaders to loop 
    through in the scene.  This will need adaptations into
    the pipeline, data objects, etc.
*/

namespace yq::tachyon {
    void Scene³Widget::init_info()
    {
        auto w = writer<Scene³Widget>();
        w.description("3D Scene Widget v2");
        w.vulkan();
    }
    
    Scene³Widget::Scene³Widget() : Widget()
    {
    }
    
    Scene³Widget::~Scene³Widget()
    {
    }

    void    Scene³Widget::_prerecord(ViContext& u)
    {
        //  We'll move these into a sub-style of widget
    
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        if(!u.frame0)
            return ;
    
        const Scene³Snap*   scene   = frame -> snap(id(SCENE³));
        if(!scene)
            return ;
            
        PushContext     ctx{ u, *frame };
        ctx.time        = u.time;
        ctx.gamma       = m_gamma;
        
        camera_matrix(ctx, id(CAMERA³));
        
        //ctx.w2e44       = ctx.projection44 * ctx.view44;
        //ctx.w2e         = ctx.w2e44;
        //auto r2 = auto_reset(u.world2eye, ctx.w2e);
        
        // maybe a spatial -> matrix cache here???
        
        
        //  eventually ... scene has lights/cameras
        for(TypedID t : scene->lights){
            if(!t.types(Type::Light))
                continue;
                
            //  we'll eventually process this... (LATER)
        }
        
        m_rendereds.resize(scene->rendereds.size());
        size_t  k   = 0;
        
        for(TypedID t : scene->rendereds){
            if(!t(Type::Rendered))
                continue;
            const RenderedSnap* sn  = frame->snap(RenderedID(t.id));
            if(!sn)
                continue;
            
            if(!sn->pipeline)
                continue;
            
            ViRenderedPtr  rr  = u.frame0 -> create(sn);
            if(!rr)
                continue;
                
            R&  r  = m_rendereds[k++];
            r.vi    = rr;
            push_buffer(r.push, ctx, *sn);
            rr->update(u, *sn);
            rr->descriptors();
        }
        
        if(k != m_rendereds.size()){
            m_rendereds.erase(m_rendereds.begin()+k, m_rendereds.end());
        }
    }

    CameraID    Scene³Widget::id(camera_k) const 
    { 
        if(m_camera(Type::Camera)){
            return { m_camera.id }; 
        } else {
            return {};
        }
    }
    
    Camera³ID   Scene³Widget::id(camera³_k) const 
    { 
        if(m_camera(Type::Camera³)){
            return { m_camera.id }; 
        } else {
            return {};
        }
    }



    SceneID     Scene³Widget::id(scene_k) const
    {
        if(m_scene(Type::Scene)){
            return { m_scene.id };
        } else
            return {};
    }
    
    Scene³ID    Scene³Widget::id(scene³_k) const
    {
        if(m_scene(Type::Scene³)){
            return { m_scene.id };
        } else
            return {};
    }
    
    void    Scene³Widget::prerecord(ViContext& u) 
    {
        _prerecord(u);
        Widget::prerecord(u);
    }

    void    Scene³Widget::vulkan(ViContext& u)
    {
        {
            auto w  = auto_reset(u.wireframe, m_wireframe);
            for(const R& r : m_rendereds)
                r.vi->record(u, r.push);
            m_rendereds.clear();
        }
        Widget::vulkan(u);
    }

    void    Scene³Widget::set_camera(Camera³ID cid)
    {
        m_camera        = TypedID(cid.id, meta<Camera³>().types());
    }
    
    void    Scene³Widget::set_scene(Scene³ID sid)
    {
        m_scene         = TypedID(sid.id, meta<Scene³>().types());
    }
}
