////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/scale/SetScale2Command.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale²Command)

namespace yq::tachyon {
    SetScale²Command::SetScale²Command(const Header& h, const Vector2D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale²Command::SetScale²Command(const SetScale²Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale²Command::~SetScale²Command()
    {
    }

    PostCPtr    SetScale²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetScale²Command(*this, h);
    }
    
    void SetScale²Command::init_meta()
    {
        auto w = writer<SetScale²Command>();
        w.description("Set Scale Command");
        w.property("x", &SetScale²Command::x);
        w.property("y", &SetScale²Command::y);
    }
}
