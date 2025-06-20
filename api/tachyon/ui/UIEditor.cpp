////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIEditor.hpp"
#include "UIEditorWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIEditor)

namespace yq::tachyon {
    struct UIEditorInfo::Repo {
        std::vector<const UIEditorInfo*>    all;
    };
    
    UIEditorInfo::Repo& UIEditorInfo::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    
    const std::vector<const UIEditorInfo*>& UIEditorInfo::all()
    {
        return repo().all;
    }

    UIEditorInfo::UIEditorInfo(std::string_view name, UIElements::MyInfo&base, const std::source_location& sl) :
        UIElements::MyInfo(name, base, sl)
    {
        repo().all.push_back(this);
    }


    bool    UIEditorInfo::has_fields() const
    {
        return !m_fields.empty();
    }

    ////////////////////////////

    void UIEditor::init_info()
    {
        auto w = writer<UIEditor>();
        w.description("UI Editor");
        w.abstract();
    }
    
    UIEditor::UIEditor(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIEditor::UIEditor(const UIEditor& cp) : UIElements(cp), m_bind(cp.m_bind), m_snap(nullptr)
    {
    }
    
    UIEditor::~UIEditor()
    {
    }

    bool    UIEditor::bind(TypedID tac)
    {
        m_bind      = tac;
        return true;
    }

    void    UIEditor::render()
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return;
        m_snap          = frame->snap(m_bind);
        if(!m_snap)
            return ;
            
        std::string     table   = std::format("##Editor{}{}", metaInfo().name(), m_bind.id );
        auto& sty = style();

        float w = ImGui::GetWindowWidth();
        
        if(ImGui::BeginTable(table.c_str(), 2)){
            float x = ImGui::GetCursorPosX();
            float kw    = std::max(sty.table.keycol()-x, sty.table.keycol.min);
            float vw    = std::max(sty.table.valcol.min, w-x);
            
            ImGui::TableSetupColumn("Key",   ImGuiTableColumnFlags_WidthFixed, kw);
            ImGui::TableSetupColumn("Value" /*, ImGuiTableColumnFlags_WidthFixed, vw */);
            
            for(auto& f : metaInfo().m_fields){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn())
                    ImGui::TextUnformatted(f.label);
                if(ImGui::TableNextColumn()){
                    ImGui::PushID(f.label.c_str());
                    f.executor->execute(this);
                    ImGui::PopID();
                }
            }
            
            ImGui::EndTable();
        }
        
    }

    ////////////////////////////
    
    UIEditorWriter::UIEditorWriter() = default;
    UIEditorWriter::UIEditorWriter(const UIEditorWriter&) = default;
    UIEditorWriter::~UIEditorWriter() = default;
    
    UIEditor* UIEditorWriter::element()
    {
        return dynamic_cast<UIEditor*>(m_ui);
    }
    
    UIEditorWriter::UIEditorWriter(UIEditor* ui) : UIElementsWriter(ui)
    {
    }

}
