////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraTableUI.hpp"
#include "CameraEntry.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/gfx/Texture.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>


void SceneEditor::CameraTableUI::init_info()
{
    auto w = writer<CameraTableUI>();
    w.description("Scene Editor's Camera Table");
}

SceneEditor::CameraTableUI::CameraTableUI(UIFlags flags) : UIElement(flags)
{
}

SceneEditor::CameraTableUI::CameraTableUI(const CameraTableUI& cp) : UIElement(cp)
{
}

SceneEditor::CameraTableUI*   SceneEditor::CameraTableUI::clone() const 
{
    return new CameraTableUI(*this);
}

const char*    SceneEditor::CameraTableUI::title() const 
{
    return "Cameras";
}

void    SceneEditor::CameraTableUI::render() 
{
    ImGui::TextUnformatted("Cameras!");
}

YQ_OBJECT_IMPLEMENT(SceneEditor::CameraTableUI)
