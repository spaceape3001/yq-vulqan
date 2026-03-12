////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeˣDCommand)

namespace yq::tachyon {
    SetSizeˣDCommand::SetSizeˣDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeˣDCommand::SetSizeˣDCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetSizeˣDCommand::SetSizeˣDCommand(const SetSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetSizeˣDCommand::~SetSizeˣDCommand()
    {
    }

    PostCPtr    SetSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeˣDCommand(*this, h);
    }
    
    void SetSizeˣDCommand::init_meta()
    {
        auto w = writer<SetSizeˣDCommand>();
        w.description("Set Size DCommand in X");
        w.property("x", &SetSizeˣDCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
