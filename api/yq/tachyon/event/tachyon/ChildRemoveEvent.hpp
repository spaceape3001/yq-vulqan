////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class ChildRemoveEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(ChildRemoveEvent, TachyonEvent)
    public:
        ChildRemoveEvent(const Header&, TypedID);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

        TypedID child() const { return m_child; }

    protected:
        ChildRemoveEvent(const ChildRemoveEvent&, const Header&);
        virtual ~ChildRemoveEvent();
        
    private:
        TypedID m_child;

        ChildRemoveEvent(const ChildRemoveEvent&) = delete;
        ChildRemoveEvent(ChildRemoveEvent&&) = delete;
        ChildRemoveEvent& operator=(const ChildRemoveEvent&) = delete;
        ChildRemoveEvent& operator=(ChildRemoveEvent&&) = delete;
    };
}
