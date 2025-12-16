////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIForm.hpp"
#include "UIFormWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>
#include <yq/tachyon/ui/UIFormMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIForm)

namespace yq::tachyon {
    UIFormMeta::UIFormMeta(std::string_view name, UIElements::MyMeta& base, const std::source_location& sl) :
        UIElements::MyMeta(name, base, sl)
    {
    }


    bool    UIFormMeta::has_fields() const
    {
        return !m_fields.empty();
    }

    ////////////////////////////

    void UIForm::init_meta()
    {
        auto w = writer<UIForm>();
        w.description("UI Form");
        w.abstract();
    }
    
    UIForm::UIForm(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIForm::UIForm(const UIForm& cp) : UIElements(cp)
    {
    }
    
    UIForm::~UIForm()
    {
    }

    void    UIForm::render()
    {
        std::string     table   = std::format("##Form{}{}", metaInfo().name(), binding(CREATE) );
        auto& sty = style();

        float w = ImGui::GetWindowWidth();
        
        if(ImGui::BeginTable(table.c_str(), 2, ImGuiTableFlags_SizingStretchProp)){
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
    
    UIFormWriter::UIFormWriter() = default;
    UIFormWriter::UIFormWriter(const UIFormWriter&) = default;
    UIFormWriter::~UIFormWriter() = default;
    
    UIForm* UIFormWriter::element()
    {
        return dynamic_cast<UIForm*>(m_ui);
    }
    
    UIFormWriter::UIFormWriter(UIForm* ui) : UIElementsWriter(ui)
    {
    }

}
