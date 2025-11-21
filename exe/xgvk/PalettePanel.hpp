////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>

using yq::tachyon::UIWindow;
using yq::tachyon::UIFlags;

class PalettePanel : public UIWindow {
    YQ_OBJECT_DECLARE(PalettePanel, UIWindow)
public:

    PalettePanel(UIFlags flags={});
    PalettePanel(const PalettePanel& cp);
    ~PalettePanel();
    PalettePanel* clone() const override;
    void    render() override;
    static void init_meta();

private:
    float   m_min   = 0.20;
    float   m_max   = 0.80;
};
