////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>
#include <tachyon/command/tachyon/SetNameCommand.hpp>
#include <tachyon/ui/UIEditorMetaWriter.hpp>
#include <tachyon/logging.hpp>
#include <format>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonUI)

namespace yq::tachyon {
    
    void TachyonUI::init_meta()
    {
        auto w = writer<TachyonUI>();
        w.field("Name", &TachyonUI::name);
        w.field("Type", &TachyonUI::type);
        w.field("ID", &TachyonUI::id);
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

    void    TachyonUI::id()
    {
        ImGui::Text(bound().id);
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
            if(ImGui::InputText("##name", text, sizeof(text), ImGuiInputTextFlags_EnterReturnsTrue)){
                text[255] = '\0';
                send(new SetNameCommand({.target=sn->self}, std::string(text)));
            }
        }
    }
    
    void    TachyonUI::thread()
    {
        const Frame*    frame = Frame::current();
        if(!frame)
            return;
        const TachyonData*  tach    = frame->data(bound());
        if(!tach)
            return;
        
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
