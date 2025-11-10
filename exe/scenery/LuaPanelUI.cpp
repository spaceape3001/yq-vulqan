////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaPanelUI.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>

using namespace yq;
using namespace yq::tachyon;

void LuaPanelUI::init_meta()
{
    auto w = writer<LuaPanelUI>();
    w.description("Scene Editor's Lua Panel");
}

LuaPanelUI::LuaPanelUI(UIFlags flags) : UIWindow("Lua Panel", flags)
{
}

LuaPanelUI::LuaPanelUI(const LuaPanelUI& cp) : UIWindow(cp)
{
}

LuaPanelUI*   LuaPanelUI::clone() const 
{
    return new LuaPanelUI(*this);
}

void    LuaPanelUI::render() 
{
    AxBox2F box = parent() -> viewport(CONTENT);
    position(SET, NEXT, box.ll());
    height(SET, NEXT, box.height());
    m_w.minimum     = m_min * box.width();
    m_w.maximum     = m_max * box.width();
    UIWindow::render();
}

YQ_OBJECT_IMPLEMENT(LuaPanelUI)
