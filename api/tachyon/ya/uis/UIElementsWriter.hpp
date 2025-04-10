////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIElements;
    class Widget;
    class WidgetInfo;
    
    class UIElementsWriter : public UIElementWriter {
    public:
        
        UIElementsWriter();
        UIElementsWriter(Widget*);
        UIElementsWriter(WidgetInfo*);
        UIElementsWriter(UIElements*);
        UIElementsWriter(const UIElementsWriter&);
        ~UIElementsWriter();
        
        UIElements*     element();
        
    protected:
    
        static UIElements*      attach(Widget*);
        static UIElements*      attach(WidgetInfo*);
        
        /*! \brief Adds item to the elements
        
            \note This routine assumes ownership, may delete the item 
            prior to return (which is why it'll return false).
        */
        bool    add(UIElement*);
    };
}
