////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class ViewerMoveEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerMoveEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerMoveEvent(Viewer*, const Vector2I&, const Param& p = {});
        virtual ~ViewerMoveEvent();
        
        static void init_info();
        
        const Vector2I& position() const { return m_position; }
        double x() const { return m_position.x; }
        double y() const { return m_position.y; }
        
    private:
        const Vector2I    m_position;
    };
}
