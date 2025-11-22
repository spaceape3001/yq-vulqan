////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/LuaWindowUI.hpp>

using namespace yq::tachyon;

class LuaPanel : public LuaWindowUI {
    YQ_OBJECT_DECLARE(LuaPanel, LuaWindowUI)
public:

    LuaPanel(std::string_view, UIFlags flags={});
    LuaPanel(const LuaPanel& cp);
    ~LuaPanel();
    LuaPanel* clone() const override;
    void    render() override;
    static void init_meta();
};
