////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize⁴MCommand)

namespace yq::tachyon {
    SetSize⁴MCommand::SetSize⁴MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize⁴MCommand::SetSize⁴MCommand(const Header& h, const Size4M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize⁴MCommand::SetSize⁴MCommand(const SetSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize⁴MCommand::~SetSize⁴MCommand()
    {
    }

    PostCPtr    SetSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize⁴MCommand(*this, h);
    }
    
    void SetSize⁴MCommand::init_meta()
    {
        auto w = writer<SetSize⁴MCommand>();
        w.description("Set Size MCommand in 4D");
        w.property("x", &SetSize⁴MCommand::x).tag(kTag_Log);
        w.property("y", &SetSize⁴MCommand::y).tag(kTag_Log);
        w.property("z", &SetSize⁴MCommand::z).tag(kTag_Log);
        w.property("w", &SetSize⁴MCommand::w).tag(kTag_Log);
        w.property("size", &SetSize⁴MCommand::m_size).tag(kTag_Save);
    }
}
