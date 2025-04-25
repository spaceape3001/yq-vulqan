////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/HideEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::HideEvent)

namespace yq::tachyon {

    HideEvent::HideEvent(const Header&h) : UIEvent(h)
    {
    }

    HideEvent::HideEvent(const HideEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    HideEvent::~HideEvent()
    {
    }

    PostCPtr    HideEvent::clone(rebind_k, const Header&h) const 
    {
        return new HideEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void HideEvent::init_info()
    {
        auto w = writer<HideEvent>();
        w.description("Hide Event");
    }
}
