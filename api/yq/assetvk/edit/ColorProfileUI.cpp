////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorProfileUI.hpp"
#include <yq/assetvk/gesture/file/PickColorProfileFileGesture.hpp>
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileSpecCommand.hpp>
#include <yq/tachyon/im/lineedit.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PColorProfile.hpp>
#include <misc/cpp/imgui_stdlib.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ColorProfileUI)

namespace yq::tachyon {
    void ColorProfileUI::init_meta()
    {
        auto w = writer<ColorProfileUI>();
        w.description("UIEditor for ColorProfile");
        w.edits<PColorProfile>();
        w.field("Color Profile", &ColorProfileUI::color_profile);
    }
    
    ColorProfileUI::ColorProfileUI(UIFlags flags)
    {
    }
    
    ColorProfileUI::ColorProfileUI(const ColorProfileUI& cp) : UIEditor(cp)
    {
    }
    
    ColorProfileUI* ColorProfileUI::clone() const
    {
        return new ColorProfileUI(*this);
    }

    void    ColorProfileUI::color_profile()
    {
        PColorProfile* p   = snap()->proxy<PColorProfile>();
        if(!p)
            return ;

        std::string     v = to_string(p->color_profile(URL));
        switch(im::lineedit(BROWSE, "##color_profile", v, {
            .drag       = "color_profile_url",
            .drop       = { "color_profile_url" },
            .flags      = ImGuiInputTextFlags_EnterReturnsTrue,
            .labelless  = true
        })){
        case im::BrowseResult::None:
            break;
        case im::BrowseResult::Changed:
            send(new SetColorProfileSpecCommand({.target=snap()->self}, v));
            break;
        case im::BrowseResult::Browse:
            gesture(new PickColorProfileFileGesture(snap()->self));
            break;
        }
    }
}
