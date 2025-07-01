////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/WindowEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class FramebufferResizeEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(FramebufferResizeEvent, WindowEvent)
    public:
    
        FramebufferResizeEvent(const Header&, const Size2I&);
        
        static void init_meta();
        
        const Size2I& size() const { return m_size; }
        double width() const { return m_size.x; }
        double height() const { return m_size.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        FramebufferResizeEvent(const FramebufferResizeEvent&, const Header&);
        virtual ~FramebufferResizeEvent();
        
    private:
        Size2I    m_size;
    };
}
