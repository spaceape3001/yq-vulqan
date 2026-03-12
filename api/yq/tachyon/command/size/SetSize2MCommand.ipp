////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²MCommand)

namespace yq::tachyon {
    SetSize²MCommand::SetSize²MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize²MCommand::SetSize²MCommand(const Header& h, const Size2M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize²MCommand::SetSize²MCommand(const SetSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize²MCommand::~SetSize²MCommand()
    {
    }

    PostCPtr    SetSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize²MCommand(*this, h);
    }
    
    void SetSize²MCommand::init_meta()
    {
        auto w = writer<SetSize²MCommand>();
        w.description("Set Size MCommand in 2D");
        w.property("x", &SetSize²MCommand::x).tag(kTag_Log);
        w.property("y", &SetSize²MCommand::y).tag(kTag_Log);
        w.property("size", &SetSize²MCommand::m_size).tag(kTag_Save);
    }
}
