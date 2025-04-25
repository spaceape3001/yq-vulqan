////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/ui/AspectEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AspectEvent)

namespace yq::tachyon {

    AspectEvent::AspectEvent(const Header&h, const Size2I& asp) : UIEvent(h), m_aspect(asp)
    {
    }

    AspectEvent::AspectEvent(const AspectEvent& cp, const Header& h) : UIEvent(cp, h), m_aspect(cp.m_aspect)
    {
    }
    
    AspectEvent::~AspectEvent()
    {
    }

    PostCPtr    AspectEvent::clone(rebind_k, const Header&h) const 
    {
        return new AspectEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AspectEvent::init_info()
    {
        auto w = writer<AspectEvent>();
        w.description("Aspect Event");
        w.property("aspect", &AspectEvent::m_aspect).description("Aspect ratio").tag(kTag_Save);
        w.property("w", &AspectEvent::width).description("Aspect width").tag(kTag_Log);
        w.property("h", &AspectEvent::height).description("Aspect height").tag(kTag_Log);
    }
}
