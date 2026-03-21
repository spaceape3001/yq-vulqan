////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PhysicsTableUI.hpp"

#include <yq/editorvk/event/PhysicsSelectEvent.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/texture.hpp>
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

namespace yq::tachyon {
    struct PhysicsTableUI::Row {
        PhysicsID           physics;
        const PhysicsMeta*  info        = nullptr;
        std::string         sid;        // ID for selectable
        std::string         stype;
    };

    void PhysicsTableUI::init_meta()
    {
        auto w = writer<PhysicsTableUI>();
        w.description("Scene Editor's Physics Table");
    }

    PhysicsTableUI::PhysicsTableUI(UIFlags flags) : UIElement(flags)
    {
    }

    PhysicsTableUI::PhysicsTableUI(const PhysicsTableUI& cp) : UIElement(cp)
    {
    }

    PhysicsTableUI*   PhysicsTableUI::clone() const 
    {
        return new PhysicsTableUI(*this);
    }


    void    PhysicsTableUI::render() 
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;

        float   sz  = ImGui::GetFrameHeight() * 0.9;
        
        Size2F      imgBtnSize    = { sz, sz };
        
        if(!m_editing)
            m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
            
        if(ImGui::BeginTable("Physicss", 4)){
            ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
            ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
            ImGui::TableHeadersRow();

            for(Row& e : m_rows){
                bool    isEdit  = (e.physics == m_selected);
                bool    wantEdit    = false;
                const PhysicsSnap*    ss  = frame->snap(e.physics);
                if(!ss)
                    continue;

                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    if(isEdit){
                        if(m_editing){
                            ImGui::ImageWithBg(m_editing.id, imgBtnSize);
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
                        sname   = std::format("(no-name)##{}.SELECT", e.physics.id); 
                    } else
                       sname = std::format("{}##{}.SELECT", ss->name, e.physics.id); 

                    if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                        wantEdit    = true;
                    }
                }
                
                if(wantEdit)
                    set_selected(e.physics);
            }
            ImGui::EndTable();
        }
    }

    void PhysicsTableUI::set_selected(PhysicsID ca)
    {
        m_selected  = ca;
        mail(new PhysicsSelectEvent({}, ca));
    }

    void           PhysicsTableUI::tick()
    {
        UIElement::tick();
        const Frame* frame = Frame::current();
        if(!frame)
            return;
            
        std::set<PhysicsID>  physics = frame->ids(PHYSICS);
        
        for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
            if(!physics.contains(itr->physics)){
                if(itr->physics == m_selected){
                    set_selected({});
                }
                itr = m_rows.erase(itr);
                continue;
            }
            
            physics.erase(itr->physics);
            ++itr;
        }
        
        for(PhysicsID c : physics){
            Row   en;
            en.physics        = c;
            en.info         = frame->meta(c);
            en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
            en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
            m_rows.push_back(en);
            
            if(!m_selected)
                set_selected(c);
        }
        
    }

    const char*    PhysicsTableUI::title() const 
    {
        return "Physicss";
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::PhysicsTableUI)
