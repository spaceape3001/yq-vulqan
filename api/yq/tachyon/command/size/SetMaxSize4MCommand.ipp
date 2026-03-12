////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize4MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize⁴MCommand)

namespace yq::tachyon {
    SetMaxSize⁴MCommand::SetMaxSize⁴MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize⁴MCommand::SetMaxSize⁴MCommand(const Header& h, const Size4M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize⁴MCommand::SetMaxSize⁴MCommand(const SetMaxSize⁴MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize⁴MCommand::~SetMaxSize⁴MCommand()
    {
    }

    PostCPtr    SetMaxSize⁴MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize⁴MCommand(*this, h);
    }
    
    void SetMaxSize⁴MCommand::init_meta()
    {
        auto w = writer<SetMaxSize⁴MCommand>();
        w.description("SetMax Size MCommand in 4D");
        w.property("x", &SetMaxSize⁴MCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize⁴MCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize⁴MCommand::z).tag(kTag_Log);
        w.property("w", &SetMaxSize⁴MCommand::w).tag(kTag_Log);
        w.property("size", &SetMaxSize⁴MCommand::m_size).tag(kTag_Save);
    }
}
