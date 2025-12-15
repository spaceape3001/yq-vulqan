////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetInnerTessellation1Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetInnerTessellation¹Event)

namespace yq::tachyon {
    SetInnerTessellation¹Event::SetInnerTessellation¹Event(const Header&h, const Vector1D& v) : 
        TessellationEvent(h), m_innerTessellation(v)
    {
    }
    
    SetInnerTessellation¹Event::SetInnerTessellation¹Event(const SetInnerTessellation¹Event& cp, const Header&h) : 
        TessellationEvent(cp, h), m_innerTessellation(cp.m_innerTessellation)
    {
    }

    SetInnerTessellation¹Event::~SetInnerTessellation¹Event()
    {
    }

    PostCPtr    SetInnerTessellation¹Event::clone(rebind_k, const Header&h) const 
    {
        return new SetInnerTessellation¹Event(*this, h);
    }
    
    void SetInnerTessellation¹Event::init_meta()
    {
        auto w = writer<SetInnerTessellation¹Event>();
        w.description("Set Tessellation Event");
        w.property("inner_tessellation", &SetInnerTessellation¹Event::m_innerTessellation).tag({kTag_Save, kTag_Log});
    }
}
