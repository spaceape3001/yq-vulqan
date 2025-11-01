////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/ui/CloseEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CloseEvent)

namespace yq::tachyon {

    CloseEvent::CloseEvent(const Header&h) : UIEvent(h)
    {
    }

    CloseEvent::CloseEvent(const CloseEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    CloseEvent::~CloseEvent()
    {
    }

    PostCPtr    CloseEvent::clone(rebind_k, const Header&h) const 
    {
        return new CloseEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CloseEvent::init_meta()
    {
        auto w = writer<CloseEvent>();
        w.description("Close Event");
    }
}
