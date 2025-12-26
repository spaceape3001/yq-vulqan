////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonUI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>
#include <yq/tachyon/command/tachyon/SetEditModeCommand.hpp>
#include <yq/tachyon/command/tachyon/SetNameCommand.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonUI)

namespace yq::tachyon {
    
    void TachyonUI::init_meta()
    {
        auto w = writer<TachyonUI>();
        w.field("Name", &TachyonUI::name);
        w.field("Type", &TachyonUI::type);
        w.field("ID", &TachyonUI::id);
        w.field("Cycle Time", C::Inspector, &TachyonUI::cycle_time);
        w.field("Edit Mode", &TachyonUI::edit_mode);
        w.field("Parent", &TachyonUI::parent);
        w.field("Revision", C::Inspector, &TachyonUI::revision);
        w.field("Thread", &TachyonUI::thread);
        w.edits<Tachyon>();
    }

    TachyonUI::TachyonUI(UIFlags flags) : UIEditor(flags)
    {
    }

    TachyonUI::TachyonUI(const TachyonUI& cp) : UIEditor(cp)
    {
    }
    
    TachyonUI::~TachyonUI()
    {
    }
    
    TachyonUI*  TachyonUI::clone() const 
    {
        return new TachyonUI(*this);
    }

    void    TachyonUI::cycle_time()
    {
        const TachyonData*  dt  = data();
        if(dt->cycleTime < 1_µs){
            ImGui::Text("%lf ns", dt->cycleTime.value);
        } else if(dt->cycleTime < 1_ms){
            ImGui::Text("%lf µs", unit::Microsecond(dt->cycleTime).value);
        } else if(dt->cycleTime < 1_s){
            ImGui::Text("%lf ms", unit::Millisecond(dt->cycleTime).value);
        } else {
            ImGui::Text("%lf s",  unit::Second(dt->cycleTime).value);
        }
    }

    void    TachyonUI::edit_mode()
    {
        const TachyonSnap*  sn    = snap();
        Tristate    v   = sn->edit_mode;
        ImGui::SetNextItemWidth(-1);
        if(ImGui::Checkbox("##EditMode", v))
            send(new SetEditModeCommand({.target=sn->self}, v));
    }

    void    TachyonUI::id()
    {
        ImGui::Text(bound().id);
    }
    
    void    TachyonUI::parent()
    {
        ImGui::Text(snap()->parent.id);
    }

    void    TachyonUI::type()
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return;
        const Tachyon*  tach   = frame->object(bound());
        if(!tach)
            return;
        ImGui::TextUnformatted(tach->metaInfo().name());
    }

    void    TachyonUI::name()
    {
        const TachyonSnap*  sn    = snap();
        if(readonly()){
            ImGui::TextUnformatted(sn->name);
        } else {
            char            text[256] ;
            if(!sn->name.empty()){
                strncpy(text, sn->name.c_str(), sizeof(text));
                text[255] = '\0';
            } else
                text[0] = '\0';
            ImGui::SetNextItemWidth(-1);
            if(ImGui::InputText("##name", text, sizeof(text), ImGuiInputTextFlags_EnterReturnsTrue)){
                text[255] = '\0';
                send(new SetNameCommand({.target=sn->self}, std::string(text)));
            }
        }
    }

    void    TachyonUI::revision()
    {
        ImGui::Text("%ld", snap()->revision);
    }
    
    void    TachyonUI::thread()
    {
        const Frame*    frame = Frame::current();
        if(!frame)
            return;
        const TachyonData*  tach    = data();
        
        std::string     text;    
        if(const ThreadSnap*   th = frame->snap(tach->owner)){
            if(!th->name.empty())
                text    = std::format("{} [{}]", th->name, tach->owner.id);
        }
        
        if(text.empty())
            text    = std::format("[{}]", tach->owner.id);
        ImGui::TextUnformatted(text);
    }
}
