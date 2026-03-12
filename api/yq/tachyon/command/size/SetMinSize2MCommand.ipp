////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize²MCommand)

namespace yq::tachyon {
    SetMinSize²MCommand::SetMinSize²MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize²MCommand::SetMinSize²MCommand(const Header& h, const Size2M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize²MCommand::SetMinSize²MCommand(const SetMinSize²MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize²MCommand::~SetMinSize²MCommand()
    {
    }

    PostCPtr    SetMinSize²MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize²MCommand(*this, h);
    }
    
    void SetMinSize²MCommand::init_meta()
    {
        auto w = writer<SetMinSize²MCommand>();
        w.description("SetMin Size MCommand in 2D");
        w.property("x", &SetMinSize²MCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize²MCommand::y).tag(kTag_Log);
        w.property("size", &SetMinSize²MCommand::m_size).tag(kTag_Save);
    }
}
