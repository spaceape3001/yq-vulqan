////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOuterTessellation3Event.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOuterTessellation³Event)

namespace yq::tachyon {
    SetOuterTessellation³Event::SetOuterTessellation³Event(const Header& h, const Vector3D& v) : 
        TessellationEvent(h), m_outerTessellation(v)
    {
    }
    
    SetOuterTessellation³Event::SetOuterTessellation³Event(const SetOuterTessellation³Event& cp, const Header& h) : 
        TessellationEvent(cp, h), m_outerTessellation(cp.m_outerTessellation)
    {
    }

    SetOuterTessellation³Event::~SetOuterTessellation³Event()
    {
    }
    
    PostCPtr    SetOuterTessellation³Event::clone(rebind_k, const Header&h) const 
    {
        return new SetOuterTessellation³Event(*this, h);
    }

    void SetOuterTessellation³Event::init_meta()
    {
        auto w = writer<SetOuterTessellation³Event>();
        w.description("Set Tessellation Event");
        w.property("outer_tessellation", &SetOuterTessellation³Event::m_outerTessellation).tag({kTag_Save, kTag_Log});
    }
}
