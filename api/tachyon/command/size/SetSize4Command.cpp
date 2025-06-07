////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSize4Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize⁴Command)

namespace yq::tachyon {
    SetSize⁴Command::SetSize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize⁴Command::SetSize⁴Command(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize⁴Command::SetSize⁴Command(const SetSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize⁴Command::~SetSize⁴Command()
    {
    }

    PostCPtr    SetSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetSize⁴Command(*this, h);
    }
    
    void SetSize⁴Command::init_info()
    {
        auto w = writer<SetSize⁴Command>();
        w.description("Set Size Command in 4D");
        w.property("x", &SetSize⁴Command::x).tag(kTag_Log);
        w.property("y", &SetSize⁴Command::y).tag(kTag_Log);
        w.property("z", &SetSize⁴Command::z).tag(kTag_Log);
        w.property("w", &SetSize⁴Command::w).tag(kTag_Log);
        w.property("size", &SetSize⁴Command::m_size).tag(kTag_Save);
    }
}
