////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/sim/TickEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TickEvent)

namespace yq::tachyon {

    TickEvent::TickEvent(const Header&h) : SimEvent(h)
    {
    }

    TickEvent::TickEvent(const TickEvent& cp, const Header& h) : SimEvent(cp, h)
    {
    }
    
    TickEvent::~TickEvent()
    {
    }

    PostCPtr    TickEvent::clone(rebind_k, const Header&h) const 
    {
        return new TickEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void TickEvent::init_meta()
    {
        auto w = writer<TickEvent>();
        w.description("Tick Event");
    }
}
