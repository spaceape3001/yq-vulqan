////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneAddMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/text/match.hpp>

struct SceneEditor::SceneAddMenuUI::Item {
    std::string         title;
    const SceneInfo*   info    = nullptr;
};

void SceneEditor::SceneAddMenuUI::init_info()
{
    auto w = writer<SceneAddMenuUI>();
    w.description("Scene Editor's Add Menu UI");
}

SceneEditor::SceneAddMenuUI::SceneAddMenuUI(std::string_view title, UIFlags flags) : UIMenu(title, flags)
{
}

SceneEditor::SceneAddMenuUI::SceneAddMenuUI(const SceneAddMenuUI& cp) : UIMenu(cp)
{
}

SceneEditor::SceneAddMenuUI::~SceneAddMenuUI()
{
}

void    SceneEditor::SceneAddMenuUI::build_menu()
{
    m_items.clear();
    for(const SceneInfo* ci : SceneInfo::all()){
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

SceneEditor::SceneAddMenuUI* SceneEditor::SceneAddMenuUI::clone() const 
{
    return new SceneAddMenuUI(*this);
}

void SceneEditor::SceneAddMenuUI::content() 
{
    if(m_items.empty())
        build_menu();
    for(const Item& i : m_items){
        if(ImGui::MenuItem(i.title.c_str())){
            SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
            if(editor && i.info)
                editor -> create_scene(*i.info);
        }
    }
}


YQ_OBJECT_IMPLEMENT(SceneEditor::SceneAddMenuUI)
