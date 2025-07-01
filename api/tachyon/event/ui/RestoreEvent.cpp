////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/RestoreEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RestoreEvent)

namespace yq::tachyon {

    RestoreEvent::RestoreEvent(const Header&h) : UIEvent(h)
    {
    }

    RestoreEvent::RestoreEvent(const RestoreEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    RestoreEvent::~RestoreEvent()
    {
    }

    PostCPtr    RestoreEvent::clone(rebind_k, const Header&h) const 
    {
        return new RestoreEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void RestoreEvent::init_info()
    {
        auto w = writer<RestoreEvent>();
        w.description("Restore Event");
    }
}
