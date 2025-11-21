////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaPanel.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hxx>

YQ_OBJECT_IMPLEMENT(LuaPanel)

using namespace yq;
using namespace yq::tachyon;

LuaPanel::LuaPanel(std::string_view k, UIFlags flags) : LuaWindow(k, flags | UIFlag::NoCollapse | UIFlag::NoDecoration )
{
}

LuaPanel::LuaPanel(const LuaPanel& cp) : LuaWindow(cp)
{
}

LuaPanel::~LuaPanel()
{
}

LuaPanel* LuaPanel::clone() const 
{
    return new LuaPanel(*this);
}

void    LuaPanel::render() 
{
    yq::AxBox2F box = parent() -> viewport(CONTENT);
    corners(SET, NEXT, box.ll(), box.hh() );
    LuaWindow::render();
}

void LuaPanel::init_meta()
{
    auto w = writer<LuaPanel>();
    w.description("Lua Panel");
}
