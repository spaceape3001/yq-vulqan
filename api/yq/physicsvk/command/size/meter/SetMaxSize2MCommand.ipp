////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize²MCommand)

namespace yq::tachyon {
    SetMaxSize²MCommand::SetMaxSize²MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize²MCommand::SetMaxSize²MCommand(const Header& h, const Size2M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize²MCommand::SetMaxSize²MCommand(const SetMaxSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize²MCommand::~SetMaxSize²MCommand()
    {
    }

    PostCPtr    SetMaxSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize²MCommand(*this, h);
    }
    
    void SetMaxSize²MCommand::init_meta()
    {
        auto w = writer<SetMaxSize²MCommand>();
        w.description("SetMax Size MCommand in 2D");
        w.property("x", &SetMaxSize²MCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize²MCommand::y).tag(kTag_Log);
        w.property("size", &SetMaxSize²MCommand::m_size).tag(kTag_Save);
    }
}
