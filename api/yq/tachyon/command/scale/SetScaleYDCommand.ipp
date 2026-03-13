////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleʸDCommand)

namespace yq::tachyon {
    SetScaleʸDCommand::SetScaleʸDCommand(const Header& h, double y) : 
        ScaleCommand(h), m_y(y)
    {
    }
    
    SetScaleʸDCommand::SetScaleʸDCommand(const SetScaleʸDCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_y(cp.m_y)
    {
    }

    SetScaleʸDCommand::~SetScaleʸDCommand()
    {
    }

    PostCPtr    SetScaleʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleʸDCommand(*this, h);
    }
    
    void SetScaleʸDCommand::init_meta()
    {
        auto w = writer<SetScaleʸDCommand>();
        w.description("Set Scale Command");
        w.property("y", &SetScaleʸDCommand::y);
    }
}
