////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4Command.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition⁴Command)

namespace yq::tachyon {
    SetPosition⁴Command::SetPosition⁴Command(const Header& h, const Vector4D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition⁴Command::SetPosition⁴Command(const SetPosition⁴Command& cp, const Header& h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition⁴Command::~SetPosition⁴Command()
    {
    }
    
    PostCPtr    SetPosition⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition⁴Command(*this, h);
    }

    void SetPosition⁴Command::init_meta()
    {
        auto w = writer<SetPosition⁴Command>();
        w.description("Set Position Command");
        w.property("w", &SetPosition⁴Command::w).tag(kTag_Log);
        w.property("x", &SetPosition⁴Command::x).tag(kTag_Log);
        w.property("y", &SetPosition⁴Command::y).tag(kTag_Log);
        w.property("z", &SetPosition⁴Command::z).tag(kTag_Log);
        w.property("position", &SetPosition⁴Command::m_position).tag(kTag_Save);
    }
}
