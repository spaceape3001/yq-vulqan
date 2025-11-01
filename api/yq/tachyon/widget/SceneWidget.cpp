////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneWidget.hpp"
#include <tachyon/api/Camera.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>
#include <tachyon/vulkan/ViContext.hpp>
#include <yq/util/AutoReset.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SceneWidget)

/*
    Musings on the rendered... may need the concept of a 
    global UBO/SBO for lights, etc for the shaders to loop 
    through in the scene.  This will need adaptations into
    the pipeline, data objects, etc.
*/

namespace yq::tachyon {
    void SceneWidget::init_meta()
    {
        auto w = writer<SceneWidget>();
        w.description("3D Scene Widget v2");
        w.vulkan();
    }
    
    SceneWidget::SceneWidget() : Widget()
    {
    }
    
    SceneWidget::~SceneWidget()
    {
    }

    void    SceneWidget::_prerecord(ViContext& u)
    {
        //  We'll move these into a sub-style of widget
    
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        if(!u.frame0)
            return ;
    
        const SceneSnap*   scene   = frame -> snap(id(SCENE));
        if(!scene)
            return ;
        if(scene->bgcolor.alpha >= 0.)
            u.clear     = scene->bgcolor;
            
        PreContext     ctx{ u, *frame };
        ctx.time        = u.time;
        ctx.gamma       = m_gamma;

        camera_matrix(ctx, id(CAMERA));
        
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
        
        for(TypedID t : scene->rendereds){
            if(!t(Type::Rendered))
                continue;
                
            prerecord(ctx, RenderedID(t.id));
        }
    }

    CameraID    SceneWidget::id(camera_k) const 
    { 
        if(m_camera(Type::Camera)){
            return { m_camera.id }; 
        } else {
            return {};
        }
    }
    
    SceneID     SceneWidget::id(scene_k) const
    {
        if(m_scene(Type::Scene)){
            return { m_scene.id };
        } else
            return {};
    }
    
    void    SceneWidget::prerecord(ViContext& u) 
    {
        _prerecord(u);
        Widget::prerecord(u);
    }

    void    SceneWidget::set_camera(CameraID cid)
    {
        m_camera        = TypedID(cid.id, meta<Camera>().types());
    }
    
    void    SceneWidget::set_scene(SceneID sid)
    {
        m_scene         = TypedID(sid.id, meta<Scene>().types());
    }
}
