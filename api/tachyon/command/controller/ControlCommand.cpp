////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/controller/ControlCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControlCommand)

namespace yq::tachyon {

    ControlCommand::ControlCommand(const Header&h, TypedID t) : 
        ControllerCommand(h), m_tachyon(t)
    {
    }
    
    ControlCommand::ControlCommand(const ControlCommand& cp, const Header&h) : 
        ControllerCommand(cp, h), m_tachyon(cp.m_tachyon)
    {
    }
    
    ControlCommand::~ControlCommand()
    {
    }

    PostCPtr    ControlCommand::clone(rebind_k, const Header&h) const
    {
        return new ControlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControlCommand::init_meta()
    {
        auto w = writer<ControlCommand>();
        w.description("Control Command");
    }
}
