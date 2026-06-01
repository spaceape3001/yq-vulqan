////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²CMCommand)

namespace yq::tachyon {
    SetSize²CMCommand::SetSize²CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize²CMCommand::SetSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize²CMCommand::SetSize²CMCommand(const SetSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize²CMCommand::~SetSize²CMCommand()
    {
    }

    PostCPtr    SetSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize²CMCommand(*this, h);
    }
    
    void SetSize²CMCommand::init_meta()
    {
        auto w = writer<SetSize²CMCommand>();
        w.description("Set Size CMCommand in 2D");
        w.property("x", &SetSize²CMCommand::x).tag(kTag_Log);
        w.property("y", &SetSize²CMCommand::y).tag(kTag_Log);
        w.property("size", &SetSize²CMCommand::m_size).tag(kTag_Save);
    }
}
