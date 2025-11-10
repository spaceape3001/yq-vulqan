////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>

using yq::tachyon::UIWindow;
using yq::tachyon::UIFlags;

class LuaPanelUI : public UIWindow {
    YQ_OBJECT_DECLARE(LuaPanelUI, UIWindow)

public:
    static void init_meta();
    LuaPanelUI(UIFlags flags={});
    LuaPanelUI(const LuaPanelUI& cp);
    
    virtual LuaPanelUI*   clone() const;
    void    render() override;
    
private:
    float   m_min   = 0.10;
    float   m_max   = 0.80;
};
