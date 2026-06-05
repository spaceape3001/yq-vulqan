////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize²CMCommand)

namespace yq::tachyon {
    SetMinSize²CMCommand::SetMinSize²CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize²CMCommand::SetMinSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize²CMCommand::SetMinSize²CMCommand(const SetMinSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize²CMCommand::~SetMinSize²CMCommand()
    {
    }

    PostCPtr    SetMinSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize²CMCommand(*this, h);
    }
    
    void SetMinSize²CMCommand::init_meta()
    {
        auto w = writer<SetMinSize²CMCommand>();
        w.description("SetMin Size CMCommand in 2D");
        w.property("x", &SetMinSize²CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize²CMCommand::y).tag(kTag_Log);
        w.property("size", &SetMinSize²CMCommand::m_size).tag(kTag_Save);
    }
}
