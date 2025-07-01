////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeXCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣCommand)

namespace yq::tachyon {
    SetMinSizeˣCommand::SetMinSizeˣCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeˣCommand::SetMinSizeˣCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMinSizeˣCommand::SetMinSizeˣCommand(const SetMinSizeˣCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMinSizeˣCommand::~SetMinSizeˣCommand()
    {
    }

    PostCPtr    SetMinSizeˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeˣCommand(*this, h);
    }
    
    void SetMinSizeˣCommand::init_meta()
    {
        auto w = writer<SetMinSizeˣCommand>();
        w.description("SetMin Size Command in X");
        w.property("x", &SetMinSizeˣCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
