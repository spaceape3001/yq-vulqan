////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/MaximizeEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaximizeEvent)

namespace yq::tachyon {

    MaximizeEvent::MaximizeEvent(const Header&h) : UIEvent(h)
    {
    }

    MaximizeEvent::MaximizeEvent(const MaximizeEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    MaximizeEvent::~MaximizeEvent()
    {
    }

    PostCPtr    MaximizeEvent::clone(rebind_k, const Header&h) const 
    {
        return new MaximizeEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MaximizeEvent::init_info()
    {
        auto w = writer<MaximizeEvent>();
        w.description("Maximize Event");
    }
}
