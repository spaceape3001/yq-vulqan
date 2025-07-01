////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderedTableUI.hpp"
#include "event/RenderedSelectEvent.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/RenderedData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>


struct RenderedTableUI::Row {
    RenderedID              rendered;
    const RenderedMeta*     info        = nullptr;
    std::string             sid;        // ID for selectable
    std::string             stype;
};

void RenderedTableUI::init_meta()
{
    auto w = writer<RenderedTableUI>();
    w.description("Scene Editor's Rendered Table");
}

RenderedTableUI::RenderedTableUI(UIFlags flags) : UIElement(flags)
{
}

RenderedTableUI::RenderedTableUI(const RenderedTableUI& cp) : UIElement(cp)
{
}

RenderedTableUI*   RenderedTableUI::clone() const 
{
    return new RenderedTableUI(*this);
}


void    RenderedTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        
    if(ImGui::BeginTable("Rendereds", 4)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.rendered == m_selected);
            bool    wantEdit    = false;
            const RenderedSnap*    ss  = frame->snap(e.rendered);
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
                    sname   = std::format("(no-name)##{}.SELECT", e.rendered.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.rendered.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(wantEdit)
                set_selected(e.rendered);
        }
        ImGui::EndTable();
    }
}

void RenderedTableUI::set_selected(RenderedID ca)
{
    m_selected  = ca;
    mail(new RenderedSelectEvent({}, ca));
}

void           RenderedTableUI::tick()
{
    UIElement::tick();
    const Frame* frame = Frame::current();
    if(!frame)
        return ;
    std::set<RenderedID>  rendereds = frame->ids(RENDERED);
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!rendereds.contains(itr->rendered)){
            if(itr->rendered == m_selected){
                set_selected({});
            }
            itr = m_rows.erase(itr);
            continue;
        }
        
        rendereds.erase(itr->rendered);
        ++itr;
    }
    
    for(RenderedID c : rendereds){
        Row   en;
        en.rendered     = c;
        en.info         = frame->meta(c);
        en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            set_selected(c);
    }
    
}

const char*    RenderedTableUI::title() const 
{
    return "Rendereds";
}



YQ_OBJECT_IMPLEMENT(RenderedTableUI)
