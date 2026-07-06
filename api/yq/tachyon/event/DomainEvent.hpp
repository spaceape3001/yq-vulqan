////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QDomainLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class DomainEvent : public Event {
        YQ_OBJECT_DECLARE(DomainEvent, Event)
    public:
    
        static void init_meta();

    protected:
        DomainEvent(const Header&);
        DomainEvent(const DomainEvent&, const Header&);
        ~DomainEvent();
    
    private:
        DomainEvent(const DomainEvent&) = delete;
        DomainEvent(DomainEvent&&) = delete;
        DomainEvent& operator=(const DomainEvent&) = delete;
        DomainEvent& operator=(DomainEvent&&) = delete;
    };
}
