////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIWindow.hpp>
#include <tachyon/typedef/widget.hpp>
#include <yt/api/ID.hpp>

namespace yq::tachyon {

    //! This is about a widget when you want the size/position title/etc 
    //! controlled by ImGui
    class UIWidget : public UIWindow {
        YQ_OBJECT_DECLARE(UIWidget, UIWindow)
    public:
    
    
        WidgetID        widget_id() const { return m_widget; }
    
    private:
        WidgetID        m_widget = {};
    };
}
