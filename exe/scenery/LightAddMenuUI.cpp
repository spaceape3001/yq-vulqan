////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightAddMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Light.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/text/match.hpp>

struct SceneEditor::LightAddMenuUI::Item {
    std::string         title;
    const LightInfo*   info    = nullptr;
};

void SceneEditor::LightAddMenuUI::init_info()
{
    auto w = writer<LightAddMenuUI>();
    w.description("Scene Editor's Add Light Menu UI");
}

SceneEditor::LightAddMenuUI::LightAddMenuUI(std::string_view title, UIFlags flags) : UIMenu(title, flags)
{
}

SceneEditor::LightAddMenuUI::LightAddMenuUI(const LightAddMenuUI& cp) : UIMenu(cp)
{
}

SceneEditor::LightAddMenuUI::~LightAddMenuUI()
{
}

void    SceneEditor::LightAddMenuUI::build_menu()
{
    m_items.clear();
    for(const LightInfo* ci : LightInfo::all()){
        if(!ci)
            continue;
        if(ci->is_abstract())
            continue;
        m_items.push_back({ .title=std::string(ci->stem()), .info=ci });
    }
    std::stable_sort(m_items.begin(), m_items.end(), [](const Item& a, const Item& b) -> bool {
        return is_less_igCase(a.title, b.title);
    });
}

SceneEditor::LightAddMenuUI* SceneEditor::LightAddMenuUI::clone() const 
{
    return new LightAddMenuUI(*this);
}

void SceneEditor::LightAddMenuUI::content() 
{
    if(m_items.empty())
        build_menu();
    for(const Item& i : m_items){
        if(ImGui::MenuItem(i.title.c_str())){
            SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
            if(editor && i.info)
                editor -> create_light(*i.info);
        }
    }
}


YQ_OBJECT_IMPLEMENT(SceneEditor::LightAddMenuUI)
