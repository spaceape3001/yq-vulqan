////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize⁴CMCommand)

namespace yq::tachyon {
    SetSize⁴CMCommand::SetSize⁴CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize⁴CMCommand::SetSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize⁴CMCommand::SetSize⁴CMCommand(const SetSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize⁴CMCommand::~SetSize⁴CMCommand()
    {
    }

    PostCPtr    SetSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize⁴CMCommand(*this, h);
    }
    
    void SetSize⁴CMCommand::init_meta()
    {
        auto w = writer<SetSize⁴CMCommand>();
        w.description("Set Size CMCommand in 4D");
        w.property("x", &SetSize⁴CMCommand::x).tag(kTag_Log);
        w.property("y", &SetSize⁴CMCommand::y).tag(kTag_Log);
        w.property("z", &SetSize⁴CMCommand::z).tag(kTag_Log);
        w.property("w", &SetSize⁴CMCommand::w).tag(kTag_Log);
        w.property("size", &SetSize⁴CMCommand::m_size).tag(kTag_Save);
    }
}
