////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/LuaWindowUI.hpp>

namespace yq::tachyon {
    class LuaExecuteReply;
}

using yq::tachyon::UIFlags;
using yq::tachyon::LuaWindowUI;
using yq::tachyon::LuaExecuteReply;

class LuaPanelUI : public LuaWindowUI {
    YQ_OBJECT_DECLARE(LuaPanelUI, UIWindow)
public:
    static void init_meta();
    LuaPanelUI(UIFlags flags={});
    LuaPanelUI(const LuaPanelUI& cp);
    virtual ~LuaPanelUI();
    
    virtual LuaPanelUI*   clone() const;
    void            render() override;
};
