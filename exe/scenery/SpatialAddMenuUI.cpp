////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpatialAddMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Spatial.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/text/match.hpp>

struct SceneEditor::SpatialAddMenuUI::Item {
    std::string         title;
    const SpatialInfo*   info    = nullptr;
};

void SceneEditor::SpatialAddMenuUI::init_info()
{
    auto w = writer<SpatialAddMenuUI>();
    w.description("Scene Editor's Spatial Add Menu UI");
}

SceneEditor::SpatialAddMenuUI::SpatialAddMenuUI(std::string_view title, UIFlags flags) : UIMenu(title, flags)
{
}

SceneEditor::SpatialAddMenuUI::SpatialAddMenuUI(const SpatialAddMenuUI& cp) : UIMenu(cp)
{
}

SceneEditor::SpatialAddMenuUI::~SpatialAddMenuUI()
{
}

void    SceneEditor::SpatialAddMenuUI::build_menu()
{
    m_items.clear();
    for(const SpatialInfo* ci : SpatialInfo::all()){
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

SceneEditor::SpatialAddMenuUI* SceneEditor::SpatialAddMenuUI::clone() const 
{
    return new SpatialAddMenuUI(*this);
}

void SceneEditor::SpatialAddMenuUI::content() 
{
    if(m_items.empty())
        build_menu();
    for(const Item& i : m_items){
        if(ImGui::MenuItem(i.title.c_str())){
            SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
            if(editor && i.info)
                editor -> create_spatial(*i.info);
        }
    }
}


YQ_OBJECT_IMPLEMENT(SceneEditor::SpatialAddMenuUI)
