////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Shape3UI.hpp"

#include <yq/assetvk/rendered/Shape3.hpp>
#include <yq/assetvk/rendered/Shape3Data.hpp>

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/command/shape/SetAutoCenterCommand.hpp>
#include <yq/tachyon/command/shape/SetNormalizeCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Shape³UI)

namespace yq::tachyon {
    
    void Shape³UI::init_meta()
    {
        auto w = writer<Shape³UI>();
        w.field("Auto Center", &Shape³UI::auto_center);
        w.field("Normalize", &Shape³UI::normalize);
        w.edits<Shape³>();
    }

    Shape³UI::Shape³UI(UIFlags flags) : UIEditor(flags)
    {
    }

    Shape³UI::Shape³UI(const Shape³UI& cp) : UIEditor(cp)
    {
    }
    
    Shape³UI::~Shape³UI()
    {
    }
    
    Shape³UI*  Shape³UI::clone() const 
    {
        return new Shape³UI(*this);
    }
    
    void    Shape³UI::auto_center()
    {
        const Shape³Snap* sn = dynamic_cast<const Shape³Snap*>(snap());
        if(!sn)
            return ;
        Tristate   ac  = sn->auto_center;
        if(ImGui::Checkbox("##AutoCenter", ac))
            send(new SetAutoCenterCommand({.target=sn->self}, ac));
    }

    void    Shape³UI::normalize()
    {
        const Shape³Snap* sn = dynamic_cast<const Shape³Snap*>(snap());
        if(!sn)
            return ;
        Tristate   normalize  = sn->normalize;
        if(ImGui::Checkbox("##Normalize", normalize))
            send(new SetNormalizeCommand({.target=sn->self}, normalize));
    }
}
