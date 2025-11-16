////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/ui/LuaWindow.hpp>

namespace yq::lua {
    class LuaExecuteReply;
}

using yq::tachyon::UIFlags;
using yq::lua::LuaWindow;
using yq::lua::LuaExecuteReply;

class LuaPanelUI : public LuaWindow {
    YQ_OBJECT_DECLARE(LuaPanelUI, UIWindow)
public:
    static void init_meta();
    LuaPanelUI(UIFlags flags={});
    LuaPanelUI(const LuaPanelUI& cp);
    virtual ~LuaPanelUI();
    
    virtual LuaPanelUI*   clone() const;
    void            render() override;
};
