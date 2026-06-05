////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize²CMCommand)

namespace yq::tachyon {
    SetMaxSize²CMCommand::SetMaxSize²CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize²CMCommand::SetMaxSize²CMCommand(const Header& h, const Size2CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize²CMCommand::SetMaxSize²CMCommand(const SetMaxSize²CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize²CMCommand::~SetMaxSize²CMCommand()
    {
    }

    PostCPtr    SetMaxSize²CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize²CMCommand(*this, h);
    }
    
    void SetMaxSize²CMCommand::init_meta()
    {
        auto w = writer<SetMaxSize²CMCommand>();
        w.description("SetMax Size CMCommand in 2D");
        w.property("x", &SetMaxSize²CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize²CMCommand::y).tag(kTag_Log);
        w.property("size", &SetMaxSize²CMCommand::m_size).tag(kTag_Save);
    }
}
