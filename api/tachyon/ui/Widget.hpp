////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Object.hpp>
#include <basic/UniqueID.hpp>

namespace yq {
    namespace tachyon {
        struct UiData;
    
        class WidgetInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;
        
            WidgetInfo(std::string_view, const ObjectInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        /*! \brief Root something that's drawwable on ImGui
        
            It follows ImGui's rules, this is something that is "drawable" and needs some amount of state information.
        */
        class Widget : public Object, public UniqueID {    
            YQ_OBJECT_INFO(WidgetInfo)
            YQ_OBJECT_DECLARE(Widget, Object)
        public:
        
            virtual void    draw(/*UiData&*/);
            
            virtual ~Widget();
            
        protected:
            Widget();

            Widget*                 m_parent    = nullptr;
            std::vector<Widget*>    m_children;
            std::string             m_windowID;
        };
    }
}
