////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize⁴CMCommand)

namespace yq::tachyon {
    SetMaxSize⁴CMCommand::SetMaxSize⁴CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize⁴CMCommand::SetMaxSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize⁴CMCommand::SetMaxSize⁴CMCommand(const SetMaxSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize⁴CMCommand::~SetMaxSize⁴CMCommand()
    {
    }

    PostCPtr    SetMaxSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize⁴CMCommand(*this, h);
    }
    
    void SetMaxSize⁴CMCommand::init_meta()
    {
        auto w = writer<SetMaxSize⁴CMCommand>();
        w.description("SetMax Size CMCommand in 4D");
        w.property("x", &SetMaxSize⁴CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize⁴CMCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize⁴CMCommand::z).tag(kTag_Log);
        w.property("w", &SetMaxSize⁴CMCommand::w).tag(kTag_Log);
        w.property("size", &SetMaxSize⁴CMCommand::m_size).tag(kTag_Save);
    }
}
