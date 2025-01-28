////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/tachyon/DestroyEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DestroyEvent)

namespace yq::tachyon {

    DestroyEvent::DestroyEvent(const Header&h) : TachyonEvent(h)
    {
    }

    DestroyEvent::DestroyEvent(const DestroyEvent& cp, const Header& h) : TachyonEvent(cp, h)
    {
    }
    
    DestroyEvent::~DestroyEvent()
    {
    }

    PostCPtr    DestroyEvent::clone(rebind_k, const Header&h) const 
    {
        return new DestroyEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DestroyEvent::init_info()
    {
        auto w = writer<DestroyEvent>();
        w.description("Destroy Event");
    }
}
