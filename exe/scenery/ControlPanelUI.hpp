////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindow.hpp>

using yq::tachyon::UIWindow;
using yq::tachyon::UIFlags;

class ControlPanelUI : public UIWindow {
    YQ_OBJECT_DECLARE(ControlPanelUI, UIWindow)

public:
    static void init_meta();
    ControlPanelUI(UIFlags flags={});
    ControlPanelUI(const ControlPanelUI& cp);
    
    virtual ControlPanelUI*   clone() const;
    void    render() override;
    
private:
    float   m_min   = 0.10;
    float   m_max   = 0.80;
};
