////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeˣDCommand)

namespace yq::tachyon {
    SetMinSizeˣDCommand::SetMinSizeˣDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeˣDCommand::SetMinSizeˣDCommand(const Header& h, double v) : 
        SizeCommand(h), m_x(v)
    {
    }

    SetMinSizeˣDCommand::SetMinSizeˣDCommand(const SetMinSizeˣDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetMinSizeˣDCommand::~SetMinSizeˣDCommand()
    {
    }

    PostCPtr    SetMinSizeˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeˣDCommand(*this, h);
    }
    
    void SetMinSizeˣDCommand::init_meta()
    {
        auto w = writer<SetMinSizeˣDCommand>();
        w.description("SetMin Size DCommand in X");
        w.property("x", &SetMinSizeˣDCommand::m_x).tag(kTag_Log).tag(kTag_Save);
    }
}
