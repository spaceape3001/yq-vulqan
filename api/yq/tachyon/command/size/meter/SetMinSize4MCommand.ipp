////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize⁴MCommand)

namespace yq::tachyon {
    SetMinSize⁴MCommand::SetMinSize⁴MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize⁴MCommand::SetMinSize⁴MCommand(const Header& h, const Size4M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize⁴MCommand::SetMinSize⁴MCommand(const SetMinSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize⁴MCommand::~SetMinSize⁴MCommand()
    {
    }

    PostCPtr    SetMinSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize⁴MCommand(*this, h);
    }
    
    void SetMinSize⁴MCommand::init_meta()
    {
        auto w = writer<SetMinSize⁴MCommand>();
        w.description("SetMin Size MCommand in 4D");
        w.property("x", &SetMinSize⁴MCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize⁴MCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize⁴MCommand::z).tag(kTag_Log);
        w.property("w", &SetMinSize⁴MCommand::w).tag(kTag_Log);
        w.property("size", &SetMinSize⁴MCommand::m_size).tag(kTag_Save);
    }
}
