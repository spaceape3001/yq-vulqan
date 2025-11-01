////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/ui/ShowEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShowEvent)

namespace yq::tachyon {

    ShowEvent::ShowEvent(const Header&h) : UIEvent(h)
    {
    }

    ShowEvent::ShowEvent(const ShowEvent& cp, const Header& h) : UIEvent(cp, h)
    {
    }
    
    ShowEvent::~ShowEvent()
    {
    }

    PostCPtr    ShowEvent::clone(rebind_k, const Header&h) const 
    {
        return new ShowEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ShowEvent::init_meta()
    {
        auto w = writer<ShowEvent>();
        w.description("Show Event");
    }
}
