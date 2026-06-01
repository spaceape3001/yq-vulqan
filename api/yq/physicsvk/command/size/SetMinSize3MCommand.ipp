////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³MCommand)

namespace yq::tachyon {
    SetMinSize³MCommand::SetMinSize³MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize³MCommand::SetMinSize³MCommand(const Header& h, const Size3M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize³MCommand::SetMinSize³MCommand(const SetMinSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³MCommand::~SetMinSize³MCommand()
    {
    }

    PostCPtr    SetMinSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³MCommand(*this, h);
    }
    
    void SetMinSize³MCommand::init_meta()
    {
        auto w = writer<SetMinSize³MCommand>();
        w.description("SetMin Size MCommand in 3D");
        w.property("x", &SetMinSize³MCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize³MCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize³MCommand::z).tag(kTag_Log);
        w.property("size", &SetMinSize³MCommand::m_size).tag(kTag_Save);
    }
}
