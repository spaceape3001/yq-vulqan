////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetInnerTessellation1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetInnerTessellation¹Command)

namespace yq::tachyon {
    SetInnerTessellation¹Command::SetInnerTessellation¹Command(const Header&h, const Vector1D& v) : 
        TessellationCommand(h), m_innerTessellation(v)
    {
    }
    
    SetInnerTessellation¹Command::SetInnerTessellation¹Command(const SetInnerTessellation¹Command& cp, const Header&h) : 
        TessellationCommand(cp, h), m_innerTessellation(cp.m_innerTessellation)
    {
    }

    SetInnerTessellation¹Command::~SetInnerTessellation¹Command()
    {
    }

    PostCPtr    SetInnerTessellation¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetInnerTessellation¹Command(*this, h);
    }
    
    void SetInnerTessellation¹Command::init_meta()
    {
        auto w = writer<SetInnerTessellation¹Command>();
        w.description("Set Tessellation Command");
        w.property("inner_tessellation", &SetInnerTessellation¹Command::m_innerTessellation).tag({kTag_Save, kTag_Log});
    }
}
