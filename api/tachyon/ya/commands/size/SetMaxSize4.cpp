////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/size/SetMaxSize4.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize⁴)

namespace yq::tachyon {
    SetMaxSize⁴::SetMaxSize⁴(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize⁴::SetMaxSize⁴(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize⁴::SetMaxSize⁴(const SetMaxSize⁴& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize⁴::~SetMaxSize⁴()
    {
    }

    PostCPtr    SetMaxSize⁴::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize⁴(*this, h);
    }
    
    void SetMaxSize⁴::init_info()
    {
        auto w = writer<SetMaxSize⁴>();
        w.description("SetMax Size Command in 4D");
        w.property("x", &SetMaxSize⁴::x).tag(kTag_Log);
        w.property("y", &SetMaxSize⁴::y).tag(kTag_Log);
        w.property("z", &SetMaxSize⁴::z).tag(kTag_Log);
        w.property("w", &SetMaxSize⁴::w).tag(kTag_Log);
        w.property("size", &SetMaxSize⁴::m_size).tag(kTag_Save);
    }
}
