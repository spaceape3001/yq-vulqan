////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/SetScaleYCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleʸCommand)

namespace yq::tachyon {
    SetScaleʸCommand::SetScaleʸCommand(const Header& h, double y) : 
        ScaleCommand(h), m_y(y)
    {
    }
    
    SetScaleʸCommand::SetScaleʸCommand(const SetScaleʸCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_y(cp.m_y)
    {
    }

    SetScaleʸCommand::~SetScaleʸCommand()
    {
    }

    PostCPtr    SetScaleʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleʸCommand(*this, h);
    }
    
    void SetScaleʸCommand::init_meta()
    {
        auto w = writer<SetScaleʸCommand>();
        w.description("Set Scale Command");
        w.property("y", &SetScaleʸCommand::y);
    }
}
