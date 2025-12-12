////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffsetXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffsetˣCommand)

namespace yq::tachyon {
    SetOffsetˣCommand::SetOffsetˣCommand(const Header&h, double x) : 
        OffsetCommand(h), m_x(x)
    {
    }
    
    SetOffsetˣCommand::SetOffsetˣCommand(const SetOffsetˣCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetOffsetˣCommand::~SetOffsetˣCommand()
    {
    }

    PostCPtr    SetOffsetˣCommand::clone(rebind_k, const Header& h) const
    {
        return new SetOffsetˣCommand(*this, h);
    }
    
    void SetOffsetˣCommand::init_meta()
    {
        auto w = writer<SetOffsetˣCommand>();
        w.description("Set Offset Command");
        w.property("x", &SetOffsetˣCommand::x);
    }
}
