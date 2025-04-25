////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/IconifyEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IconifyEvent)

namespace yq::tachyon {

    IconifyEvent::IconifyEvent(const Header&h) : UIEvent(h)
    {
    }

    IconifyEvent::IconifyEvent(const IconifyEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    IconifyEvent::~IconifyEvent()
    {
    }

    PostCPtr    IconifyEvent::clone(rebind_k, const Header&h) const 
    {
        return new IconifyEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void IconifyEvent::init_info()
    {
        auto w = writer<IconifyEvent>();
        w.description("Iconify Event");
    }
}
