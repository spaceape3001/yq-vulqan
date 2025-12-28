////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "HeightFieldUI.hpp"
#include <yq/assetvk/gesture/file/PickHeightFieldFileGesture.hpp>
#include <yq/core/Result.hpp>
#include <yq/net/Url.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/command/height_field/SetHeightFieldSpecCommand.hpp>
#include <yq/tachyon/im/lineedit.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PHeightField.hpp>
#include <misc/cpp/imgui_stdlib.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::HeightFieldUI)

namespace yq::tachyon {
    void HeightFieldUI::init_meta()
    {
        auto w = writer<HeightFieldUI>();
        w.description("UIEditor for HeightField");
        w.edits<PHeightField>();
        w.field("Height Field", &HeightFieldUI::height_field);
    }
    
    HeightFieldUI::HeightFieldUI(UIFlags flags)
    {
    }
    
    HeightFieldUI::HeightFieldUI(const HeightFieldUI& cp) : UIEditor(cp)
    {
    }
    
    HeightFieldUI* HeightFieldUI::clone() const
    {
        return new HeightFieldUI(*this);
    }

    void    HeightFieldUI::height_field()
    {
        PHeightField* p   = snap()->proxy<PHeightField>();
        if(!p)
            return ;
        
        std::string     v = to_string(p->height_field(URL));
        switch(im::lineedit(BROWSE, "##height_field", v, {
            .drag       = "height_field_url",
            .drop       = { "height_field_url" },
            .flags      = ImGuiInputTextFlags_EnterReturnsTrue,
            .labelless  = true
        })){
        case im::BrowseResult::None:
            break;
        case im::BrowseResult::Changed:
            send(new SetHeightFieldSpecCommand({.target=snap()->self}, v));
            break;
        case im::BrowseResult::Browse:
            gesture(new PickHeightFieldFileGesture(snap()->self));
            break;
        }
    }
}
