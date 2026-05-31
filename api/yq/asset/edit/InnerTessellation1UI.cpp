////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InnerTessellation1UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/im/input_double.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PInnerTessellation1.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InnerTessellation¹UI)

namespace yq::tachyon {
    void InnerTessellation¹UI::init_meta()
    {
        auto w = writer<InnerTessellation¹UI>();
        w.description("UIEditor for Inner Tessellation¹");
        w.edits<PInnerTessellation¹>();
        w.field("Inner Tessellation", &InnerTessellation¹UI::inner_tessellation);
    }
    
    InnerTessellation¹UI::InnerTessellation¹UI(UIFlags flags)
    {
    }
    
    InnerTessellation¹UI::InnerTessellation¹UI(const InnerTessellation¹UI& cp) : UIEditor(cp)
    {
    }
    
    InnerTessellation¹UI* InnerTessellation¹UI::clone() const
    {
        return new InnerTessellation¹UI(*this);
    }

    void    InnerTessellation¹UI::inner_tessellation()
    {
        PInnerTessellation¹* p   = snap()->proxy<PInnerTessellation¹>();
        if(!p)
            return ;
            
        Vector1D    v   = p->inner_tessellation();
        if(im::input("##inner_tessellation", v))
            p -> inner_tessellation(SET, v);
    }
}
