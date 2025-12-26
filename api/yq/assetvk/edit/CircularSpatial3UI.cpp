////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CircularSpatial3UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/assetvk/command/circular3/Circular3LockCommand.hpp>
#include <yq/assetvk/command/circular3/Circular3PeriodCommand.hpp>
#include <yq/assetvk/command/circular3/Circular3RadiusCommand.hpp>
#include <yq/assetvk/spatial/CircularSpatial3.hpp>
#include <yq/assetvk/spatial/CircularSpatial3Data.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CircularSpatial³UI)

namespace yq::tachyon {
    void CircularSpatial³UI::init_meta()
    {
        auto w = writer<CircularSpatial³UI>();
        w.description("UIEditor for CircularSpatial³");
        w.edits<CircularSpatial³>();
        w.field("Angle", &CircularSpatial³UI::angle);
        w.field("Locked", &CircularSpatial³UI::locked);
        w.field("Period", &CircularSpatial³UI::period);
        w.field("Radius", &CircularSpatial³UI::radius);
    }
    
    CircularSpatial³UI::CircularSpatial³UI(UIFlags flags)
    {
    }
    
    CircularSpatial³UI::CircularSpatial³UI(const CircularSpatial³UI& cp) : UIEditor(cp)
    {
    }
    
    CircularSpatial³UI* CircularSpatial³UI::clone() const
    {
        return new CircularSpatial³UI(*this);
    }

    void    CircularSpatial³UI::angle()
    {
        const CircularSpatial³Snap*     sn  = snap();
        if(!sn)
            return;
        Degree  d   = sn->angle;
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##Angle", d)){
            // change it
        }
    }
    
    void    CircularSpatial³UI::locked()
    {
        const CircularSpatial³Snap*     sn  = snap();
        if(!sn)
            return;
            
        bool    v   = sn->locked;
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Checkbox("##Locked", &v) && (v != sn->locked)){
            send(new Circular³LockCommand({.target=sn->self}, v));
        }
    }
    
    
    void    CircularSpatial³UI::period()
    {
        const CircularSpatial³Snap*     sn  = snap();
        if(!sn)
            return;
            
        unit::Second s    = sn->period;
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Input("##Period", s)){
            send(new Circular³PeriodCommand({.target=sn->self}, { s }));
        }
    }
    
    void    CircularSpatial³UI::radius()
    {
        const CircularSpatial³Snap*     sn  = snap();
        if(!sn)
            return;
        
        double r    = sn->radius;
        ImGui::SetNextItemWidth(-1);
        if(ImGui::InputDouble("##Radius", &r)){
            send(new Circular³RadiusCommand({.target=sn->self}, r));
        }
    }

    const CircularSpatial³Snap*   CircularSpatial³UI::snap() const
    {
        return dynamic_cast<const CircularSpatial³Snap*>(UIEditor::snap());
    }
}
