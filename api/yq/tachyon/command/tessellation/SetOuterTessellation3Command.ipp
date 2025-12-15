////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOuterTessellation3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOuterTessellation³Command)

namespace yq::tachyon {
    SetOuterTessellation³Command::SetOuterTessellation³Command(const Header& h, const Vector3D& v) : 
        TessellationCommand(h), m_outerTessellation(v)
    {
    }
    
    SetOuterTessellation³Command::SetOuterTessellation³Command(const SetOuterTessellation³Command& cp, const Header& h) : 
        TessellationCommand(cp, h), m_outerTessellation(cp.m_outerTessellation)
    {
    }

    SetOuterTessellation³Command::~SetOuterTessellation³Command()
    {
    }
    
    PostCPtr    SetOuterTessellation³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOuterTessellation³Command(*this, h);
    }

    void SetOuterTessellation³Command::init_meta()
    {
        auto w = writer<SetOuterTessellation³Command>();
        w.description("Set Tessellation Command");
        w.property("outer_tessellation", &SetOuterTessellation³Command::m_outerTessellation).tag({kTag_Save, kTag_Log});
    }
}
