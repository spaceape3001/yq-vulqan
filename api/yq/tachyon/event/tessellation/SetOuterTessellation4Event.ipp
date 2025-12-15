////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOuterTessellation4Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOuterTessellation⁴Event)

namespace yq::tachyon {
    SetOuterTessellation⁴Event::SetOuterTessellation⁴Event(const Header& h, const Vector4D& v) : 
        TessellationEvent(h), m_outerTessellation(v)
    {
    }
    
    SetOuterTessellation⁴Event::SetOuterTessellation⁴Event(const SetOuterTessellation⁴Event& cp, const Header& h) : 
        TessellationEvent(cp, h), m_outerTessellation(cp.m_outerTessellation)
    {
    }

    SetOuterTessellation⁴Event::~SetOuterTessellation⁴Event()
    {
    }
    
    PostCPtr    SetOuterTessellation⁴Event::clone(rebind_k, const Header&h) const 
    {
        return new SetOuterTessellation⁴Event(*this, h);
    }

    void SetOuterTessellation⁴Event::init_meta()
    {
        auto w = writer<SetOuterTessellation⁴Event>();
        w.description("Set Tessellation Event");
        w.property("outer_tessellation", &SetOuterTessellation⁴Event::m_outerTessellation).tag({kTag_Save, kTag_Log});
    }
}
