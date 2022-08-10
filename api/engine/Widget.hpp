////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>

namespace yq {
    namespace engine {
    
        class Viewer;
        struct UiData;
    
        class WidgetInfo : public MetaObjectInfo {
        public:
            template <typename C> class Writer;
        
            WidgetInfo(std::string_view, const MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        /*! \brief Root something that's drawwable on ImGui
        
            It follows ImGui's rules, this is something that is "drawable" and needs some amount of state information.
        */
        class Widget : public MetaObject {    
            YQ_OBJECT_INFO(WidgetInfo)
            YQ_OBJECT_DECLARE(Widget, MetaObject)
        public:
        
            virtual void    draw(/*UiData&*/);
            
        protected:
            friend class Viewer;
            
            Widget();
            ~Widget();
            
            Viewer*                     m_viewer    = nullptr;
            Widget*                     m_parent    = nullptr;
            std::vector<Ref<Widget>>    m_children;
        };

        template <typename C>
        class WidgetInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(WidgetInfo* widgetInfo) : MetaObjectInfo::Writer<C>(widgetInfo)
            {
            }
            
            Writer(WidgetInfo& widgetInfo) : Writer(&widgetInfo)
            {
            }
        };
    }
}
