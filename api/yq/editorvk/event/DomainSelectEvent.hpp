////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/domain.hpp>

namespace yq::tachyon {

    class DomainSelectEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(DomainSelectEvent, EditorEvent)
    public:
        DomainSelectEvent(const Header&, DomainID);
        DomainSelectEvent(const DomainSelectEvent&, const Header&);
        ~DomainSelectEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        DomainID        domain() const { return m_domain; }
        static void init_meta();
    private:
        DomainID        m_domain;
    };
}
