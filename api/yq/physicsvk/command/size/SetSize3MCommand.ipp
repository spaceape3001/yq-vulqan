////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³MCommand)

namespace yq::tachyon {
    SetSize³MCommand::SetSize³MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize³MCommand::SetSize³MCommand(const Header& h, const Size3M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize³MCommand::SetSize³MCommand(const SetSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³MCommand::~SetSize³MCommand()
    {
    }

    PostCPtr    SetSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³MCommand(*this, h);
    }
    
    void SetSize³MCommand::init_meta()
    {
        auto w = writer<SetSize³MCommand>();
        w.description("Set Size MCommand in 3D");
        w.property("x", &SetSize³MCommand::x).tag(kTag_Log);
        w.property("y", &SetSize³MCommand::y).tag(kTag_Log);
        w.property("z", &SetSize³MCommand::z).tag(kTag_Log);
        w.property("size", &SetSize³MCommand::m_size).tag(kTag_Save);
    }
}
