////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/DefocusEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DefocusEvent)

namespace yq::tachyon {

    DefocusEvent::DefocusEvent(const Header&h) : UIEvent(h)
    {
    }

    DefocusEvent::DefocusEvent(const DefocusEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    DefocusEvent::~DefocusEvent()
    {
    }

    PostCPtr    DefocusEvent::clone(rebind_k, const Header&h) const 
    {
        return new DefocusEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DefocusEvent::init_info()
    {
        auto w = writer<DefocusEvent>();
        w.description("Defocus Event");
    }
}
