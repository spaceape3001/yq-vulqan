////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale²DCommand)

namespace yq::tachyon {
    SetScale²DCommand::SetScale²DCommand(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale²DCommand::SetScale²DCommand(const SetScale²DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale²DCommand::~SetScale²DCommand()
    {
    }

    PostCPtr    SetScale²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScale²DCommand(*this, h);
    }
    
    void SetScale²DCommand::init_meta()
    {
        auto w = writer<SetScale²DCommand>();
        w.description("Set Scale Command");
        w.property("x", &SetScale²DCommand::x);
        w.property("y", &SetScale²DCommand::y);
    }
}
