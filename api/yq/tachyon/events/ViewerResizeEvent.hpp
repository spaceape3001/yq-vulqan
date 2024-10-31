////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class ViewerResizeEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerResizeEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerResizeEvent(Viewer*, const Size2I&, const Param& p = {});
        virtual ~ViewerResizeEvent();
        
        static void init_info();
        
        const Size2I& size() const { return m_size; }
        double width() const { return m_size.x; }
        double height() const { return m_size.y; }
        
    private:
        const Size2I    m_size;
    };
}
