////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize⁴Command)

namespace yq::tachyon {
    SetMaxSize⁴Command::SetMaxSize⁴Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize⁴Command::SetMaxSize⁴Command(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize⁴Command::SetMaxSize⁴Command(const SetMaxSize⁴Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize⁴Command::~SetMaxSize⁴Command()
    {
    }

    PostCPtr    SetMaxSize⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize⁴Command(*this, h);
    }
    
    void SetMaxSize⁴Command::init_meta()
    {
        auto w = writer<SetMaxSize⁴Command>();
        w.description("SetMax Size Command in 4D");
        w.property("x", &SetMaxSize⁴Command::x).tag(kTag_Log);
        w.property("y", &SetMaxSize⁴Command::y).tag(kTag_Log);
        w.property("z", &SetMaxSize⁴Command::z).tag(kTag_Log);
        w.property("w", &SetMaxSize⁴Command::w).tag(kTag_Log);
        w.property("size", &SetMaxSize⁴Command::m_size).tag(kTag_Save);
    }
}
