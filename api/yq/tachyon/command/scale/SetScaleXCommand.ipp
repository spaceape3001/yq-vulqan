////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleXCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleˣCommand)

namespace yq::tachyon {
    SetScaleˣCommand::SetScaleˣCommand(const Header&h, double x) : 
        ScaleCommand(h), m_x(x)
    {
    }

    SetScaleˣCommand::SetScaleˣCommand(const SetScaleˣCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetScaleˣCommand::~SetScaleˣCommand()
    {
    }
    
    PostCPtr    SetScaleˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleˣCommand(*this, h);
    }

    void SetScaleˣCommand::init_meta()
    {
        auto w = writer<SetScaleˣCommand>();
        w.description("Set Scale Command");
        w.property("x", &SetScaleˣCommand::x);
    }
}
