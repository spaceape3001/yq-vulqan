////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/ui/LuaWindow.hpp>

using namespace yq::tachyon;
using namespace yq::lua;

class LuaPanel : public LuaWindow {
    YQ_OBJECT_DECLARE(LuaPanel, LuaWindow)
public:

    LuaPanel(std::string_view, UIFlags flags={});
    LuaPanel(const LuaPanel& cp);
    ~LuaPanel();
    LuaPanel* clone() const override;
    void    render() override;
    static void init_meta();
};
