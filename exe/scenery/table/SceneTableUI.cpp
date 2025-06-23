////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneTableUI.hpp"
#include "event/SceneAddEvent.hpp"
#include "event/SceneRemoveEvent.hpp"
#include "event/SceneSelectEvent.hpp"
#include "event/SceneVisibilityEvent.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>


struct SceneTableUI::Row {
    SceneID             scene;
    CameraID            camera;
    std::string         cameraText  = "(default)";
    const SceneInfo*    info        = nullptr;
    std::string         sid;        // ID for selectable
    std::string         stype;
    std::string         visBtn, visBtn2, invisBtn, invisBtn2;
    bool                visible     = true;
};

namespace {
    std::string  text_for(CameraID cam)
    {
        if(!cam)
            return "";
            
        const Frame*    frame   = Frame::current();
        if(!frame)
            return "(error)";
            
        const CameraInfo*   info    = frame->info(cam);
        const CameraSnap*   snap    = frame->snap(cam);
        
        if(!snap->name.empty()){
            return std::format("({}:{})", info->stem(), cam.id );
        } else {
            return std::format("({}:{}) {}", info->stem(), cam.id, snap->name);
        }
    }
}


void SceneTableUI::init_info()
{
    auto w = writer<SceneTableUI>();
    w.description("Scene Editor's Scene Table");
}

SceneTableUI::SceneTableUI(UIFlags flags) : UIElement(flags)
{
}

SceneTableUI::SceneTableUI(const SceneTableUI& cp) : UIElement(cp)
{
}

CameraID        SceneTableUI::camera(SceneID id) const
{
    const Row* r    = row(id);
    if(!r)
        return {};
    return r->camera;
}

SceneTableUI*   SceneTableUI::clone() const 
{
    return new SceneTableUI(*this);
}


void    SceneTableUI::render() 
{
    const Frame*    frame   = Frame::current();
    if(!frame)
        return ;

    float   sz  = ImGui::GetFrameHeight() * 0.9;
    
    Size2F      imgBtnSize    = { sz, sz };
    
    if(!m_editing)
        m_editing = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
    if(!m_invisible)
        m_invisible = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-p000-general.png"));
    if(!m_visible)
        m_visible   = install(texture("exe/scenery/eyeball48.png"));
        
    if(ImGui::BeginTable("Scenes", 5)){
        ImGui::TableSetupColumn("Editing", ImGuiTableColumnFlags_WidthFixed|ImGuiTableColumnFlags_NoHeaderLabel, sz*1.2);
        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthStretch, 0.1);
        ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthStretch, 0.3);
        ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch, 0.4);
        ImGui::TableSetupColumn("Camera", ImGuiTableColumnFlags_WidthStretch, 0.2);
        ImGui::TableHeadersRow();

        for(Row& e : m_rows){
            bool    isEdit  = (e.scene == m_selected);
            bool    wantEdit    = false;
            const SceneSnap*    ss  = frame->snap(e.scene);
            if(!ss)
                continue;
                
            bool    vChange = false;

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                if(isEdit){
                    if(m_editing){
                        ImGui::ImageWithBg(m_editing, imgBtnSize);
                    } else {
                        ImGui::TextUnformatted("E");
                    }
                } else {
                    if(e.visible){
                        if(m_visible ? ImGui::ImageButton(e.visBtn.c_str(), m_visible, imgBtnSize) : ImGui::Button(e.visBtn2.c_str())){
                            e.visible   = true;
                            vChange     = true;
                        }
                    } else {
                        if(m_invisible ? ImGui::ImageButton(e.invisBtn.c_str(), m_invisible, imgBtnSize) : ImGui::Button(e.invisBtn2.c_str())){
                            e.visible   = false;
                            vChange     = true;
                        }
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
                    sname   = std::format("(no-name)##{}.SELECT", e.scene.id); 
                } else
                   sname = std::format("{}##{}.SELECT", ss->name, e.scene.id); 

                if(ImGui::Selectable(sname.c_str(), isEdit) && !isEdit){
                    wantEdit    = true;
                }
            }
            
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(e.cameraText);
            }
            
            if(wantEdit)
                set_selected(e.scene);
                
            if(vChange)
                mail(new SceneVisibilityEvent({}, e.scene));
        }
        ImGui::EndTable();
    }
}

SceneTableUI::Row*            SceneTableUI::row(SceneID id)
{
    for(Row& r : m_rows){
        if(r.scene == id)
            return &r;
    }
    return nullptr;
}

const SceneTableUI::Row*      SceneTableUI::row(SceneID id) const
{
    return const_cast<SceneTableUI*>(this)->row(id);
}

void SceneTableUI::set_selected(SceneID ca)
{
    m_selected  = ca;
    mail(new SceneSelectEvent({}, ca));
}

std::vector<SceneID>    SceneTableUI::scenes() const
{
    std::vector<SceneID>    ret;
    for(const Row& r : m_rows)
        ret.push_back(r.scene);
    return ret;
}

std::vector<SceneTableUI::Snap>       SceneTableUI::snaps() const
{
    std::vector<Snap>       ret;
    for(const Row& r : m_rows)
        ret.push_back({r.scene, r.camera, r.info, r.visible});
    return ret;
}

void           SceneTableUI::tick()
{
    UIElement::tick();

    const Frame* frame  = Frame::current();
    if(!frame)
        return;

    std::set<SceneID>   scenes = frame->ids(SCENE);
    std::set<SceneID>   removed;
    
    for(auto itr = m_rows.begin(); itr != m_rows.end(); ){
        if(!scenes.contains(itr->scene)){
            if(itr->scene == m_selected){
                set_selected({});
            }
            removed.insert(itr->scene);
            itr = m_rows.erase(itr);
            continue;
        }
        
        scenes.erase(itr->scene);
        ++itr;
    }
    
    for(SceneID c : scenes){
        Row   en;
        en.scene       = c;
        en.info         = frame->info(c);
        en.sid          = std::format("{}##{}.SELECT_ID", c.id, c.id);
        en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), c.id);
        en.visBtn       = std::format("{}##VISIBLE{}", c.id, c.id);
        en.visBtn2      = std::format("V##VISIBLE{}", c.id);
        en.invisBtn     = std::format("{}##INVISIBLE{}", c.id, c.id);
        en.invisBtn2    = std::format("I##INVISIBLE{}", c.id);
        m_rows.push_back(en);
        
        if(!m_selected)
            set_selected(c);
    }
    
    if(!removed.empty())
        mail(new SceneRemoveEvent({}, std::move(removed)));
    if(!scenes.empty())
        mail(new SceneAddEvent({}, std::move(scenes)));
}

const char*    SceneTableUI::title() const 
{
    return "Scenes";
}

bool            SceneTableUI::visible(SceneID id) const
{
    const Row* r = row(id);
    if(!r)
        return false;
    return r->visible;
}

YQ_OBJECT_IMPLEMENT(SceneTableUI)
