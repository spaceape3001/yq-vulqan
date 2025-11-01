////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/api/ID.hpp>

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
