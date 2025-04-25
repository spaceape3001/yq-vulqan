////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize⁴)

namespace yq::tachyon {
    SetSize⁴::SetSize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize⁴::SetSize⁴(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize⁴::SetSize⁴(const SetSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize⁴::~SetSize⁴()
    {
    }

    PostCPtr    SetSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new SetSize⁴(*this, h);
    }
    
    void SetSize⁴::init_info()
    {
        auto w = writer<SetSize⁴>();
        w.description("Set Size Command in 4D");
        w.property("x", &SetSize⁴::x).tag(kTag_Log);
        w.property("y", &SetSize⁴::y).tag(kTag_Log);
        w.property("z", &SetSize⁴::z).tag(kTag_Log);
        w.property("w", &SetSize⁴::w).tag(kTag_Log);
        w.property("size", &SetSize⁴::m_size).tag(kTag_Save);
    }
}
