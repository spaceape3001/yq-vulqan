////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleˣDCommand)

namespace yq::tachyon {
    SetScaleˣDCommand::SetScaleˣDCommand(const Header&h, double x) : 
        ScaleCommand(h), m_x(x)
    {
    }

    SetScaleˣDCommand::SetScaleˣDCommand(const SetScaleˣDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetScaleˣDCommand::~SetScaleˣDCommand()
    {
    }
    
    PostCPtr    SetScaleˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleˣDCommand(*this, h);
    }

    void SetScaleˣDCommand::init_meta()
    {
        auto w = writer<SetScaleˣDCommand>();
        w.description("Set Scale Command");
        w.property("x", &SetScaleˣDCommand::x);
    }
}
