////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/tachyon/ChildRemoveEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ChildRemoveEvent)

namespace yq::tachyon {

    ChildRemoveEvent::ChildRemoveEvent(const Header&h, TypedID ch) : TachyonEvent(h), m_child(ch)
    {
    }

    ChildRemoveEvent::ChildRemoveEvent(const ChildRemoveEvent& cp, const Header& h) : TachyonEvent(cp, h), m_child(cp.m_child)
    {
    }
    
    ChildRemoveEvent::~ChildRemoveEvent()
    {
    }

    PostCPtr    ChildRemoveEvent::clone(rebind_k, const Header&h) const 
    {
        return new ChildRemoveEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ChildRemoveEvent::init_meta()
    {
        auto w = writer<ChildRemoveEvent>();
        w.description("ChildRemove Event");
    }
}
