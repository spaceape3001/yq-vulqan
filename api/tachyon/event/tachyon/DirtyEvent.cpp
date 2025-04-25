////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/tachyon/DirtyEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DirtyEvent)

namespace yq::tachyon {

    DirtyEvent::DirtyEvent(const Header&h) : TachyonEvent(h)
    {
    }

    DirtyEvent::DirtyEvent(const DirtyEvent& cp, const Header& h) : TachyonEvent(cp, h)
    {
    }
    
    DirtyEvent::~DirtyEvent()
    {
    }

    PostCPtr    DirtyEvent::clone(rebind_k, const Header&h) const 
    {
        return new DirtyEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void DirtyEvent::init_info()
    {
        auto w = writer<DirtyEvent>();
        w.description("Dirty Event");
    }
}
