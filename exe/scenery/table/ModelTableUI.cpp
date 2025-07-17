////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ModelTableUI.hpp"
#include "event/ModelSelectEvent.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/texture.hpp>
#include <tachyon/api/Model.hpp>
#include <tachyon/api/ModelData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>


struct ModelTableUI::Row {
    ModelID            model;
    const ModelMeta*   info        = nullptr;
    std::string        sid;        // ID for selectable
    std::string        stype;
};

void ModelTableUI::init_meta()
{
    auto w = writer<ModelTableUI>();
    w.description("Scene Editor's Model Table");
}

ModelTableUI::ModelTableUI(UIFlags flags) : UIElement(flags)
{
}

ModelTableUI::ModelTableUI(const ModelTableUI& cp) : UIElement(cp)
{
}

ModelTableUI*   ModelTableUI::clone() const 
{
    return new ModelTableUI(*this);
}


void    ModelTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        
    if(ImGui::BeginTable("Models", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.model == m_selected);
            bool    wantEdit    = false;
            const ModelSnap*    ss  = frame->snap(e.model);
            if(!ss)
                continue;

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                if(isEdit){
                    if(m_editing){
                        ImGui::ImageWithBg(m_editing, imgBtnSize);
                    } else {
                        ImGui::TextUnformatted("E");
                    }
                }
            }
            
            if(ImGui::TableNextColumn()){
                if(ImGui::Selectable(e.sid.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            if(ImGui::TableNextColumn()){
                if(ImGui::Selectable(e.stype.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }            

            if(ImGui::TableNextColumn()){
                std::string sname;
                if(ss->name.empty()){
                    sname   = std::format("(no-name)##{}.SELECT", e.model.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.model.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit)
                set_selected(e.model);
        }
        ImGui::EndTable();
    }
}

void ModelTableUI::set_selected(ModelID ca)
{
    m_selected  = ca;
    mail(new ModelSelectEvent({}, ca));
}

void           ModelTableUI::tick()
{
    UIElement::tick();
    const Frame* frame = Frame::current();
    if(!frame)
        return;
        
    std::set<ModelID>  models = frame->ids(MODEL);
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!models.contains(itr->model)){
            if(itr->model == m_selected){
                set_selected({});
            }
            itr = m_rows.erase(itr);
            continue;
        }
        
        models.erase(itr->model);
        ++itr;
    }
    
    for(ModelID c : models){
        Row   en;
        en.model        = c;
        en.info         = frame->meta(c);
        en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            set_selected(c);
    }
    
}

const char*    ModelTableUI::title() const 
{
    return "Models";
}

YQ_OBJECT_IMPLEMENT(ModelTableUI)
