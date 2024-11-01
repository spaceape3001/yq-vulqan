////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/ViewerEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class ViewerScaleEvent : public ViewerEvent {
        YQ_OBJECT_DECLARE(ViewerScaleEvent, ViewerEvent)
    public:
    
        struct Param : public ViewerEvent::Param {
        };
    
        ViewerScaleEvent(Viewer*, const Vector2F&, const Param& p = {});
        virtual ~ViewerScaleEvent();
        
        static void init_info();
        
        const Vector2F& scale() const { return m_scale; }
        float  x() const { return m_scale.x; }
        float  y() const { return m_scale.y; }
        
    private:
        const Vector2F    m_scale;
    };
}
