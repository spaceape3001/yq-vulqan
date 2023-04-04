////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>

namespace yq {
    namespace tachyon {
        struct UiData;
    
        class Widget2Info : public WidgetInfo {
        public:
            template <typename C> class Writer;
            Widget2Info(std::string_view, const WidgetInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        /*! \brief Root something that's drawwable
        
            It follows ImGui's rules, this is something that is "drawable" and needs some amount of state information.
        */
        class Widget2 : public Widget {    
            YQ_OBJECT_INFO(Widget2Info)
            YQ_OBJECT_DECLARE(Widget2, Widget)
        public:

            struct UiData {};       // contents TBD
        
            virtual void    imgui_(UiData&);
            virtual void    vulkan_(UiData&, VqRecord&);
            
            virtual ~Widget2();
            
        protected:
            Widget2();

            Widget2*                m_parent    = nullptr;
            std::vector<Widget2*>   m_children;
        };

        template <typename C>
        class Widget2Info::Writer : public WidgetInfo::Writer<C> {
        public:
            Writer(Widget2Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo)
            {
            }
            
            Writer(Widget2Info& widgetInfo) : Writer(&widgetInfo)
            {
            }
        };
    }
}
