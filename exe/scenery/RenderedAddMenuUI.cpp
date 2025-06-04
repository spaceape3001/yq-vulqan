////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderedAddMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/text/match.hpp>

struct SceneEditor::RenderedAddMenuUI::Item {
    std::string         title;
    const RenderedInfo*   info    = nullptr;
};

void SceneEditor::RenderedAddMenuUI::init_info()
{
    auto w = writer<RenderedAddMenuUI>();
    w.description("Scene Editor's Add Rendered Menu UI");
}

SceneEditor::RenderedAddMenuUI::RenderedAddMenuUI(std::string_view title, UIFlags flags) : UIMenu(title, flags)
{
}

SceneEditor::RenderedAddMenuUI::RenderedAddMenuUI(const RenderedAddMenuUI& cp) : UIMenu(cp)
{
}

SceneEditor::RenderedAddMenuUI::~RenderedAddMenuUI()
{
}

void    SceneEditor::RenderedAddMenuUI::build_menu()
{
    m_items.clear();
    for(const RenderedInfo* ci : RenderedInfo::all()){
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

SceneEditor::RenderedAddMenuUI* SceneEditor::RenderedAddMenuUI::clone() const 
{
    return new RenderedAddMenuUI(*this);
}

void SceneEditor::RenderedAddMenuUI::content() 
{
    if(m_items.empty())
        build_menu();
    for(const Item& i : m_items){
        if(ImGui::MenuItem(i.title.c_str())){
            SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
            if(editor && i.info)
                editor -> create_rendered(*i.info);
        }
    }
}


YQ_OBJECT_IMPLEMENT(SceneEditor::RenderedAddMenuUI)
