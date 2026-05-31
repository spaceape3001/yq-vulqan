////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BgColorUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/color.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PBgColor.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BgColorUI)

namespace yq::tachyon {
    void BgColorUI::init_meta()
    {
        auto w = writer<BgColorUI>();
        w.description("UIEditor for BgColor");
        w.edits<PBgColor>();
        w.field("Alternate Color", &BgColorUI::bgcolor);
    }
    
    BgColorUI::BgColorUI(UIFlags flags)
    {
    }
    
    BgColorUI::BgColorUI(const BgColorUI& cp) : UIEditor(cp)
    {
    }
    
    BgColorUI* BgColorUI::clone() const
    {
        return new BgColorUI(*this);
    }

    void    BgColorUI::bgcolor()
    {
        PBgColor* p   = snap()->proxy<PBgColor>();
        if(!p)
            return ;
            
        RGBA4F    v   = p->bgcolor();
        if(im::color("##color", v))
            p -> bgcolor(SET, v);
    }
}
