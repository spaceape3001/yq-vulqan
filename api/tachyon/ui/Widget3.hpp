////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>

namespace yq {
    namespace tachyon {
        class Widget3Info : public WidgetInfo {
        public:
            template <typename C> class Writer;
            Widget3Info(std::string_view, const WidgetInfo&, const std::source_location& sl = std::source_location::current());
        };

        class Widget3 : public Widget {
            YQ_OBJECT_INFO(Widget3Info)
            YQ_OBJECT_DECLARE(Widget3, Widget)
        public:

            struct ViContext {};       // contents TBD
        
            Widget3();
            virtual ~Widget3();
            
            virtual void    imgui_(ViContext&);
            virtual void    vulkan_(ViContext&);

        protected:
            Widget3*                m_parent = nullptr;
            std::vector<Widget3*>   m_children;
        };

        template <typename C>
        class Widget3Info::Writer : public WidgetInfo::Writer<C> {
        public:
            Writer(Widget3Info* widgetInfo) : WidgetInfo::Writer<C>(widgetInfo)
            {
            }
            
            Writer(Widget3Info& widgetInfo) : Writer(&widgetInfo)
            {
            }
        };
    }
}

