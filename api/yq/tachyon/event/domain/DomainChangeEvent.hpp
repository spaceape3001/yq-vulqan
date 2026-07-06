////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/DomainEvent.hpp>

namespace yq::tachyon {
    class DomainChangeEvent : public DomainEvent {
        YQ_OBJECT_DECLARE(DomainChangeEvent, DomainEvent)
    public:
        DomainChangeEvent(const Header&, TypedID from, TypedID to);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

        TypedID     from() const { return m_from; }
        TypedID     to() const { return m_to; }

    protected:
        DomainChangeEvent(const DomainChangeEvent&, const Header&);
        virtual ~DomainChangeEvent();
        
    private:

        TypedID m_from;
        TypedID m_to;

        DomainChangeEvent(const DomainChangeEvent&) = delete;
        DomainChangeEvent(DomainChangeEvent&&) = delete;
        DomainChangeEvent& operator=(const DomainChangeEvent&) = delete;
        DomainChangeEvent& operator=(DomainChangeEvent&&) = delete;
    };
}
