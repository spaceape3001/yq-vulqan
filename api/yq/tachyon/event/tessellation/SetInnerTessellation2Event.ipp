////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetInnerTessellation2Event.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetInnerTessellation²Event)

namespace yq::tachyon {
    SetInnerTessellation²Event::SetInnerTessellation²Event(const Header& h, const Vector2D& v) : 
        TessellationEvent(h), m_innerTessellation(v)
    {
    }

    SetInnerTessellation²Event::SetInnerTessellation²Event(const SetInnerTessellation²Event& cp, const Header& h) : 
        TessellationEvent(cp, h), m_innerTessellation(cp.m_innerTessellation)
    {
    }
    
    SetInnerTessellation²Event::~SetInnerTessellation²Event()
    {
    }

    PostCPtr    SetInnerTessellation²Event::clone(rebind_k, const Header&h) const 
    {
        return new SetInnerTessellation²Event(*this, h);
    }
    
    void SetInnerTessellation²Event::init_meta()
    {
        auto w = writer<SetInnerTessellation²Event>();
        w.description("Set Tessellation Event");
        w.property("inner_tessellation", &SetInnerTessellation²Event::m_innerTessellation).tag({kTag_Save, kTag_Log});
    }
}
