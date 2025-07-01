////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSize4Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize⁴Command)

namespace yq::tachyon {
    SetMinSize⁴Command::SetMinSize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize⁴Command::SetMinSize⁴Command(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize⁴Command::SetMinSize⁴Command(const SetMinSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize⁴Command::~SetMinSize⁴Command()
    {
    }

    PostCPtr    SetMinSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize⁴Command(*this, h);
    }
    
    void SetMinSize⁴Command::init_info()
    {
        auto w = writer<SetMinSize⁴Command>();
        w.description("SetMin Size Command in 4D");
        w.property("x", &SetMinSize⁴Command::x).tag(kTag_Log);
        w.property("y", &SetMinSize⁴Command::y).tag(kTag_Log);
        w.property("z", &SetMinSize⁴Command::z).tag(kTag_Log);
        w.property("w", &SetMinSize⁴Command::w).tag(kTag_Log);
        w.property("size", &SetMinSize⁴Command::m_size).tag(kTag_Save);
    }
}
