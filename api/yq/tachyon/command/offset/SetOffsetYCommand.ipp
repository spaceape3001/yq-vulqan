////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetOffsetYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetOffsetʸCommand)

namespace yq::tachyon {
    SetOffsetʸCommand::SetOffsetʸCommand(const Header&h, double y) : 
        OffsetCommand(h), m_y(y)
    {
    }

    SetOffsetʸCommand::SetOffsetʸCommand(const SetOffsetʸCommand& cp, const Header&h) : 
        OffsetCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetOffsetʸCommand::~SetOffsetʸCommand()
    {
    }
    
    PostCPtr    SetOffsetʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetOffsetʸCommand(*this, h);
    }

    void SetOffsetʸCommand::init_meta()
    {
        auto w = writer<SetOffsetʸCommand>();
        w.description("Set Offset Command");
        w.property("y", &SetOffsetʸCommand::y);
    }
}
