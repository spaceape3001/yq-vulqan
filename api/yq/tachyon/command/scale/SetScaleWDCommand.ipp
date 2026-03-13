////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleʷDCommand)

namespace yq::tachyon {
    SetScaleʷDCommand::SetScaleʷDCommand(const Header&h, double z) : 
        ScaleCommand(h), m_w(z)
    {
    }
    
    SetScaleʷDCommand::SetScaleʷDCommand(const SetScaleʷDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_w(cp.m_w)
    {
    }

    SetScaleʷDCommand::~SetScaleʷDCommand()
    {
    }

    PostCPtr    SetScaleʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleʷDCommand(*this, h);
    }
    
    void SetScaleʷDCommand::init_meta()
    {
        auto w = writer<SetScaleʷDCommand>();
        w.description("Set Scale Command");
        w.property("w", &SetScaleʷDCommand::w);
    }
}
