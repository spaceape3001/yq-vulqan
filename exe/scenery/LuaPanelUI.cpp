////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaPanelUI.hpp"
#include <yq/tachyon/ui/UILineInput.hpp>
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

LuaPanelUI::LuaPanelUI(UIFlags flags) : LuaWindowUI("Lua Panel", flags | UIFlag::NoCollapse | UIFlag::NoResize )
{
}

LuaPanelUI::LuaPanelUI(const LuaPanelUI& cp) : LuaWindowUI(cp)
{
}

LuaPanelUI::~LuaPanelUI()
{

}

LuaPanelUI*   LuaPanelUI::clone() const 
{
    return new LuaPanelUI(*this);
}

void    LuaPanelUI::render() 
{
    AxBox2F box = parent() -> viewport(CONTENT);
    float   cx   = 0.;
    float   cy  = 0.5*box.height();
    UIWindow*   ctrlp = dynamic_cast<UIWindow*>(element(FIRST, "ControlPanel"));
    if(ctrlp && !ctrlp->invisible())
        cx   = ctrlp->right();
    corners(SET, NEXT, {cx, cy}, box.hh() );
    LuaWindowUI::render();
}

YQ_OBJECT_IMPLEMENT(LuaPanelUI)
