////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CompositeWidget.hpp"
#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>
#include <tachyon/api/CameraTweak.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Rendered3Data.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>
#include <tachyon/vulkan/ViContext.hpp>
#include <yq/util/AutoReset.hpp>
#include <tachyon/logging.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CompositeWidget)

namespace yq::tachyon {
    CompositeWidget::CompositeWidget()
    {
    }
    
    CompositeWidget::~CompositeWidget()
    {
    }

    void    CompositeWidget::_prerecord(ViContext& u, const CLayer& lay)
    {
        //  We'll move these into a sub-style of widget
    
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        if(!u.frame0)
            return ;
    
        const SceneSnap*   scene   = frame -> snap(lay.scene);
        if(!scene)
            return ;
            
        if((scene->bgcolor.alpha >= 0) && (u.clear.alpha < 0.))
            u.clear     = scene->bgcolor;
            
        PreContext     ctx{ u, *frame };
        ctx.time        = u.time;
        ctx.gamma       = lay.gamma;

        camera_matrix(ctx, lay.camera, lay.tweaks);
        
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
        
    void    CompositeWidget::prerecord(ViContext& ctx) 
    {
        for(const CLayer& lay : m_layers)
            _prerecord(ctx, lay);
        Widget::prerecord(ctx);
    }

    void CompositeWidget::init_info()
    {
        auto w = writer<CompositeWidget>();
        w.description("Composite widget using multiple scenes/cameras");
    }
}
