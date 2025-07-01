////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeˣCommand)

namespace yq::tachyon {
    SetSizeˣCommand::SetSizeˣCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeˣCommand::SetSizeˣCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetSizeˣCommand::SetSizeˣCommand(const SetSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetSizeˣCommand::~SetSizeˣCommand()
    {
    }

    PostCPtr    SetSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeˣCommand(*this, h);
    }
    
    void SetSizeˣCommand::init_info()
    {
        auto w = writer<SetSizeˣCommand>();
        w.description("Set Size Command in X");
        w.property("x", &SetSizeˣCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
