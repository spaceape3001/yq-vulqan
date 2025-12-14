////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetColorProfileEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/asset/ColorProfile.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetColorProfileEvent)

namespace yq::tachyon {

    SetColorProfileEvent::SetColorProfileEvent(const Header&h, const ColorProfileCPtr& dm, const Url& u) : Event(h), m_colorProfile(dm), m_url(u)
    {
    }

    SetColorProfileEvent::SetColorProfileEvent(const SetColorProfileEvent& cp, const Header& h) : 
        Event(cp, h), m_colorProfile(cp.m_colorProfile), m_url(cp.m_url)
    {
    }
    
    SetColorProfileEvent::~SetColorProfileEvent()
    {
    }

    PostCPtr    SetColorProfileEvent::clone(rebind_k, const Header&h) const 
    {
        return new SetColorProfileEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetColorProfileEvent::init_meta()
    {
        auto w = writer<SetColorProfileEvent>();
        w.description("Set ColorProfile Event");
        w.property("url", &SetColorProfileEvent::m_url);
    }
}
