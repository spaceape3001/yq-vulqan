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
    //! controlled by ImGui... widget needs to live in this thread!
    //! *IF* the widget is in this thread *AND* it has an UIElement, 
    //! then that element will be called
    class UIWidget : public UIWindow {
        YQ_OBJECT_DECLARE(UIWidget, UIWindow)
    public:
    
        UIWidget(UIFlags flags={});
        UIWidget(WidgetID, UIFlags flags={});
        ~UIWidget();
    
        WidgetID        widget_id() const { return m_widget; }
        void            set_widget(WidgetID);
        
        virtual void content() override;
        
        static void     init_meta();
        
        virtual const char* title() const override;
    
    private:
        WidgetID        m_widgetID  = {};
        std::string     m_title;
    };
}
