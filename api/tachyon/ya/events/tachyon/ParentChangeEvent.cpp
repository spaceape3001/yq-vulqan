////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/tachyon/ParentChangeEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ParentChangeEvent)

namespace yq::tachyon {

    ParentChangeEvent::ParentChangeEvent(const Header&h, TypedID from, TypedID to) : TachyonEvent(h), m_from(from), m_to(to)
    {
    }

    ParentChangeEvent::ParentChangeEvent(const ParentChangeEvent& cp, const Header& h) : 
        TachyonEvent(cp, h), m_from(cp.m_from), m_to(cp.m_to)
    {
    }
    
    ParentChangeEvent::~ParentChangeEvent()
    {
    }

    PostCPtr    ParentChangeEvent::clone(rebind_k, const Header&h) const 
    {
        return new ParentChangeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ParentChangeEvent::init_info()
    {
        auto w = writer<ParentChangeEvent>();
        w.description("ParentChange Event");
    }
}
