////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/UIEvent.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class AspectEvent : public UIEvent {
        YQ_OBJECT_DECLARE(AspectEvent, UIEvent)
    public:
        AspectEvent(const Header&, const Size2I&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Size2I& aspect() const { return m_aspect; }
        int width() const { return m_aspect.x; }
        int height() const { return m_aspect.y; }

        static void init_meta();

    protected:
        AspectEvent(const AspectEvent&, const Header&);
        virtual ~AspectEvent();
        
    private:
        Size2I  m_aspect;

        AspectEvent(const AspectEvent&) = delete;
        AspectEvent(AspectEvent&&) = delete;
        AspectEvent& operator=(const AspectEvent&) = delete;
        AspectEvent& operator=(AspectEvent&&) = delete;
    };
}
