////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraAddMenuUI.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Camera.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/text/match.hpp>

struct SceneEditor::CameraAddMenuUI::Item {
    std::string         title;
    const CameraInfo*   info    = nullptr;
};

void SceneEditor::CameraAddMenuUI::init_info()
{
    auto w = writer<CameraAddMenuUI>();
    w.description("Scene Editor's Add Menu UI");
}

SceneEditor::CameraAddMenuUI::CameraAddMenuUI(std::string_view title, UIFlags flags) : UIMenu(title, flags)
{
}

SceneEditor::CameraAddMenuUI::CameraAddMenuUI(const CameraAddMenuUI& cp) : UIMenu(cp)
{
}

SceneEditor::CameraAddMenuUI::~CameraAddMenuUI()
{
}

void    SceneEditor::CameraAddMenuUI::build_menu()
{
    m_items.clear();
    for(const CameraInfo* ci : CameraInfo::all()){
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

SceneEditor::CameraAddMenuUI* SceneEditor::CameraAddMenuUI::clone() const 
{
    return new CameraAddMenuUI(*this);
}

void SceneEditor::CameraAddMenuUI::content() 
{
    if(m_items.empty())
        build_menu();
    for(const Item& i : m_items){
        if(ImGui::MenuItem(i.title.c_str())){
            // TODO....
        }
    }
}


YQ_OBJECT_IMPLEMENT(SceneEditor::CameraAddMenuUI)
