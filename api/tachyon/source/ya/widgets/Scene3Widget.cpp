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
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        if(!u.frame0)
            return ;
    
        Scene³ID    sc  = id(SCENE);
    
        const Scene³Snap*   scene   = frame -> snap(id(SCENE));
        if(!scene)
            return ;
            
        const Camera³Snap*  camera  = frame->snap(id(CAMERA));
        if(camera){
            m_view          = camera -> view;
            m_projection    = camera -> projection;
        }
        
        Tensor44D      w2e44 = m_projection * m_view;
        glm::dmat4      w2e = w2e44;
        auto r2 = auto_reset(u.world2eye, glm::dmat4(w2e));
        
        // maybe a spatial -> matrix cache here???
        
        
        //  eventually ... scene has lights/cameras
        for(TypedID t : scene->lights){
            if(!t.types(Type::Light))
                continue;
                
            //  we'll eventually process this... (LATER)
        }
        
        StdPushData     stdpush;
        stdpush.time    = u.time;
        
        for(TypedID t : scene->rendereds){
            if(!t(Type::Rendered))
                continue;
            
            const RenderedSnap* sn  = frame->snap(RenderedID(t.id));
            if(!sn)
                continue;
            
            if(!sn->pipeline)
                continue;
            
            ViRenderedPtr  rr  = u.frame0 -> create({.rendered=sn});
            if(!rr)
                continue;

            const void*   pb  = nullptr;
            switch(sn->pipeline->push().type){
            case PushConfigType::Full:
                if(t(Type::Rendered³)){
                    const Rendered³Snap* r3 = static_cast<const Rendered³Snap*>(sn);
                    if(r3->vm_override){
                        Tensor44D   vm  = comingle(m_view, r3->model, r3->vm_tensor);
                        stdpush.matrix  = glm::dmat4(m_projection * vm);
                    } else {
                        stdpush.matrix  = glm::dmat4(w2e44 * r3->model);
                    }
                    pb  = &stdpush;
                    break;
                }
                [[fallthrough]];
            case PushConfigType::View:
                stdpush.matrix  = w2e;
                pb      = &stdpush;
                break;
            case PushConfigType::Custom:
                break;
            default:
                break;
            }
            
            rr->update(u, *sn, pb);
            rr->descriptors();
            m_rendereds.push_back(rr);
        }
    }

    void    Scene³Widget::prerecord(ViContext& u) 
    {
        _prerecord(u);
        Widget::prerecord(u);
    }

    void    Scene³Widget::vulkan_(ViContext& u)
    {
        {
            yInfo() << "Scene³Widget::vulkan_() rendering with " << m_rendereds.size() << " Rendereds";
            auto w  = auto_reset(u.wireframe, m_wireframe);
            for(ViRenderedPtr& rr : m_rendereds){
                rr->record(u);
            }
            m_rendereds.clear();
        }
        Widget::vulkan_(u);
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
