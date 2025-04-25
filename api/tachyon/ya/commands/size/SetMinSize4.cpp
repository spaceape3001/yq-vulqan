////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetMinSize4.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize⁴)

namespace yq::tachyon {
    SetMinSize⁴::SetMinSize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize⁴::SetMinSize⁴(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize⁴::SetMinSize⁴(const SetMinSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize⁴::~SetMinSize⁴()
    {
    }

    PostCPtr    SetMinSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize⁴(*this, h);
    }
    
    void SetMinSize⁴::init_info()
    {
        auto w = writer<SetMinSize⁴>();
        w.description("SetMin Size Command in 4D");
        w.property("x", &SetMinSize⁴::x).tag(kTag_Log);
        w.property("y", &SetMinSize⁴::y).tag(kTag_Log);
        w.property("z", &SetMinSize⁴::z).tag(kTag_Log);
        w.property("w", &SetMinSize⁴::w).tag(kTag_Log);
        w.property("size", &SetMinSize⁴::m_size).tag(kTag_Save);
    }
}
