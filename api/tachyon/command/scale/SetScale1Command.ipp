////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/SetScale1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale¹Command)

namespace yq::tachyon {
    SetScale¹Command::SetScale¹Command(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }
    
    SetScale¹Command::SetScale¹Command(const SetScale¹Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }

    SetScale¹Command::~SetScale¹Command()
    {
    }
    
    PostCPtr    SetScale¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetScale¹Command(*this, h);
    }

    void SetScale¹Command::init_meta()
    {
        auto w = writer<SetScale¹Command>();
        w.description("Set Scale Command");
        w.property("x", &SetScale¹Command::x);
    }
}
