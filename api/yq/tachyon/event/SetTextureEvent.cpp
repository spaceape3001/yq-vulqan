////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTextureEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>
#include <yq/tachyon/asset/Texture.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTextureEvent)

namespace yq::tachyon {

    SetTextureEvent::SetTextureEvent(const Header&h, const TextureCPtr& dm, const Url& u) : Event(h), m_texture(dm), m_url(u)
    {
    }

    SetTextureEvent::SetTextureEvent(const SetTextureEvent& cp, const Header& h) : 
        Event(cp, h), m_texture(cp.m_texture), m_url(cp.m_url)
    {
    }
    
    SetTextureEvent::~SetTextureEvent()
    {
    }

    PostCPtr    SetTextureEvent::clone(rebind_k, const Header&h) const 
    {
        return new SetTextureEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetTextureEvent::init_meta()
    {
        auto w = writer<SetTextureEvent>();
        w.description("Set Texture Event");
        w.property("url", &SetTextureEvent::m_url);
    }
}
