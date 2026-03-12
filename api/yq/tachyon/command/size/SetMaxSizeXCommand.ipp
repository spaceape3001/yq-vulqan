////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeˣDCommand)

namespace yq::tachyon {
    SetMaxSizeˣDCommand::SetMaxSizeˣDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeˣDCommand::SetMaxSizeˣDCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMaxSizeˣDCommand::SetMaxSizeˣDCommand(const SetMaxSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMaxSizeˣDCommand::~SetMaxSizeˣDCommand()
    {
    }

    PostCPtr    SetMaxSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeˣDCommand(*this, h);
    }
    
    void SetMaxSizeˣDCommand::init_meta()
    {
        auto w = writer<SetMaxSizeˣDCommand>();
        w.description("SetMax Size DCommand in X");
        w.property("x", &SetMaxSizeˣDCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
