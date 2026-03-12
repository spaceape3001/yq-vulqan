////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize⁴DCommand)

namespace yq::tachyon {
    SetSize⁴DCommand::SetSize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize⁴DCommand::SetSize⁴DCommand(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize⁴DCommand::SetSize⁴DCommand(const SetSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize⁴DCommand::~SetSize⁴DCommand()
    {
    }

    PostCPtr    SetSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize⁴DCommand(*this, h);
    }
    
    void SetSize⁴DCommand::init_meta()
    {
        auto w = writer<SetSize⁴DCommand>();
        w.description("Set Size DCommand in 4D");
        w.property("x", &SetSize⁴DCommand::x).tag(kTag_Log);
        w.property("y", &SetSize⁴DCommand::y).tag(kTag_Log);
        w.property("z", &SetSize⁴DCommand::z).tag(kTag_Log);
        w.property("w", &SetSize⁴DCommand::w).tag(kTag_Log);
        w.property("size", &SetSize⁴DCommand::m_size).tag(kTag_Save);
    }
}
