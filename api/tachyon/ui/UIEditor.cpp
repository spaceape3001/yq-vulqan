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
    
    UIEditorInfo::UIEditorInfo(std::string_view name, UIElements::MyInfo&base, const std::source_location& sl) :
        UIElements::MyInfo(name, base, sl)
    {
        repo().all.push_back(this);
    }

    ////////////////////////////

    void UIEditor::init_info()
    {
        auto w = writer<UIEditor>();
        w.description("UI Editor");
    }
    
    UIEditor::UIEditor(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIEditor::UIEditor(const UIEditor& cp) : UIElements(cp)
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
            
        std::string     table   = std::format("Editor{}{}", metaInfo().name(), m_bind.id );
        
        if(ImGui::BeginTable(table.c_str(), 2)){
            ImGui::TableSetupColumn("Key",   ImGuiTableColumnFlags_WidthFixed, style().table.keycol());
            ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch, 1.0);
            for(auto& f : metaInfo().m_fields){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn())
                    ImGui::TextUnformatted(f.label);
                if(ImGui::TableNextColumn())
                    f.executor->execute(this);
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
