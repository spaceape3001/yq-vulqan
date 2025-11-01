////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeˣCommand)

namespace yq::tachyon {
    SetMaxSizeˣCommand::SetMaxSizeˣCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeˣCommand::SetMaxSizeˣCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMaxSizeˣCommand::SetMaxSizeˣCommand(const SetMaxSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMaxSizeˣCommand::~SetMaxSizeˣCommand()
    {
    }

    PostCPtr    SetMaxSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeˣCommand(*this, h);
    }
    
    void SetMaxSizeˣCommand::init_meta()
    {
        auto w = writer<SetMaxSizeˣCommand>();
        w.description("SetMax Size Command in X");
        w.property("x", &SetMaxSizeˣCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
