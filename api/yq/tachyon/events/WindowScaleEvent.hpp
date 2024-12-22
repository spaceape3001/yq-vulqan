////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class WindowScaleEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowScaleEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowScaleEvent(Window*, const Vector2F&, const Param& p = {});
        virtual ~WindowScaleEvent();
        
        static void init_info();
        
        const Vector2F& scale() const { return m_scale; }
        float  x() const { return m_scale.x; }
        float  y() const { return m_scale.y; }
        
    private:
        const Vector2F    m_scale;
    };
}
