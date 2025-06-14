////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BgColorUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>
#include <tachyon/proxy/PBgColor.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BgColorUI)

namespace yq::tachyon {
    void BgColorUI::init_info()
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
        if(ImGui::ColorEdit("##bgcolor", v))
            p -> bgcolor(SET, v);
    }
}
