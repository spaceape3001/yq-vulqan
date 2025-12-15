////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOuterTessellation4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOuterTessellation⁴Command)

namespace yq::tachyon {
    SetOuterTessellation⁴Command::SetOuterTessellation⁴Command(const Header& h, const Vector4D& v) : 
        TessellationCommand(h), m_outerTessellation(v)
    {
    }
    
    SetOuterTessellation⁴Command::SetOuterTessellation⁴Command(const SetOuterTessellation⁴Command& cp, const Header& h) : 
        TessellationCommand(cp, h), m_outerTessellation(cp.m_outerTessellation)
    {
    }

    SetOuterTessellation⁴Command::~SetOuterTessellation⁴Command()
    {
    }
    
    PostCPtr    SetOuterTessellation⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetOuterTessellation⁴Command(*this, h);
    }

    void SetOuterTessellation⁴Command::init_meta()
    {
        auto w = writer<SetOuterTessellation⁴Command>();
        w.description("Set Tessellation Command");
        w.property("outer_tessellation", &SetOuterTessellation⁴Command::m_outerTessellation).tag({kTag_Save, kTag_Log});
    }
}
