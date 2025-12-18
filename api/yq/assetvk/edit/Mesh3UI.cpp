////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh3UI.hpp"

#include <yq/assetvk/rendered/Mesh3.hpp>
#include <yq/assetvk/rendered/Mesh3Data.hpp>

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/command/shape/SetAxisRemapCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Mesh³UI)

namespace yq::tachyon {
    
    void Mesh³UI::init_meta()
    {
        auto w = writer<Mesh³UI>();
        w.field("Axis", &Mesh³UI::axis);
        w.edits<Mesh³>();
    }

    Mesh³UI::Mesh³UI(UIFlags flags) : UIEditor(flags)
    {
    }

    Mesh³UI::Mesh³UI(const Mesh³UI& cp) : UIEditor(cp)
    {
    }
    
    Mesh³UI::~Mesh³UI()
    {
    }
    
    Mesh³UI*  Mesh³UI::clone() const 
    {
        return new Mesh³UI(*this);
    }
    
    void    Mesh³UI::axis()
    {
        const Mesh³Snap* sn = dynamic_cast<const Mesh³Snap*>(snap());
        if(!sn)
            return ;
        AxisRemap   ar  = sn->axis;
        if(ImGui::Combo("##Axis", ar))
            send(new SetAxisRemapCommand({.target=sn->self}, ar));
    }
}
