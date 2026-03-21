////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ScreenScaleMUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_mks_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PScreenScaleM.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScreenScaleMUI)

namespace yq::tachyon {
    void ScreenScaleMUI::init_meta()
    {
        auto w = writer<ScreenScaleMUI>();
        w.description("UIEditor for ScreenScaleM");
        w.edits<PScreenScaleM>();
        w.field("Screen Scale", &ScreenScaleMUI::screen_scale);
    }
    
    ScreenScaleMUI::ScreenScaleMUI(UIFlags flags)
    {
    }
    
    ScreenScaleMUI::ScreenScaleMUI(const ScreenScaleMUI& cp) : UIEditor(cp)
    {
    }
    
    ScreenScaleMUI* ScreenScaleMUI::clone() const
    {
        return new ScreenScaleMUI(*this);
    }

    void    ScreenScaleMUI::screen_scale()
    {
        PScreenScaleM* p   = snap()->proxy<PScreenScaleM>();
        if(!p)
            return ;
            
        Meter    v   = p->screen_scale();
        if(im::input("##screen_scale", v))
            p -> screen_scale(SET, v);
    }
}
