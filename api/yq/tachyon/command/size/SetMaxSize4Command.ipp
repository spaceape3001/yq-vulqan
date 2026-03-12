////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize⁴DCommand)

namespace yq::tachyon {
    SetMaxSize⁴DCommand::SetMaxSize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize⁴DCommand::SetMaxSize⁴DCommand(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize⁴DCommand::SetMaxSize⁴DCommand(const SetMaxSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize⁴DCommand::~SetMaxSize⁴DCommand()
    {
    }

    PostCPtr    SetMaxSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize⁴DCommand(*this, h);
    }
    
    void SetMaxSize⁴DCommand::init_meta()
    {
        auto w = writer<SetMaxSize⁴DCommand>();
        w.description("SetMax Size DCommand in 4D");
        w.property("x", &SetMaxSize⁴DCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize⁴DCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize⁴DCommand::z).tag(kTag_Log);
        w.property("w", &SetMaxSize⁴DCommand::w).tag(kTag_Log);
        w.property("size", &SetMaxSize⁴DCommand::m_size).tag(kTag_Save);
    }
}
