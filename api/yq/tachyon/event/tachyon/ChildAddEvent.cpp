////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/tachyon/ChildAddEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ChildAddEvent)

namespace yq::tachyon {

    ChildAddEvent::ChildAddEvent(const Header&h, TypedID ch) : TachyonEvent(h), m_child(ch)
    {
    }

    ChildAddEvent::ChildAddEvent(const ChildAddEvent& cp, const Header& h) : TachyonEvent(cp, h), m_child(cp.m_child)
    {
    }
    
    ChildAddEvent::~ChildAddEvent()
    {
    }

    PostCPtr    ChildAddEvent::clone(rebind_k, const Header&h) const 
    {
        return new ChildAddEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ChildAddEvent::init_meta()
    {
        auto w = writer<ChildAddEvent>();
        w.description("ChildAdd Event");
    }
}
