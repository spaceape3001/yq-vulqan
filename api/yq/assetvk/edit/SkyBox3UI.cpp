////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SkyBox3UI.hpp"
#include <yq/assetvk/rendered/SkyBox3.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SkyBox³UI)

namespace yq::tachyon {
    void SkyBox³UI::init_meta()
    {
        auto w = writer<SkyBox³UI>();
        w.description("UIEditor for SkyBox³");
        w.edits<SkyBox³>();
    }
    
    SkyBox³UI::SkyBox³UI(UIFlags flags)
    {
    }
    
    SkyBox³UI::SkyBox³UI(const SkyBox³UI& cp) : UIEditor(cp)
    {
    }
    
    SkyBox³UI* SkyBox³UI::clone() const
    {
        return new SkyBox³UI(*this);
    }
    
}
