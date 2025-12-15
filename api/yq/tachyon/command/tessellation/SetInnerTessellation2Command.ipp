////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetInnerTessellation2Command.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetInnerTessellation²Command)

namespace yq::tachyon {
    SetInnerTessellation²Command::SetInnerTessellation²Command(const Header& h, const Vector2D& v) : 
        TessellationCommand(h), m_innerTessellation(v)
    {
    }

    SetInnerTessellation²Command::SetInnerTessellation²Command(const SetInnerTessellation²Command& cp, const Header& h) : 
        TessellationCommand(cp, h), m_innerTessellation(cp.m_innerTessellation)
    {
    }
    
    SetInnerTessellation²Command::~SetInnerTessellation²Command()
    {
    }

    PostCPtr    SetInnerTessellation²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetInnerTessellation²Command(*this, h);
    }
    
    void SetInnerTessellation²Command::init_meta()
    {
        auto w = writer<SetInnerTessellation²Command>();
        w.description("Set Tessellation Command");
        w.property("inner_tessellation", &SetInnerTessellation²Command::m_innerTessellation).tag({kTag_Save, kTag_Log});
    }
}
