////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>

using yq::tachyon::UIWindow;
using yq::tachyon::UIFlags;

class ViewPanel : public UIWindow {
    YQ_OBJECT_DECLARE(ViewPanel, UIWindow)
public:

    ViewPanel(UIFlags flags={});
    ViewPanel(const ViewPanel& cp);
    ~ViewPanel();
    ViewPanel* clone() const override;
    void    render() override;
    static void init_meta();

};
