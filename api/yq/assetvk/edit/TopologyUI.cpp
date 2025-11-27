////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TopologyUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PTopology.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TopologyUI)

namespace yq::tachyon {
    void TopologyUI::init_meta()
    {
        auto w = writer<TopologyUI>();
        w.description("UIEditor for Draw Mode");
        w.edits<PTopology>();
        w.field("Topology", &TopologyUI::topology);
    }
    
    TopologyUI::TopologyUI(UIFlags flags)
    {
    }
    
    TopologyUI::TopologyUI(const TopologyUI& cp) : UIEditor(cp)
    {
    }
    
    TopologyUI* TopologyUI::clone() const
    {
        return new TopologyUI(*this);
    }

    void    TopologyUI::topology()
    {
        PTopology* p   = snap()->proxy<PTopology>();
        if(!p)
            return ;
            
        Topology    v   = p->topology();
        if(ImGui::Combo("##topology", v))
            p -> topology(SET, v);
    }
}
