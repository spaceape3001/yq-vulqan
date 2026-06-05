////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize4CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize⁴CMCommand)

namespace yq::tachyon {
    SetMinSize⁴CMCommand::SetMinSize⁴CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize⁴CMCommand::SetMinSize⁴CMCommand(const Header& h, const Size4CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize⁴CMCommand::SetMinSize⁴CMCommand(const SetMinSize⁴CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize⁴CMCommand::~SetMinSize⁴CMCommand()
    {
    }

    PostCPtr    SetMinSize⁴CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize⁴CMCommand(*this, h);
    }
    
    void SetMinSize⁴CMCommand::init_meta()
    {
        auto w = writer<SetMinSize⁴CMCommand>();
        w.description("SetMin Size CMCommand in 4D");
        w.property("x", &SetMinSize⁴CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize⁴CMCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize⁴CMCommand::z).tag(kTag_Log);
        w.property("w", &SetMinSize⁴CMCommand::w).tag(kTag_Log);
        w.property("size", &SetMinSize⁴CMCommand::m_size).tag(kTag_Save);
    }
}
