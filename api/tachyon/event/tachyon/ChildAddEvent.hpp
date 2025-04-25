////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class ChildAddEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(ChildAddEvent, TachyonEvent)
    public:
        ChildAddEvent(const Header&, TypedID);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

        TypedID     child() const { return m_child; }

    protected:
        ChildAddEvent(const ChildAddEvent&, const Header&);
        virtual ~ChildAddEvent();
        
    private:
        TypedID     m_child;

        ChildAddEvent(const ChildAddEvent&) = delete;
        ChildAddEvent(ChildAddEvent&&) = delete;
        ChildAddEvent& operator=(const ChildAddEvent&) = delete;
        ChildAddEvent& operator=(ChildAddEvent&&) = delete;
    };
}
