////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/lua/LuaWindow.hpp>

namespace yq::tachyon {
    class LuaExecuteReply;
}

using yq::tachyon::UIFlags;
using yq::tachyon::LuaWindow;
using yq::tachyon::LuaExecuteReply;

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
