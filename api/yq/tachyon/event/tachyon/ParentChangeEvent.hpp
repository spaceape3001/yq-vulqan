////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/TachyonEvent.hpp>

namespace yq::tachyon {
    class ParentChangeEvent : public TachyonEvent {
        YQ_OBJECT_DECLARE(ParentChangeEvent, TachyonEvent)
    public:
        ParentChangeEvent(const Header&, TypedID from, TypedID to);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

        TypedID     from() const { return m_from; }
        TypedID     to() const { return m_to; }

    protected:
        ParentChangeEvent(const ParentChangeEvent&, const Header&);
        virtual ~ParentChangeEvent();
        
    private:

        TypedID m_from;
        TypedID m_to;

        ParentChangeEvent(const ParentChangeEvent&) = delete;
        ParentChangeEvent(ParentChangeEvent&&) = delete;
        ParentChangeEvent& operator=(const ParentChangeEvent&) = delete;
        ParentChangeEvent& operator=(ParentChangeEvent&&) = delete;
    };
}
