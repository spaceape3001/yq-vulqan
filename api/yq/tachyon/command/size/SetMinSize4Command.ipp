////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize⁴DCommand)

namespace yq::tachyon {
    SetMinSize⁴DCommand::SetMinSize⁴DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize⁴DCommand::SetMinSize⁴DCommand(const Header& h, const Size4D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize⁴DCommand::SetMinSize⁴DCommand(const SetMinSize⁴DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize⁴DCommand::~SetMinSize⁴DCommand()
    {
    }

    PostCPtr    SetMinSize⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize⁴DCommand(*this, h);
    }
    
    void SetMinSize⁴DCommand::init_meta()
    {
        auto w = writer<SetMinSize⁴DCommand>();
        w.description("SetMin Size DCommand in 4D");
        w.property("x", &SetMinSize⁴DCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize⁴DCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize⁴DCommand::z).tag(kTag_Log);
        w.property("w", &SetMinSize⁴DCommand::w).tag(kTag_Log);
        w.property("size", &SetMinSize⁴DCommand::m_size).tag(kTag_Save);
    }
}
