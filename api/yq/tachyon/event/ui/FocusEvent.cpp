////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/ui/FocusEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FocusEvent)

namespace yq::tachyon {

    FocusEvent::FocusEvent(const Header&h) : UIEvent(h)
    {
    }

    FocusEvent::FocusEvent(const FocusEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    FocusEvent::~FocusEvent()
    {
    }

    PostCPtr    FocusEvent::clone(rebind_k, const Header&h) const 
    {
        return new FocusEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FocusEvent::init_meta()
    {
        auto w = writer<FocusEvent>();
        w.description("Focus Event");
    }
}
