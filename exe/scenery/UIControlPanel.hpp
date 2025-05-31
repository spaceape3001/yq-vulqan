////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindow.hpp>

using yq::tachyon::UIWindow;
using yq::tachyon::UIFlags;

class UIControlPanel : public UIWindow {
    YQ_OBJECT_DECLARE(UIControlPanel, UIWindow)

public:
    static void init_info();
    UIControlPanel(UIFlags flags={});
    UIControlPanel(const UIControlPanel& cp);
    
    virtual UIControlPanel*   clone() const;
    void    render() override;
    
private:
    float   m_min   = 0.10;
    float   m_max   = 0.80;
};
